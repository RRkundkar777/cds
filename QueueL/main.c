#include"queue.h"
#include<stdio.h>

int main(int argc, char const *argv[])
{
    queue Q1;
    init(&Q1);
    printf("%d\n",isEmpty(Q1));
    enqueue(&Q1,3);
    printf("%d\n",peek(Q1));
    enqueue(&Q1,4);
    printf("%d\n",peek(Q1));
    enqueue(&Q1,5);
    printf("%d\n",peek(Q1));
    dequeue(&Q1);
    printf("%d\n",peek(Q1));
    dequeue(&Q1);
    printf("%d\n",peek(Q1));
    return 0;
}