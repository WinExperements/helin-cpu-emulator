#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "..\inc\vm.h"
FILE *output;
char *readFile(char *path) {
    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
    return string;
}
typedef struct split_element {
    char *token;
    bool hasNext;
    int len;
    struct split_element *next;
} split_t;
split_t *split(char *text,char *token) {
    split_t *ret = (split_t *)malloc(sizeof(split_t));
    split_t *cur = ret;
    char *c = strtok(text,token);
    int len = 0;
    while(c != NULL) {
        cur->token = c;
        cur->hasNext = true;
        cur->next = (split_t *)malloc(sizeof(split_t));
        cur = cur->next;
        len++;
        c = strtok(NULL,token);
    }
    cur->hasNext = false;
    cur->next = NULL;
    ret->len = len;
    return ret;
}
int getInstructionNumber(char *instr) {
    instr_t *list = vm_getInstructionList();
    int c = vm_getInstructionsCount();
    int i;
    for ( i = 0; i < c; i++) {
        instr_t t = list[i];
        if (!strcmp(t.name,instr)) {
            return t.pos;
        }
    }
    char buff[100];
    sprintf(buff,"Error: %s is not valid instruction. Please check file or read documentation",instr);
    MessageBoxA(NULL,buff,"Error",16);
    exit(1);
    return -1;
}
void parseAndWriteLine(char *c) {
    split_t *s = split(c," ");
    int len = s->len;
    bool hasInstr = false;
    char instr[len];
    int argPtr = 1;
    while(s->hasNext) {
        if (!hasInstr) {
            instr[0] = getInstructionNumber(s->token);
            hasInstr = true;
        } else {
            instr[argPtr++] = atoi(s->token);
        }
        s = s->next;
    }
    free(s);
    if (fwrite(&instr,len,1,output) != 1) {
        MessageBoxA(NULL,"Cannot write output\n","Error",16);
        exit(1);
    }
}
int main(int argc,char *argv[]) {
    if (argc < 3) {
        char buff[100];
        sprintf(buff,"Use %s <input file> <output file>",argv[0]);
        MessageBoxA(NULL,buff,"Error",16);
        return 1;
    } else {
        char *p = readFile(argv[1]);
        output = fopen(argv[2],"wb");
        if (output == NULL) {
            MessageBoxA(NULL,"Cannot open output file.","Error",16);
            return 1;
        }
        vm_init(0);
        vm_deInit();
        split_t *s = split(p,"\n");
        while(s->hasNext) {
            parseAndWriteLine(s->token);
            s = s->next;
        }
        free(p);
        free(s);
    }
    return 0;
}