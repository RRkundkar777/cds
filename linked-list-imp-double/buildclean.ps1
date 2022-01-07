gcc -c main.c -Wall
gcc -c Dlist.c -Wall
gcc main.o Dlist.o -lm -o app
./app
rm *.o
rm app