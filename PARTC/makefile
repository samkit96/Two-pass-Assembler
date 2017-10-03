
exb: machexec.o functionsc.o
	gcc machexec.o functionsc.o -o exb

machexec.o: machexec.c
	gcc -c machexec.c

functionsc.o: functionsc.c functionsc.h
	gcc -c functionsc.c

run: exb
	./exb
clean:
	rm *.o exb
