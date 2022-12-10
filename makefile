DerleCalistir: Program Calistir

Calistir:
	./bin/program.exe

Program: DinamikDizi Dugum Kuyruk Radix Hucre Doku  Main 
	g++ ./lib/dinamikdizi.o ./lib/dugum.o ./lib/kuyruk.o ./lib/radix.o  ./lib/hucre.o  ./lib/doku.o ./lib/main.o -o ./bin/program.exe

Main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

Doku:
	g++ -I "./include" -c ./src/doku.cpp -o ./lib/doku.o

Hucre:
	g++ -I "./include" -c ./src/hucre.cpp -o ./lib/hucre.o

DinamikDizi:
	g++ -I "./include" -c ./src/dinamikdizi.cpp -o ./lib/dinamikdizi.o

Radix:
	g++ -I "./include" -c ./src/radix.cpp -o ./lib/radix.o

Kuyruk:
	g++ -I "./include" -c ./src/kuyruk.cpp -o ./lib/kuyruk.o

Dugum:
	g++ -I "./include" -c ./src/dugum.cpp -o ./lib/dugum.o