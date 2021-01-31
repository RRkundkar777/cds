gcc -c main.c -Wall
gcc -c array.c -Wall
gcc main.o array.o -lm -o app
./app
rm *.o
rm app