app : main.o queue.o
	cc main.o queue.o -lm -o app
main.o : main.c 
	cc -c main.c -Wall
queue.o : queue.c queue.h
	cc -c queue.c -Wall 