# Shell Script for Clean Building
gcc -c main.c
gcc -c maxHeap.c 
gcc maxHeap.o main.o -o app
./app
rm app
rm *.o