#ifndef VM_H
#define VM_H
#include<stdbool.h>
typedef struct vm
{
    char *name;
    int instructions;
} vm_t;

typedef struct instr
{
    char *name;
    int operands;
    int *opers;
    bool hasArgumentsAllocated;
    int pos;
    void (*handler)(struct instr in);
} instr_t;
typedef struct dev {
    char *devName;
    void (*write)(int data);
    int (*read)();
} dev_t;

void vm_init(int memSize);
void vm_addInstr(char *name,int operands, void (*handler)(struct instr in));
vm_t vm_getVM();
void vm_writeRegister(int reg,int data);
int vm_readRegister(int reg);
void vm_exec(int n[]);
void vm_deInit();
void vm_writeMemory(int addr,int data);
int vm_readMemory(int addr);
void vm_switchMemory(int newMem[],int delCur);
void vm_jump(int newAddr);
void vm_jumpProgram(int addr);
void vm_returnFromProgram();
void vm_writeCMPRegister(int n,bool val);
bool vm_readCMPRegister(int n);
void vm_updateState(int n);
void vm_printRegisters();
void vm_writePort(int,int);
int vm_readPort(int);
void vm_addDevice(char *name,void (*write)(int data),int (*read)());
void vm_deCompile(int n[]);
instr_t *vm_getInstructionList();
int vm_getInstructionsCount();
#endif