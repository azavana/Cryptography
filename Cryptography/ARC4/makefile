main.exe : arc4.o main.o
		 g++ arc4.o main.o -o main.exe
arc4.o : arc4.cpp header.h
	    g++ -c arc4.cpp
main.o : main.cpp header.h
	    g++ -c main.cpp
