#include "types.h"
#include "search_alg.h"

#ifndef MAX 
#define MAX(x,y) (((x) > (y))?(x):(y) )
#endif

static int16 badChar[255] ;

int32 searchWildCard(uint8* pattern,uint8* buffer,uint8 patternSize, uint32 bufferSize)
{
	int32 shiftVal =  0;
	int32 retVal = SEARCH_NOT_FOUND; 
	int32  matchIndex = patternSize;
	int i = 0 ;
	for (i = 0; i < 255; i++)
	{
		badChar[i] = -1;
	}
	for (i = 0; i < patternSize; i++)
	{
		badChar[pattern[i]] = i;
	}	
	while(shiftVal <= bufferSize-patternSize)
	{
		matchIndex = patternSize -1;
		while((matchIndex >= 0) && ((pattern[matchIndex] == buffer[shiftVal+matchIndex]) || (pattern[matchIndex]  == '?'))) 
		{
			matchIndex--;
		}
		
		if(matchIndex<0) 
		{
			return (shiftVal/2);
		}
		else 
		{
			shiftVal += MAX(1 , (matchIndex - badChar[buffer[shiftVal+matchIndex]]));
		}
	}
	return retVal;
}