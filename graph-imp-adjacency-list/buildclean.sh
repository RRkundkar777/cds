# Shell Script for clean build
gcc -c graph.c
gcc -c main.c 
gcc main.o graph.o -o app
./app 
rm app
rm *.o