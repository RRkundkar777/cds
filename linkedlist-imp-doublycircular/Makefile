app : main.o DClist.o
	cc main.o DClist.o -lm -o app
main.o : main.c
	cc -c main.c
DClist.o : DClist.c DClist.h
	cc -c DClist.c 