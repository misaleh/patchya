#include "std_wrapper.h"

#include "debugger_win32.h"

static 	void* imageBase = 0;


void ARCH_setSWBreakPoint(nodeBP* currNode)
{
	uint8 opcodeBP = 0 ;
	if(!ReadProcessMemory(currNode->procInfo.pi.hProcess, currNode->addressBreakPoint, &opcodeBP, sizeof(opcodeBP), NULL))
	{
	}
	currNode->oldOPcode = opcodeBP;
	opcodeBP = SW_BP_OP;
	if(!WriteProcessMemory(currNode->procInfo.pi.hProcess, currNode->addressBreakPoint,&opcodeBP, sizeof(opcodeBP), NULL))
	{
	}
	/*flush the cache*/
	FlushInstructionCache(currNode->procInfo.pi.hProcess,currNode->addressBreakPoint,sizeof(opcodeBP));	
	
}

void ARCH_setHWBreakPoint(void* _address,ARCH_PROCINFO _procInfo,uint8 BPNum)
{
	CONTEXT lcContext;
	lcContext.ContextFlags  = CONTEXT_DEBUG_REGISTERS;
	GetThreadContext(_procInfo.pi.hThread, &lcContext);
	
	switch(BPNum)
	{
		case 0:
			lcContext.Dr0 = (int64)_address;
			break;
		case 1:
			lcContext.Dr1 = (int64)_address;
			break;
		case 2:
			lcContext.Dr2 = (int64)_address;
			break;
		case 3:
			lcContext.Dr3 = (int64)_address;
			break;
		default:
		
			break;
	}
	/*enable correponding DR on local level*/
	lcContext.Dr7 |= (1<<BPNum); 
	/*enabel read-write breakpoint*/
	lcContext.Dr7 |= 0x030000 <<(BPNum*4);
	lcContext.Dr6 = 0;
	SetThreadContext(_procInfo.pi.hThread, &lcContext);

}
void ARCH_clearSWBreakPoint(nodeBP* currNode)
{
	CONTEXT lcContext;
	uint8 opcodeBP = 0;
	lcContext.ContextFlags = CONTEXT_ALL;
	GetThreadContext(currNode->procInfo.pi.hThread, &lcContext);
	lcContext.Rip --; 
	SetThreadContext(currNode->procInfo.pi.hThread, &lcContext);

	if(!WriteProcessMemory(currNode->procInfo.pi.hProcess, currNode->addressBreakPoint,&currNode->oldOPcode, sizeof(opcodeBP), NULL))
	{
	}
	if(!ReadProcessMemory(currNode->procInfo.pi.hProcess, currNode->addressBreakPoint, &opcodeBP, sizeof(opcodeBP), NULL))
	{
	}
	FlushInstructionCache(currNode->procInfo.pi.hProcess,currNode->addressBreakPoint, sizeof(opcodeBP));
}

void ARCH_clearHWBreakPoint(HANDLE _hthread,uint8 BPNum)
{
	CONTEXT lcContext;
	lcContext.ContextFlags  = CONTEXT_DEBUG_REGISTERS;
	GetThreadContext(_hthread, &lcContext);
	lcContext.Dr7 &= ~(1<<BPNum); 
	SetThreadContext(_hthread, &lcContext);
}

void* ARCH_getEndAddress(ARCH_PROCINFO _procInfo)
{
	LPVOID addressBase = imageBase + 0x3C; /*address of e_lfanew in DOS header*/
	void* buffImageBase = 0;
	uint32 sizeImageBase = 4;
	uint32 e_lfanew;
	if(!ARCH_READ_PROC_MEMORY(addressBase,_procInfo,&e_lfanew,sizeImageBase))
	{
	}
	/*offset to get sizeOfImage from optional header*/
	addressBase = imageBase + 0x18 + 0x38 +  e_lfanew ;
	if(!ARCH_READ_PROC_MEMORY(addressBase,_procInfo,&buffImageBase,sizeImageBase))
	{
	}
	#ifdef LOG_ENABLE
	LOG_WRITE( "Image end Address = :0x%p\n", (void*)((int64)imageBase + (int64)buffImageBase) ); 
	#endif
	return (void*)((int64)imageBase + (int64)buffImageBase);
}
void* ARCH_getStartAddress(ARCH_PROCINFO _procInfo)
{
	void* imageStartAddress =   imageBase + 0x1000;
	#ifdef LOG_ENABLE
	LOG_WRITE( "Image Start Address = :0x%p\n", imageStartAddress ); 
	#endif
	return imageStartAddress;
}

void* ARCH_getEXEBaseAddress(ARCH_PROCINFO _procInfo)
{
	HMODULE hNTDLL  = LoadLibrary("ntdll");
	DWORD result = 0;
	PEB procPEB;
	if(hNTDLL ==NULL )
	{
		#ifdef LOG_ENABLE
		LOG_WRITE( "Couldn't find ntdll Error:%ld\n", GetLastError() ); 
		#endif
	}
	FARPROC fpNtQueryInformationProcess = GetProcAddress(hNTDLL,"NtQueryInformationProcess");
	if(fpNtQueryInformationProcess == NULL)
	{
		#ifdef LOG_ENABLE
		LOG_WRITE( "Couldn't find NtQueryInformationProcess\n" ); 
		#endif
	}
	
	PROCESS_BASIC_INFORMATION pbi;
	fpNtQueryInformationProcess(_procInfo.pi.hProcess,0,&pbi,sizeof(PROCESS_BASIC_INFORMATION),result);
	#ifdef LOG_ENABLE
	LOG_WRITE( "PEB base Address = 0x%p\n",pbi.PebBaseAddress ); 
	#endif
	if(!ReadProcessMemory(_procInfo.pi.hProcess,pbi.PebBaseAddress,&procPEB,sizeof(PEB),NULL))
	{
		#ifdef LOG_ENABLE
		LOG_WRITE("can't read PEB %ld\n",GetLastError());
		#endif
	}
	else
	{
		imageBase = procPEB.Reserved3[1];
	}
	
	#ifdef LOG_ENABLE
	LOG_WRITE("Image Base =  0x%p\n",imageBase);
	#endif

	return  imageBase;
}

void* ARCH_convertRA(void* RVA)
{
	return (void*)((int64)RVA + (int64)imageBase);
}