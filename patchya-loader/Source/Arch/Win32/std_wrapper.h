#ifndef _CMD_WRAPPER_H_
#define _CMD_WRAPPER_H_
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>


#define ARCH_CMD_WRITE(...) printf(__VA_ARGS__)
#define ARCH_STRCPY(dest,src) strcpy(dest,src)
#define ARCH_MALLOC(s)   malloc(s)
#define ARCH_FREE(buff)  free(buff) 
#define ARCH_STRLEN(buff) strlen(buff)
#define ARCH_STRCMP(buff1,buff2)  strcmp(buff1,buff2)
#define ARCH_STRTONUM(str,base) strtol(str, NULL, base)
#define ARCH_WAIT_MS(t)  Sleep(t)
#define ARCH_STRCAT(dst,src) strcat(dst,src)
#define ARCH_MEMCMP(buf1,buf2,s) memcmp(buf1,buf2,s)
#define ARCH_MEMCPY(dest,src,count) memcpy(dest,src,count)
#define ARCH_FCREATE(filename) fopen(filename,"w+");
#define ARCH_FWRITE(fp,...)  fprintf(fp ,__VA_ARGS__ )
#define ARCH_FCLOSE(fp)  fclose(fp)


#endif