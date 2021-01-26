app : main.o Clist.o
	cc main.o Clist.o -lm -o app
main.o : main.c
	cc -c main.c
Clist.o : Clist.c Clist.h
	cc -c Clist.c