gcc -c main.c 
gcc -c bst.c
gcc -c treeQueue.c
gcc -c treeStack.c
gcc main.o bst.o treeQueue.o treeStack.o -o app
./app
rm *.o
rm app