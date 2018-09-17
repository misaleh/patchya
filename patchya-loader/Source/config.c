#include  "config.h"
#include "std_wrapper.h"
#define CONFIG_SIZE   4096

static  uint8 configBuffer[CONFIG_SIZE] = {'T' ,'h' ,'i','s' ,'i','s','t','h','e', 's','t','a','r','t', 'o' ,'f', 'c' , 'o' , 'n',\
'f' ,'i' ,'g' ,'u' ,'r','a','t','i','o','n', 'b','u','f','f','e','r','!','\0'};	
void readConfiguration(projectConfig* _progConfig)
{
	//read buffer
	_progConfig->configType = configBuffer[CONFIG_FLAG_OFFSET];
	ARCH_MEMCPY( _progConfig->inFile,&configBuffer[CONFIG_INFILE_OFFSET],MAX_INFILE_SIZE);
	ARCH_MEMCPY(&_progConfig->gateCondition,&configBuffer[CONFIG_GATE_CONDITION_OFFSET],sizeof(_progConfig->gateCondition));
	ARCH_MEMCPY(&_progConfig->timeout  , &configBuffer[CONFIG_TIMEOUT_OFFSET],sizeof(_progConfig->timeout));
	ARCH_MEMCPY(&_progConfig->memAdd   ,&configBuffer[CONFIG_MEM_ADD_OFFSET],sizeof(_progConfig->memAdd ));
	ARCH_MEMCPY(&_progConfig->memVal   ,&configBuffer[CONFIG_MEM_VAL_OFFSET],sizeof(_progConfig->memVal));
	ARCH_MEMCPY(&_progConfig->pcVal    ,&configBuffer[CONFIG_MEM_PC_OFFSET],sizeof(_progConfig->pcVal));
	ARCH_MEMCPY(&_progConfig->numOffPatch, &configBuffer[CONFIG_NUM_OFF_OFFSET],sizeof(_progConfig->numOffPatch));
	ARCH_MEMCPY(&_progConfig->numofSNRpatch, &configBuffer[CONFIG_NUM_SNR_OFFSET],sizeof(_progConfig->numofSNRpatch));
	ARCH_MEMCPY(_progConfig->patternSearch,&configBuffer[CONFIG_PATT_SRCH_OFFSET],MAX_NUM_SNR*MAX_PATTERN_SIZE);
	ARCH_MEMCPY(_progConfig->patternReplace ,&configBuffer[CONFIG_PATT_REP_OFFSET],MAX_NUM_SNR*MAX_PATTERN_SIZE);
	ARCH_MEMCPY(_progConfig->patternSNRSize ,&configBuffer[CONFIG_PATT_SNR_SIZE_OFFSET],MAX_NUM_SNR);
	ARCH_MEMCPY(_progConfig->offPatchAdd ,&configBuffer[CONFIG_OFF_ADD_OFFSET],MAX_NUM_OFF*sizeof(_progConfig->offPatchAdd ));
	ARCH_MEMCPY(_progConfig->patchData ,&configBuffer[CONFIG_OFF_REP_OFFSET],MAX_NUM_SNR*MAX_PATTERN_SIZE);
	ARCH_MEMCPY(_progConfig->patchDataOriginal ,&configBuffer[CONFIG_OFF_ORG_OFFSET],MAX_NUM_SNR*MAX_PATTERN_SIZE);
	ARCH_MEMCPY(_progConfig->patternOFFSize ,&configBuffer[CONFIG_OFF_SIZE_OFFSET],MAX_NUM_OFF);
}