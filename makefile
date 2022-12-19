DerleCalistir: Program Calistir

Calistir:
	./bin/program.exe

Program: DinamikDizi Dugum Kuyruk Radix Hucre Doku Ikiliaramaagaci Organ Sistem Organizma Kontrol Test 
	g++ ./lib/dinamikdizi.o ./lib/dugum.o ./lib/kuyruk.o ./lib/radix.o  ./lib/hucre.o  ./lib/doku.o ./lib/ikiliaramaagaci.o ./lib/organ.o ./lib/sistem.o ./lib/organizma.o ./lib/kontrol.o ./lib/test.o -o ./bin/program.exe

Test:
	g++ -I "./include" -c ./src/test.cpp -o ./lib/test.o

Kontrol:
	g++ -I "./include" -c ./src/kontrol.cpp -o ./lib/kontrol.o	

Organizma:
	g++ -I "./include" -c ./src/organizma.cpp -o ./lib/organizma.o

Sistem:
	g++ -I "./include" -c ./src/sistem.cpp -o ./lib/sistem.o

Organ:
	g++ -I "./include" -c ./src/organ.cpp -o ./lib/organ.o

Ikiliaramaagaci:
	g++ -I "./include" -c ./src/ikiliaramaagaci.cpp -o ./lib/ikiliaramaagaci.o	

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