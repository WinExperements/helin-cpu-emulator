objects = src\main.o src\vm.o src\instr\base.o
OUTPUT_FILE = vm.exe
CCCOMPILER = i686-w64-mingw32-gcc
CCPARAMS = -Iinc

%.o: %.c
	$(CCCOMPILER) $(CCPARAMS) -c -o $@ $<
all: $(objects)
	$(CCCOMPILER) $(objects) -o $(OUTPUT_FILE)
clean:
	rm $(objects)