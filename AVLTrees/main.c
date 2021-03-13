#include <stdio.h>
#include "avlTree.h"

int main(int argc, char const *argv[])
{
    avltree t1;
    initAVL(&t1);

    t1 = insertR(t1, 40);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 50);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 60);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 70);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 80);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 90);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = insertR(t1, 100);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    t1 = deleteNode(t1, 70);
    print2D(t1, 10);
    printf("End\n\n\n\n");

    return 0;
}
