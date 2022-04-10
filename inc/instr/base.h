#ifndef BASE_H
#define BASE_H
#include "..\inc\vm.h"
/* Memory/Control instructions handlers */
void hlt_handler(instr_t in);
void ldr_handler(instr_t in);
void str_handler(instr_t in);
void mre_handler(instr_t in);
void jmp_handler(instr_t in);
void call_handler(instr_t in);
void ret_handler(instr_t in);
/* Arichmetical and logical handlers */
void add_handler(instr_t in);
void sub_handler(instr_t in);
void div_handler(instr_t in);
void mul_handler(instr_t in);
void and_handler(instr_t in);
void or_handler(instr_t in);
void xor_handler(instr_t in);
/* Branch jumping */
void cmp_handler(instr_t in);
void je_handler(instr_t in);
void jne_handler(instr_t in);
void jle_handler(instr_t in);
void jge_handler(instr_t in);
void jle_handler(instr_t in);
void jge_handler(instr_t in);
/* Input / output */
void inb_handler(instr_t in);
void outb_handler(instr_t in);
void base_addInstr();
#endif