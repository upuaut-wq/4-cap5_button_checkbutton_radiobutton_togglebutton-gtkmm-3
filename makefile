all: exe_arq

exe_arq: main.o botoes.o
	g++ -o exe_arq main.o botoes.o `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp botoes.h
	g++ -o main.o main.cpp -c `pkg-config gtkmm-3.0 --cflags --libs`

botoes.o: botoes.cpp 
	g++ -o botoes.o botoes.cpp -c `pkg-config gtkmm-3.0 --cflags --libs`

run: exe_arq
	./exe_arq