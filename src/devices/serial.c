#include "..\..\inc\devices\serial.h"
#include "..\..\inc\vm.h"
#include<stdio.h>
void serial_write(int data) {
    printf("%c",(char)data);
}
int serial_read() {
    char c;
    scanf("%c",c);
    return c;
}
void serial_init() {
    vm_addDevice("serial",serial_write,serial_read);
}