#include<stdio.h>
#include"bst.h"

int main(int argc, char const *argv[])
{
    tree t1;
    init(&t1);
    insertI(t1,40);
    insertR(t1,60);
    print2D(t1,0,0);
    printf("\n\n\n\n");
    insertI(t1,20);
    insertI(t1,80);
    insertI(t1,50);
    print2D(t1,0,0);
    printf("\n\n\n\n");
    insertI(t1,30);
    insertI(t1,10);
    print2D(t1,0,0);
    
    inOrder(t1,0);
    printf("\n");
    preOrder(t1,0);
    printf("\n");
    postOrder(t1,0);
    printf("\n\n");

    printf("Search Result: %d\n",Isearch(t1,140));
    printf("Search Result: %d\n",Isearch(t1,60));

    return 0;
}