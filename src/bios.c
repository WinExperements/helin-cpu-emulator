#include "..\inc\bios.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *addPrint(char *c);
int *compileAndReturn() {
    static int ret[] = {1,0,72,21,0,0,1,0,101,21,0,0,1,0,108,21,0,0,1,0,108,21,0,0,1,0,111,21,0,0,1,0,32,21,0,0,1,0,102,21,0,0,1,0,114,21,0,0,1,0,111,21,0,0,1,0,109,21,0,0,1,0,32,21,0,0,1,0,66,21,0,0,1,0,82,21,0,0,1,0,79,21,0,0,1,0,77,21,0,0,0};
    return ret;
}