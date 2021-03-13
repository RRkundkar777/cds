gcc -c main.c -Wall
gcc -c stack.c -Wall 
gcc main.o stack.o -lm -o app
./app
rm *.o
rm app.exe