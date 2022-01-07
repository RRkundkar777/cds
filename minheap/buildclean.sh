# Shell Script for Clean Building
gcc -c main.c
gcc -c minHeap.c 
gcc minHeap.o main.o -o app
./app
rm app
rm *.o