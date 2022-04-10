#include<stdio.h>
#include "..\inc\vm.h"
int main(int argc,char *argv[]) {
        printf("Gametab Virtual Machine\n");
        vm_init();
        getchar();
        vm_deInit();
        return 0;
}