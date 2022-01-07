# Shell script for clean build
gcc -c graph.c 
gcc -c main.c 
gcc -c graphQueue.c
gcc main.o graph.o graphQueue.o -o app
./app
rm app
rm *.o