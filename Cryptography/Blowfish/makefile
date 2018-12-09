Main.exe : Blowfish.o Main.o
			   g++ Blowfish.o Main.o -o Main.exe
Blowfish.o : Blowfish.cpp Blowfish.h ORIG_S_P.h
				g++ -c Blowfish.cpp
Main.o : Main.cpp Blowfish.h
			g++ -c Main.cpp
