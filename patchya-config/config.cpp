#include "config.h"

void convertIntToBA(int data, QByteArray& ba)
{
    ba.resize(4);
    ba[0] = data&0x000000ff;
    ba[1] = (data&0x0000ff00)>>8;
    ba[2] = (data&0x00ff0000)>>16;
    ba[3] = (data&0xff000000)>>24;

}
