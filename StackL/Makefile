app : main.o stack.o
	cc main.o stack.o -lm -o app
main.o : main.c 
	cc -c main.c -Wall
stack.o : stack.c stack.h
	cc -c stack.c -Wall 