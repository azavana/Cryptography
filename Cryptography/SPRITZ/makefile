SPRITZ.exe : Function.o SPRITZ.o
	gcc Function.o SPRITZ.o -o SPRITZ.exe
Function.o : Function.c
	gcc -c Function.c
SPRITZ.o : SPRITZ.c SPRITZ.h
	gcc -c SPRITZ.c

