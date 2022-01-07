# Powershell Script for Dumpless Execution
gcc -c treeStack.c
gcc -c charStack.c
gcc -c expTree.c
gcc treeStack.o charStack.o expTree.o -o app
./app
rm *.o
rm app