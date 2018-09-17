#include "config.h"
#include "std_wrapper.h"
#include "common_def.h"
#include "types.h"
#include "debugger.h"
#include "search_alg.h"
#include "bin_funcs.h"
#include "logger.h"


int main(int argc, char * argv[])
{
	/*process information used for debugging the process*/
	ARCH_PROCINFO myProcInfo = {0};
	/*break point handle*/
	BP_HANDLE handleSWBP = 0;
	BP_HANDLE handleHWBP = 0;
	/*address of break point*/
	void* addressBP = NULL;
	/*temproray buffer used to read data from process*/
	uint8 tempBuf[100] = {0};
	/*flag to indicate if gate condition met*/
	uint8 gateCondFlag = GATE_COND_NOTMET;
	/*loop variable*/
	uint32 i;
	/*read code from process*/
	uint8 codeBuffer[BLOCK_SIZE];
	/*code read from porcess but converted into ASCII*/
	uint8 codeBufferASCII[BLOCK_SIZE*2];
	/*the struct that holds the configuration*/
	projectConfig myprojectConfig = {0};
	/*start of search in SNR patch*/
	uint32 startSNR = 0;
	/*end of search in SNR patch*/
	uint32 endSNR = 0;
	
	
	#ifdef LOG_ENABLE
	/*initialize logging*/
	loggerInit(argv[0]);
	#endif
	/*initialize the struct with configuration data*/
	readConfiguration(&myprojectConfig);
	#ifdef LOG_ENABLE
	/*Write configuration to Log file for debugging*/
	logConfig(&myprojectConfig);
	#endif
	/*check the configuration flag, it indicates if the file is configure or not*/
	if(myprojectConfig.configType != CONFIG_FLAG)
	{
		#ifdef LOG_ENABLE
		LOG_WRITE("Error, it seems that the file is not configured properly\n");
		#endif
		return 0;
	}
	
	/*load and run the program*/
	if(!ARCH_CREATEPROC(myprojectConfig.inFile , myProcInfo))
	{ 
		#ifdef LOG_ENABLE
		LOG_WRITE( "Couldn't Start the exe! Error:%ld\n", GetLastError() ); 
		#endif
		return 0;
	}
	
	if(debuggerInit(myProcInfo) == ERROR_GENERAL)
	{
		#ifdef LOG_ENABLE
		LOG_WRITE( "Error in intializing debugger refer to previous error\n"); 
		#endif
	}

	#ifdef LOG_ENABLE
	LOG_WRITE( "Started gate condition\n" );
	#endif
	/*check the gate condition, if it is memory address*/
	if(myprojectConfig.gateCondition == PATCH_COND_MEM)
	{
		/* create a debugging object*/
		ARCH_CREATE_DEBUG_OBJECT(0);
		/*address of the breakpoint*/
		addressBP = ARCH_convertRA((void*)(myprojectConfig.memAdd)) ;
		while(1)
		{
			/*check new debugging events*/
			ARCH_CHECKDBGEVENTS(0);
			/*if it is the condition to add the breakpoint, as some archs, require certain condition to add HW breakpoint*/
			if(ARCH_ISCOND_SET_HWBP(0))
			{
				/*add the hardware breakpoint at the address of the gate condition*/
				handleHWBP = setHWBreakPoint(addressBP, myProcInfo);
				/*continue debugging*/
				ARCH_DBG_CONTINUE(0);
			}
			/*if a hw breakpoint hit*/
			else if(ARCH_ISHWBPHIT(0))
			{
				/*read the data in the address*/
				ARCH_READ_PROC_MEMORY(addressBP,myProcInfo,tempBuf,2);
				/*if match the config*/
				if(myprojectConfig.memVal == (*(unsigned short*)tempBuf))
				{
					#ifdef LOG_ENABLE
					LOG_WRITE("HW BP HIT!\n");
					#endif
					/*remove hardware breakpoint*/
					clearHWBreakPoint(handleHWBP);
					/*gate condition met, move to patching*/
					gateCondFlag = GATE_COND_MET;
					ARCH_SUSPEND_EXE(myProcInfo);
				}
				ARCH_DBG_CONTINUE(0);
			}
			else
			{
				/*if any other event, pass it to application*/
				ARCH_DBG_PASS(0);
			}

		if(gateCondFlag == GATE_COND_MET)
		{
			#ifdef LOG_ENABLE
			LOG_WRITE("Gate Condition Met\n");
			#endif
			ARCH_DBG_PASS(0);
			break;
		}
	   }
	}
	/* if gate condition is certain address*/
	else if(myprojectConfig.gateCondition == PATCH_COND_PC)
	{
		/*create a debugging object*/
		 ARCH_CREATE_DEBUG_OBJECT(0);
		 /*address of the breakpoint is the address of the required PC*/
		 addressBP = ARCH_convertRA((void*)(myprojectConfig.pcVal)) ;
		 /*add SW breakpoint at this address*/
		 handleSWBP = setSWBreakPoint(addressBP,myProcInfo);		 
		while(1)
		{
			ARCH_CHECKDBGEVENTS(0);
			/*if SW breakpoint hit*/
			if(ARCH_ISSWBPHIT(0))
			{
				/*check if it is the required breakpoint*/
				 if(ARCH_GET_SWBP_ADD(0) == addressBP)
				 {
					#ifdef LOG_ENABLE
					LOG_WRITE("SW BP Hit!\n");
					#endif
					 /*clear the breakpoint*/
					clearSWBreakPoint(handleSWBP);
					/*gate condition met, move to patching*/
					gateCondFlag = GATE_COND_MET;
					ARCH_SUSPEND_EXE(myProcInfo);
				 }
				ARCH_DBG_CONTINUE(0);
			}
			else
			{
				/*if any other event, pass it to application*/
				ARCH_DBG_PASS(0);
			}
			
		if(gateCondFlag == GATE_COND_MET)
		{
			#ifdef LOG_ENABLE
			LOG_WRITE("Gate Condition Met!\n");
			#endif
			ARCH_DBG_PASS(0);
			break;
		}
	   }
	}
	/*if timeout, wait for it*/
	else if(myprojectConfig.gateCondition == PATCH_COND_TOUT)
	{
		/*wait a certain amount of time*/
		ARCH_WAIT_MS(myprojectConfig.timeout);
		#ifdef LOG_ENABLE
		LOG_WRITE("Gate Condition Met!\n");
		#endif		
		ARCH_SUSPEND_EXE(myProcInfo);

	}
	
	
	#ifdef LOG_ENABLE
	LOG_WRITE("Patching Started\n");
	#endif
	/*patch the code*/
	while(myprojectConfig.numofSNRpatch > 0)
	{
		int32 searchResult;
		uint32 BlockReadSize;
		uint32 sizeSNR;
		/*loop counter*/
		int j = 0;
		myprojectConfig.numofSNRpatch--;
		/*get start and end address*/
		startSNR = getStartAddress(myProcInfo);
		endSNR = getEndAddress(myProcInfo);
		/*size of search area*/
		sizeSNR = (endSNR - startSNR);
		/*for all the seatch area*/
		for(i = 0 ;  i < sizeSNR ;i++)
		{
			/*if the remaining part is smaller than BLOCK_SIZE, then search for it ,otherwise search for block size which is configurable */
			BlockReadSize = ((sizeSNR-i)>=BLOCK_SIZE)?BLOCK_SIZE : sizeSNR-i; 
			/*read the memory of the process in  codeBuffer to search in*/
			if(!ARCH_READ_PROC_MEMORY(startSNR+i,myProcInfo,codeBuffer,BlockReadSize))
			{
				#ifdef LOG_ENABLE
				LOG_WRITE("Couldn't read process memory in SNR patch %d\n",j);
				#endif
			}
			/*Convert code to ascii to be able to search in it*/
			convertCodeASCII(codeBuffer,codeBufferASCII,BlockReadSize);
			/*do the search*/
			searchResult = searchWildCard(&myprojectConfig.patternSearch[j*MAX_PATTERN_SIZE],codeBufferASCII,2*myprojectConfig.patternSNRSize[j] ,2*BlockReadSize );
			if(searchResult == SEARCH_NOT_FOUND)
			{
				/*if not found, increamnt the counter to the next block*/
				i +=BlockReadSize;
			}
			else
			{
				/*if found make the counter points the found address*/
				i += searchResult;
				#ifdef LOG_ENABLE
				LOG_WRITE("FOUND at address 0x%x\n",startSNR+i);
				#endif
				/*patch the process memory*/
				if(!ARCH_WRITE_PROC_MEMORTY(startSNR+i,myProcInfo,&myprojectConfig.patternReplace[j*MAX_PATTERN_SIZE],myprojectConfig.patternSNRSize[j]))
				{
					#ifdef LOG_ENABLE
					LOG_WRITE("Couldn't write to process memory in SNR patch %d\n",j);
					#endif
				}
				ARCH_FLUSH_INST_CACHE(startSNR+i,myProcInfo,myprojectConfig.patternSNRSize[j]);
			}
		}
		j++;
	}
	while(myprojectConfig.numOffPatch > 0)
	{
		//for loop for all offsets
		int j = 0;
		myprojectConfig.numOffPatch--;
		addressBP = ARCH_convertRA((void*)myprojectConfig.offPatchAdd[j]) ;
		if(!ARCH_READ_PROC_MEMORY(addressBP,myProcInfo,tempBuf,myprojectConfig.patternOFFSize[j]))
		{
			#ifdef LOG_ENABLE
			LOG_WRITE("Couldn't read  process memory in offset patch = %d\n",j);
			#endif
		}
		if(ARCH_MEMCMP(tempBuf,&myprojectConfig.patchDataOriginal[j*MAX_PATTERN_SIZE],myprojectConfig.patternOFFSize[j]) != 0)
		{
			#ifdef LOG_ENABLE
			LOG_WRITE("Offset Patch value doesn't match with expected value\n");
			#endif
		}
		else
		{
			if(!ARCH_WRITE_PROC_MEMORTY(addressBP,myProcInfo,&myprojectConfig.patchData[j*MAX_PATTERN_SIZE],myprojectConfig.patternOFFSize[j]))
			{
				#ifdef LOG_ENABLE
				LOG_WRITE("Couldn't write to process memory in offset patch = %d\n",j);
				#endif
			}
			ARCH_FLUSH_INST_CACHE(addressBP,myProcInfo,myprojectConfig.patternOFFSize[j]);
		}
		j++;
	}
	#ifdef LOG_ENABLE
	LOG_WRITE("Patching Done\n");
	#endif
	ARCH_RESUME_EXE(myProcInfo);
	
	/*Continue running the exe */
	ARCH_RUN_TILL_END();
	loggerDeInit();
	
	return 0;
}