#include<stdio.h>
#include<stdlib.h>
#include "..\inc\vm.h"
#include<windows.h>
int prg[] = {1,0,65,21,0,0,0};
void waitForKey();
int main(int argc,char *argv[]) {
        printf("Gametab Virtual Machine\n");
        vm_init(65535);
        vm_exec(prg);
        vm_deInit();
        waitForKey();
        return 0;
}
void waitForKey() {
        char b[1];
        scanf("%c",b);
}