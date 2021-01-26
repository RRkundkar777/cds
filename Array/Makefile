app : main.o array.o
	cc main.o array.o -lm -o app
main.o : main.c 
	cc -c main.c -Wall
array.o : array.c array.h
	cc -c array.c -Wall