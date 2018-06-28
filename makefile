exe:	mainProyecto.o
	g++ mainProyecto.o -o exe -lncurses

main.o:	mainProyecto.cpp 
	g++ -c main.cpp



