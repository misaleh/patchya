#include "bin_funcs.h"
/*convert binary data to upper case ASCII*/
void convertCodeASCII(uint8* _src,uint8* _dst,uint32 _srcSize)
{
	uint32 i = 0 ;
	for(i = 0 ; i < _srcSize ; ++i)
	{
		
		_dst[i*2+1] = ((_src[i]&0x0F)<10)?((_src[i]&0x0F) + 48) : ((_src[i]&0x0F) + 55) ;
		_dst[i*2] = (((_src[i]&0xF0)>>4)<10)?(((_src[i]&0xF0)>>4)+ 48) : (((_src[i]&0xF0)>>4) + 55) ;
	}
}
