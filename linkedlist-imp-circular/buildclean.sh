gcc -c main.c
gcc -c Clist.c
gcc main.o Clist.o -lm -o app
./app
rm *.o
rm app