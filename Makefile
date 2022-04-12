objects = src\main.o src\vm.o src\instr\base.o
libObjs = src\vm.o src\instr\base.o src\devices\serial.o src\bios.o
OUTPUT_FILE = vm.exe
CCCOMPILER = gcc
CCPARAMS = -Iinc -fpic

%.o: %.c
	$(CCCOMPILER) $(CCPARAMS) -c -o $@ $<
all: makeLib
	$(CCCOMPILER) $(CCPARAMS) src\main.c -o $(OUTPUT_FILE) -L. -lvm
clean:
	del $(libObjs)
makeLib: $(libObjs)
	$(CCCOMPILER) -fpic -shared -o vm.dll $(libObjs)