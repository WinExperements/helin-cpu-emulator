#include "..\inc\instr\base.h"
#include "..\inc\vm.h"
#include <stdio.h>
void hlt_handler(instr_t in) {
     vm_getVM()->state = 1;
}
void ldr_handler(instr_t in) {
    vm_writeRegister(in.opers[0],in.opers[1]);
}
void base_addInstr() {
    //Add instruction set
    vm_addInstr("hlt",0,hlt_handler);
    vm_addInstr("ldr",2,ldr_handler);
}