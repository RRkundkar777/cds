gcc -c main.c -Wall
gcc -c bst.c -Wall
gcc main.o bst.o -lm -o app
./app
rm *.o
rm app