#include "..\inc\vm.h"
#include<stdio.h>
#include<stdlib.h>
#include "..\inc\instr\base.h"
#include "..\inc\devices\serial.h"
#include<string.h>
instr_t instructions[22];
int pc;
int ret;
int instrPtr;
vm_t vm;
int *mem;
bool cmpRegs[3];
int regs[10];
int state;
dev_t devs[1];
int devPtr;
void vm_init(int memSize) {
    vm.name = "VCPU version 1.0";
    vm.instructions = 20;
    int i;
    for (i = 0; i < 10; i++) {
        regs[i] = 0;
    }
    //Allocate memory
    mem = (int *)malloc(sizeof(int *)*memSize);
    base_addInstr();
    serial_init();
}
void vm_addInstr(char *name,int operands, void (*handler)(struct instr in)) {
    instr_t in;
    in.name = name;
    in.operands = operands;
    in.handler = handler;
    instructions[instrPtr++] = in;
}
vm_t vm_getVM() {
    return vm;
}
void vm_exec(int n[]) {
    pc = 0;
    state = 1;
    while (state) {
       instr_t in = instructions[n[pc++]];
       if (in.operands != 0) {
           if (!in.hasArgumentsAllocated) {
               in.opers = (int *)malloc(8*in.operands);
               in.hasArgumentsAllocated = true;
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
    state = 0;
    free(mem);
}
void vm_writeRegister(int num,int data) {
    regs[num] = data;
}
int vm_readRegister(int num) {
    return regs[num];
}
void vm_writeMemory(int addr,int data) {
    mem[addr] = data;
}
int vm_readMemory(int addr) {
    return mem[addr];
}

void vm_jump(int newaddr) {
    pc = newaddr;
}
void vm_jumpProgram(int addr) {
    ret = pc;
    pc = addr;
}
void vm_returnFromProgram() {
    pc = ret;
}
void vm_writeCMPRegister(int n,bool val) {
    cmpRegs[n] = val;
}
bool vm_readCMPRegister(int n) {
    return cmpRegs[n];
}
void vm_updateState(int n) {
    state = n;
}
void vm_printRegisters() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ",regs[i]);
    }
    printf("\n");
}
void vm_writePort(int port,int data) {
    devs[port].write(data);
}
int vm_readPort(int port) {
    return devs[port].read();
}
void vm_addDevice(char *name,void (*write)(int data),int (*read)()) {
    dev_t d;
    d.devName = name;
    d.write = write;
    d.read = read;
    devs[devPtr++] = d;
}