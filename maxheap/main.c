#include<stdio.h>
#include"maxHeap.h"

// Driver Code
int main(int argc, char const *argv[])
{
    maxHeap m1;
    initMaxHeap(&m1, 7);
    insert(&m1, 5);
    printf("root %d\n\n", m1.array[0]);
    insert(&m1, 4);
    printf("root %d\n", m1.array[0]);
    printf("left %d\n\n", m1.array[1]);
    insert(&m1, 3);
    printf("root %d\n", m1.array[0]);
    printf("left %d\n", m1.array[1]);
    printf("right %d\n\n", m1.array[2]);
    printf("\n\n\n");
    // decreaseKey(&m1, 1, 2);

    printf("root %d\n", m1.array[0]);
    printf("left %d\n", m1.array[1]);
    printf("right %d\n", m1.array[2]);

    print2D(m1,0,10);

    insert(&m1,6);
    insert(&m1,7);
    insert(&m1,8);

    print2D(m1,0,10);

    printf("\n\n\n\n\n\n\n");

    extractMax(&m1);

    print2D(m1,0,10);

    

    printf("\n\n\n\n\n\n\n");

    print2D(m1,0,10);

    return 0;
}