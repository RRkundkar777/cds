gcc -c main.c
gcc -c DClist.c 
gcc main.o DClist.o -lm -o app
./app
rm *.o
rm app