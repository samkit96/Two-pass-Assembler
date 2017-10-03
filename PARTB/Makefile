
exb: my_assembler.o functions.o
	gcc my_assembler.o functions.o -o exb

my_assembler.o: my_assembler.c
	gcc -c my_assembler.c

functions.o: functions.c functions.h
	gcc -c functions.c

run: exb
	./exb ../input_files/testfile.txt
clean:
	rm *.o exb
