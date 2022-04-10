#ifndef VM_H
#define VM_H
typedef struct vm
{
    char *name;
    int regs[10];
    int instructions;
    int state;
} vm_t;

typedef struct instr
{
    char *name;
    int operands;
    int *opers;
    void (*handler)(struct instr in);
} instr_t;

void vm_init();
void vm_addInstr(char *name,int operands, void (*handler)(struct instr in));
vm_t *vm_getVM();
void vm_writeRegister(int reg,int data);
int vm_readRegister(int reg);
void vm_exec(int n[]);
void vm_deInit();
void vm_writeMemory(int addr,int data);
int vm_readMemory(int addr);
void vm_switchMemory(int *newMem,int delCur);

#endif