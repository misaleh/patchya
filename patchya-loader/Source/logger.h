#ifndef _LOGGER_H_
#define _LOGGER_H_
#include "config.h"

#define LOG_EXTENSION "_log"
#define LOG_WRITE(...) ARCH_FWRITE(getLogHandle(),__VA_ARGS__);


void loggerInit(char* fileName);
void logConfig(projectConfig * myprojectConfig);
ARCH_FILE* getLogHandle(void);
void loggerDeInit(void);
#endif