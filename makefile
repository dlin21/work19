all: main.o processor.o
	gcc -o main main.o
	gcc -o processor processor.o

main.o: main.c
	gcc -c main.c

processor.o: processor.c
	gcc -c processor.c

clean:
	rm *.o
	rm main
	rm processor
	rm toC
	rm toP
