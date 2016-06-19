tropa:	tropas.o soldado.o avion.o tanque.o main.o
	g++ tropas.o soldado.o avion.o tanque.o main.o -o tropa -lncurses

main.o: main.cpp soldado.h tropas.h avion.h tanque.h
	g++ -c main.cpp

soldado.o:	soldado.cpp tropas.h soldado.h
	g++ -c soldado.cpp

avion.o:  avion.cpp tropas.h avion.h
	g++ -c avion.cpp

tanque.o:	tanque.cpp tropas.h tanque.h
	g++ -c tanque.cpp

tropas.o:	tropas.cpp tropas.h
	g++ -c tropas.cpp