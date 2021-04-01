all: Metadata

Metadatadebug.o:
	g++ -g ./lib/Metadata.cpp -c -o ./objs/Metadata.o


Metadata.o:
	g++ ./lib/Metadata.cpp -c -o ./objs/Metadata.o

Metadata: Metadata.o
	g++ -shared -o  ./release/Metadata.dll ./objs/Metadata.o
	cp ./lib/*.h ./release

Teste.o: Metadatadebug.o
	g++ -g -I ./lib ./test/Teste.cpp -c -o ./objs/Teste.o

debug: Teste.o
	g++ -g -Wall -o  ./debug/main ./objs/Metadata.o ./objs/Teste.o

clear:
	rm  ./objs/*
	rm  ./debug/*
	rm  ./release/*