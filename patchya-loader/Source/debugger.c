#include "debugger.h"
#include "std_wrapper.h"

static nodeBP* headNode = NULL;
static nodeBP* tailNode = NULL;
static HANDLE HWBPThreads[HW_BP_NB] = {0};


BP_HANDLE setSWBreakPoint(void* _address,ARCH_PROCINFO _procInfo)
{
	static uint32 lastHandle = 0 ;
	nodeBP *NewNodeBP = ARCH_MALLOC(sizeof(nodeBP));
	NewNodeBP->handleBP = lastHandle;
	NewNodeBP->procInfo = _procInfo;
	NewNodeBP->nextBP = NULL;
	NewNodeBP->addressBreakPoint = _address;
	lastHandle++;
	if(headNode == NULL) //first Node
	{
		headNode = NewNodeBP;
		tailNode = headNode;
	}
	else
	{
		tailNode->nextBP = NewNodeBP;
	}
	ARCH_setSWBreakPoint(NewNodeBP);
	return  NewNodeBP->handleBP;
}
BP_HANDLE setHWBreakPoint(void* _address,ARCH_PROCINFO _procInfo)
{
	
	int i  = 0;
	for(i = 0 ; i < HW_BP_NB ; i++)
	{
		/*if break point is not used*/
		if(HWBPThreads[i]  == 0 )
			HWBPThreads[i] = _procInfo.pi.hThread;
	}
	ARCH_setHWBreakPoint(_address,_procInfo,0);
	return 0;
	
}
void clearSWBreakPoint(BP_HANDLE BPHandle)
{
	nodeBP* tempNode = headNode;
	nodeBP* prevNode = headNode;
	while(tempNode != NULL)
	{
		if(tempNode->handleBP == BPHandle)
		{
			ARCH_clearSWBreakPoint(tempNode);
			/*remove the node from linked list*/
			prevNode->nextBP = tempNode->nextBP;
			return;
		}
		prevNode = tempNode;
		tempNode = tempNode->nextBP;
	}
}

void clearHWBreakPoint(BP_HANDLE BPHandle)
{
	if(BPHandle < HW_BP_NB)
	{
		/*clear the Breakpoint*/
		ARCH_clearHWBreakPoint(HWBPThreads[BPHandle],BPHandle);
		/*set Breakpoint as not used*/
		HWBPThreads[BPHandle] = 0;
	}
}

void* getEndAddress(ARCH_PROCINFO _procInfo)
{
	return (ARCH_getEndAddress(_procInfo)) ;
}
void* getStartAddress(ARCH_PROCINFO _procInfo)
{
	return (ARCH_getStartAddress(_procInfo)) ;
}


uint8 debuggerInit(ARCH_PROCINFO _procInfo)
{
	uint32 imageBase = 0;
	ARCH_getEXEBaseAddress(_procInfo);
	if(imageBase == 0)
		return ERROR_GENERAL;
	return ERROR_NONE;
}