#ifndef CONFIG_H
#define CONFIG_H
#include "config_win32.h"
#include <QByteArray>
#define CONFIG_PATTERN "Thisisthestartofconfigurationbuffer!"
#define CONFIG_FLAG  0x55
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

#define MAX_NUM_SNR				10
#define MAX_NUM_OFF				10
#define MAX_PATTERN_SIZE		50

void convertIntToBA(int data, QByteArray& ba);
#endif // CONFIG_H
