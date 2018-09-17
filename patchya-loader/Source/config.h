#ifndef _CONFIG_H_
#define _CONFIG_H_
#include "types.h"

/*memory check patch*/
#define PATCH_COND_MEM			0
/*program counter check patch*/
#define PATCH_COND_PC			1
/*timeout patch*/
#define PATCH_COND_TOUT			2
/*No Type*/
#define PATCH_NO_COND			3

/*search and replace patch*/
#define PATCH_TYPE_SNR			0
/*offset patch*/
#define PATCH_TYPE_OFF			1
/*assembly search and replace*/
#define PATCH_TYPE_ASM			2
/*No Type*/
#define PATCH_NO_TYPE			3

#define CONFIG_FLAG 			0x55


#define GATE_COND_MET  0x01
#define GATE_COND_NOTMET  0x00


#define BLOCK_SIZE				512
#define MAX_NUM_SNR				10
#define MAX_NUM_OFF				10
#define MAX_INFILE_SIZE			100
#define MAX_PATTERN_SIZE		50

/** Offset of configurations in config Buffer **/
/*will change if struct change, can be more generic with using size of plus of intial index*/
#define CONFIG_FLAG_OFFSET   0
#define CONFIG_INFILE_OFFSET 1
#define CONFIG_GATE_CONDITION_OFFSET 101
#define CONFIG_MEM_PC_OFFSET  114
#define CONFIG_TIMEOUT_OFFSET 102
#define CONFIG_MEM_ADD_OFFSET 106
#define CONFIG_MEM_VAL_OFFSET 110
#define CONFIG_NUM_SNR_OFFSET 122
#define CONFIG_NUM_OFF_OFFSET 118
#define CONFIG_PATT_SRCH_OFFSET 126
#define CONFIG_PATT_REP_OFFSET 626
#define CONFIG_PATT_SNR_SIZE_OFFSET 1126
#define CONFIG_OFF_ADD_OFFSET 1136
#define CONFIG_OFF_ORG_OFFSET 1676
#define CONFIG_OFF_REP_OFFSET 1176
#define CONFIG_OFF_SIZE_OFFSET 2176

typedef struct 
{
	/*check if the struct is exe is proprley configured*/
	uint8 configType; //offset 0 
	/*victim file name*/
	char inFile[MAX_INFILE_SIZE];//offset 1
	/*condition to start patching*/
	uint8 gateCondition;//offset 101
	/*if gateCondition =  PATCH_COND_TOUT*/ 
	uint32 timeout;  //offset 102
	/*if gateCondition =  PATCH_COND_MEM*/ 
	uint32 memAdd;   //offset 106
	uint32 memVal;   //offset 110
	/*if gateCondition =  PATCH_COND_PC*/ 
	uint32 pcVal;    //offset 114
	/*number of offset patches*/
	uint32 numOffPatch; //offset 118
	/*number of SNR patches*/
	uint32 numofSNRpatch; //offset 122
	uint8 patternSearch[MAX_NUM_SNR*MAX_PATTERN_SIZE];//offset 126
	uint8 patternReplace[MAX_NUM_SNR*MAX_PATTERN_SIZE]; //offset 626
	uint8 patternSNRSize[MAX_NUM_SNR]; //offset 1126
	uint32 offPatchAdd[MAX_NUM_SNR]; //offset 1136
	uint8 patchData[MAX_NUM_SNR*MAX_PATTERN_SIZE]; //offset 1176
	uint8 patchDataOriginal[MAX_NUM_OFF*MAX_PATTERN_SIZE]; //offset 1676
	uint8 patternOFFSize[MAX_NUM_SNR]; //offset 2176
} projectConfig; 


void readConfiguration(projectConfig*);



#endif