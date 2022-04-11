#include "..\..\inc\instr\base.h"
#include <stdio.h>
void hlt_handler(instr_t in) {
     vm_updateState(0);
}
void ldr_handler(instr_t in) {
    vm_writeRegister(in.opers[0],in.opers[1]);
}
void str_handler(instr_t in) {
    vm_writeMemory(in.opers[1],in.opers[0]);
}
void mre_handler(instr_t in) {
    vm_writeRegister(in.opers[1],vm_readRegister(in.opers[0]));
}
void jmp_handler(instr_t in) {
    vm_jump(in.opers[0]);
}
void call_handler(instr_t in) {
    vm_jumpProgram(in.opers[0]);
}
void ret_handler(instr_t in) {
    vm_returnFromProgram();
}
void add_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) + vm_readRegister(in.opers[1]));
}
void sub_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) - vm_readRegister(in.opers[1]));
}void div_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) / vm_readRegister(in.opers[1]));
}
void mul_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) * vm_readRegister(in.opers[1]));
}
void and_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) & vm_readRegister(in.opers[1]));
}
void or_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) | vm_readRegister(in.opers[1]));
}
void xor_handler(instr_t in) {
    vm_writeRegister(in.opers[2],vm_readRegister(in.opers[0]) ^ vm_readRegister(in.opers[1]));
}
void cmp_handler(instr_t in) {
    int val1 = vm_readRegister(in.opers[0]);
    int val2 = vm_readRegister(in.opers[1]);
    if (val1 == val2) {
        vm_writeCMPRegister(0,true);
    }
    if (val1 > val2) {
        vm_writeCMPRegister(1,true);
    }
    if (val1 < val2) {
        vm_writeCMPRegister(1,true);
    }
}
void je_handler(instr_t in) {
    if (vm_readCMPRegister(0)) {
        vm_jump(in.opers[0]);
    }
}
void jne_handler(instr_t in) {
    if (!vm_readCMPRegister(0)) {
        vm_jump(in.opers[0]);
    }
}
void jle_handler(instr_t in) {
    if (vm_readCMPRegister(1)) {
        vm_jump(in.opers[0]);
    }
}
void jge_handler(instr_t in) {
    if (vm_readCMPRegister(2)) {
        vm_jump(in.opers[0]);
    }
}
void jleq_handler(instr_t in) {
    if (vm_readCMPRegister(0) || vm_readCMPRegister(1)) {
        vm_jump(in.opers[0]);
    }
}
void jgle_handler(instr_t in) {
    if (vm_readCMPRegister(0) || vm_readCMPRegister(2)) {
        vm_jump(in.opers[0]);
    }
}
void inb_handler(instr_t in) {
    vm_writePort(in.opers[0],vm_readRegister(in.opers[1]));
}
void outb_handler(instr_t in) {
    vm_writeRegister(in.opers[1],vm_readPort(in.opers[0]));
}
void base_addInstr() {
    //Add instruction set
    vm_addInstr("hlt",0,hlt_handler);
    vm_addInstr("ldr",2,ldr_handler);
    vm_addInstr("str",2,str_handler);
    vm_addInstr("mre",2,mre_handler);
    vm_addInstr("jmp",1,jmp_handler);
    vm_addInstr("call",1,call_handler);
    vm_addInstr("ret",0,ret_handler);
    vm_addInstr("add",3,add_handler);
    vm_addInstr("sub",3,sub_handler);
    vm_addInstr("div",3,div_handler);
    vm_addInstr("mul",3,mul_handler);
    vm_addInstr("and",3,and_handler);
    vm_addInstr("or",3,or_handler);
    vm_addInstr("xor",3,xor_handler);
    vm_addInstr("cmp",2,cmp_handler);
    vm_addInstr("je",1,je_handler);
    vm_addInstr("jne",1,jne_handler);
    vm_addInstr("jle",1,jle_handler);
    vm_addInstr("jge",1,jge_handler);
    vm_addInstr("jleq",1,jleq_handler);
    vm_addInstr("jgle",1,jge_handler);
    vm_addInstr("inb",2,inb_handler);
    vm_addInstr("outb",2,outb_handler);
}