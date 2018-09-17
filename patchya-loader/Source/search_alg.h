#ifndef _SEARCH_H_
#define _SEARCH_H_

#define SEARCH_NOT_FOUND               -1


int32 search(uint8* pattern,uint8* buffer,uint8 patternSize, uint32 bufferSize);
int32 searchWildCard(uint8* pattern,uint8* buffer,uint8 patternSize, uint32 bufferSize);

#endif