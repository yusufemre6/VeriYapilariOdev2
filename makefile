DerleCalistir: Program Calistir

Calistir:
	./bin/program.exe

Program: Hucre Doku  Main 
	g++ ./lib/hucre.o  ./lib/doku.o ./lib/main.o -o ./bin/program.exe

Main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

Doku:
	g++ -I "./include" -c ./src/doku.cpp -o ./lib/doku.o

Hucre:
	g++ -I "./include" -c ./src/hucre.cpp -o ./lib/hucre.o