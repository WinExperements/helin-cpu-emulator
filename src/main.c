#include<stdio.h>
#include<stdlib.h>
#include "..\inc\vm.h"
#include "..\inc\bios.h"
void waitForKey();
void convertChar(char in[],int out[],int size) {
        int i;
        for (i = 0; i < size; i++) {
                out[i] = in[i];
        }
}
int main(int argc,char *argv[]) {
        if (argc < 2) {
                printf("Use %s <file name>\n",argv[0]);
                return 0;
        }
        FILE *in = fopen(argv[1],"r");
        if (in == NULL) {
                printf("Failed to open file\n");
                return 0;
        }
        fseek(in,0,SEEK_END);
        size_t size = ftell(in);
        fseek(in,0,SEEK_SET);
        char buff[size];
        int ii[size];
        if (!fread(buff,size,1,in)) {
                fclose(in);
                printf("Failed to read file\n");
                return 0;
        }
        fclose(in);
        convertChar(buff,ii,size);
        vm_init(65535);
        vm_exec(ii);
        vm_deInit();
        return 0;
}
void waitForKey() {
        char b[1];
        scanf("%c",b);
}