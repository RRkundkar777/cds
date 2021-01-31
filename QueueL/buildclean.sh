gcc -c main.c -Wall
gcc -c queue.c -Wall
gcc main.o queue.o -lm -o app
./app
rm *.o
rm app