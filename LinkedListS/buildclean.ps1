gcc -c main.c -Wall
gcc -c Slist.c -Wall
gcc main.o Slist.o -lm -o app
./app
rm *.o
rm app