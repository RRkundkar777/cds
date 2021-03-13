gcc -c avlTree.c
gcc -c main.c
gcc main.o avlTree.o -o app
./app
rm *.o
rm app