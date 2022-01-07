app : main.o bst.o
	cc main.o bst.o -lm -o app
main.o : main.c 
	cc -c main.c -Wall
bst.o : bst.c bst.h
	cc -c bst.c -Wall