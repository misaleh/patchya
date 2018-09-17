#ifndef _DEBUGGER_H_
#define  _DEBUGGER_H_
#include "debugger_win32.h"


BP_HANDLE setSWBreakPoint(void* address,ARCH_PROCINFO _procInfo);

BP_HANDLE setHWBreakPoint(void* address,ARCH_PROCINFO _procInfo);

void clearSWBreakPoint(BP_HANDLE BPHandle);

void clearHWBreakPoint(BP_HANDLE BPHandle);

void* getEndAddress(ARCH_PROCINFO _procInfo);
void* getStartAddress(ARCH_PROCINFO _procInfo);

uint8 debuggerInit(ARCH_PROCINFO _procInfo);

#endif