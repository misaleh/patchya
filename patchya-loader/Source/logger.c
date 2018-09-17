#include "config.h"
#include "std_wrapper.h"
#include "logger.h"

static char * logFileName;
static ARCH_FILE * FilePointer;
void loggerInit(char* fileName)
{
	
	logFileName =ARCH_MALLOC(ARCH_STRLEN(fileName) + ARCH_STRLEN(LOG_EXTENSION)+1);
	ARCH_STRCPY(logFileName,fileName);
	ARCH_STRCAT(logFileName,LOG_EXTENSION);
	FilePointer  = ARCH_FCREATE(logFileName);
}
void logConfig(projectConfig * myprojectConfig)
{
	int i = 0,k=0;
	ARCH_FWRITE(FilePointer,"configuration flag =0x%X \n",myprojectConfig->configType); 
	ARCH_FWRITE(FilePointer,"victim file = %s \n",myprojectConfig->inFile); 
	ARCH_FWRITE(FilePointer,"Gate Condition =0x%X\n",myprojectConfig->gateCondition); 
	ARCH_FWRITE(FilePointer,"timeout =%d\n",myprojectConfig->timeout); 
	ARCH_FWRITE(FilePointer,"mem Address   =%x\n",myprojectConfig->memAdd ); 
	ARCH_FWRITE(FilePointer,"mem Value    =%x\n",myprojectConfig->memVal  ); 
	ARCH_FWRITE(FilePointer,"pcVal    =%x\n",myprojectConfig->pcVal  ); 	
	ARCH_FWRITE(FilePointer,"numOffPatch   =%d\n",myprojectConfig->numOffPatch   ); 
	ARCH_FWRITE(FilePointer,"numofSNRpatch   =%d\n",myprojectConfig->numofSNRpatch  ); 
	for(i = 0 ; i  <  myprojectConfig->numOffPatch;i++)
	{
		ARCH_FWRITE(FilePointer,"off patch %d at address 0x%X\n",i,myprojectConfig->offPatchAdd[i]);
		
		for(k = 0 ; k < myprojectConfig->patternOFFSize[i]; k++)
		{
			ARCH_FWRITE(FilePointer,"0x%X -> 0x%X\n", myprojectConfig->patchDataOriginal[i*MAX_PATTERN_SIZE +k], myprojectConfig->patchData[i*MAX_PATTERN_SIZE +k]);
		}
		ARCH_FWRITE(FilePointer,"\n");
	}
	for(i = 0 ; i  <  myprojectConfig->numofSNRpatch;i++)
	{
		ARCH_FWRITE(FilePointer,"SNR patch %d\n",i);
		
		for(k = 0 ; k < myprojectConfig->patternSNRSize[i]; k++)
		{
			ARCH_FWRITE(FilePointer,"%c%c -> 0x%X\n",myprojectConfig->patternSearch[i*MAX_PATTERN_SIZE +2*k],myprojectConfig->patternSearch[i*MAX_PATTERN_SIZE +2*k+1],myprojectConfig->patternReplace[i*MAX_PATTERN_SIZE +k]);
		}
		ARCH_FWRITE(FilePointer,"\n");
	}
}

ARCH_FILE* getLogHandle(void)
{
	return FilePointer;
}

void loggerDeInit(void)
{
	ARCH_FCLOSE(FilePointer);
}