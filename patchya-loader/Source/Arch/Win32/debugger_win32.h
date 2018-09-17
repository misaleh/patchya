#ifndef _DEBUGGER_WIN32_H_
#define  _DEBUGGER_WIN32_H_
#include "Windows.h"
#include "ntstatus.h"
#include "WINNT.H"
#include <winternl.h>
#include "types.h"
#include "common_def.h"
#include "std_wrapper.h"
#include "logger.h"


#define SW_BP_OP   0xCC
#define HW_BP_NB   4

typedef  unsigned char BP_HANDLE;

typedef struct {
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
} ARCH_PROCINFO;

struct node {
	BP_HANDLE handleBP;
	uint8 oldOPcode;
	void* addressBreakPoint;
	ARCH_PROCINFO procInfo;
	struct node * nextBP;
} ;

typedef struct node nodeBP;

#define ARCH_CREATEPROC(_filename,  _procInfo)	CreateProcess( NULL,_filename ,NULL,NULL,FALSE,DEBUG_ONLY_THIS_PROCESS,NULL,NULL,&(_procInfo.si),&(_procInfo.pi))  
#define ARCH_CHECKDBGEVENTS(num) WaitForDebugEvent( &WIN32_debugEvent##num, INFINITE );
#define ARCH_CREATE_DEBUG_OBJECT(num) DEBUG_EVENT WIN32_debugEvent##num = {0};
#define ARCH_ISSWBPHIT(num) ((WIN32_debugEvent##num).dwDebugEventCode == EXCEPTION_DEBUG_EVENT) && (((WIN32_debugEvent##num).u.Exception.ExceptionRecord.ExceptionCode ==STATUS_WX86_BREAKPOINT ) ||((WIN32_debugEvent##num).u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_BREAKPOINT))
#define ARCH_DBG_CONTINUE(num) 	   ContinueDebugEvent(WIN32_debugEvent##num.dwProcessId,  WIN32_debugEvent##num.dwThreadId, DBG_CONTINUE);
#define ARCH_DBG_PASS(num)		ContinueDebugEvent(WIN32_debugEvent##num.dwProcessId,  WIN32_debugEvent##num.dwThreadId, DBG_EXCEPTION_NOT_HANDLED);		
#define ARCH_GET_SWBP_ADD(num)   (WIN32_debugEvent##num).u.Exception.ExceptionRecord.ExceptionAddress 
#define ARCH_ISCOND_SET_HWBP(num)  ((WIN32_debugEvent##num).dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT)
#define ARCH_ISHWBPHIT(num) ((WIN32_debugEvent##num).dwDebugEventCode == EXCEPTION_DEBUG_EVENT) && (((WIN32_debugEvent##num).u.Exception.ExceptionRecord.ExceptionCode ==STATUS_WX86_SINGLE_STEP ) ||((WIN32_debugEvent##num).u.Exception.ExceptionRecord.ExceptionCode == STATUS_SINGLE_STEP))
#define ARCH_READ_PROC_MEMORY(address,_procInfo,bufAdd,bufSize)  ReadProcessMemory(_procInfo.pi.hProcess,address, bufAdd, bufSize, NULL)
#define ARCH_WRITE_PROC_MEMORTY(address,_procInfo,bufAdd,bufSize) WriteProcessMemory(_procInfo.pi.hProcess, address ,bufAdd, bufSize, NULL)
#define ARCH_FLUSH_INST_CACHE(address,_procInfo,bufSize)  FlushInstructionCache(_procInfo.pi.hProcess,address, bufSize)
#define ARCH_SUSPEND_EXE(_procInfo)  SuspendThread(_procInfo.pi.hThread);
#define ARCH_RESUME_EXE(_procInfo)   ResumeThread(_procInfo.pi.hThread);
#define ARCH_RUN_TILL_END()  	ARCH_CREATE_DEBUG_OBJECT(1); \
									while(1) { \
									ARCH_CHECKDBGEVENTS(1); \
									ARCH_DBG_PASS(1); \
									if(WIN32_debugEvent1.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)break; }

void ARCH_setSWBreakPoint(nodeBP* currNode);
void ARCH_setHWBreakPoint(void* _address,ARCH_PROCINFO _procInfo,uint8 BPNum);

void ARCH_clearSWBreakPoint(nodeBP* currNode);
void ARCH_clearHWBreakPoint(HANDLE _hthread, uint8 BPNum);


void* ARCH_getEndAddress(ARCH_PROCINFO _procInfo);
void* ARCH_getStartAddress(ARCH_PROCINFO _procInfo);


void* ARCH_getEXEBaseAddress(ARCH_PROCINFO _procInfo);
/*just a getter for the variable to avoid reading the PEB each time*/
void* ARCH_convertRA(void*);
#endif