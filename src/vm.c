#include "..\inc\vm.h"
#include<stdio.h>
#include<stdlib.h>
#include "..\inc\instr\base.h"
instr_t instructions[2];
int pc;
int instrPtr;
vm_t *vm;
int *mem;
void vm_init() {
    printf("%s: init started\n",__FILE__);
    vm = (vm_t *)malloc(sizeof(vm_t));
    vm->name = "VCPU version 1.0";
    vm->instructions = 2;
    base_addInstr();
    mem = (int *)malloc(65535);
    printf("%s: initialised\n");
}
void vm_addInstr(char *name,int operands, void (*handler)(struct instr in)) {
    instr_t in;
    in.name = name;
    in.operands = operands;
    in.handler = handler;
    instructions[instrPtr++] = in;
}
vm_t *vm_getVM() {
    return vm;
}
void vm_exec(int n[]) {
   while(vm->state != 1) {
       instr_t in = instructions[n[pc++]];
       if (in.operands != 0) {
           if (in.opers == NULL) {
               in.opers = (int *)malloc(in.operands);
           }
           int i;
           for (i = 0; i < in.operands; i++) {
               in.opers[i] = n[pc++];
           }
       }
       in.handler(in);
   }
}
void vm_deInit() {
    vm->state = 1;
    free(vm);
}
void vm_writeRegister(int num,int data) {
    vm->regs[num] = data;
}
int vm_readRegister(int num) {
    return vm->regs[num];
}
void vm_writeMemory(int addr,int data) {
    mem[addr] = data;
}
int vm_readMemory(int addr) {
    return mem[addr];
}
void vm_switchMemory(int *newMem,int delCur) {
    if (delCur) free(mem);
    mem = newMem;
}