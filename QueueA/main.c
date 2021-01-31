#include<stdio.h>
#include"queue.h"

int main(int argc, char const *argv[])
{
    queue q1;
    init(&q1);
    printf("Initial State %lld\n%lld\n",q1.size,q1.front);
    printf("FIrst Isempty %d\n",isEmpty(q1));
    enqueue(&q1,67);
    printf("2nd isempty %d\n",isEmpty(q1));
    printf("QueueFront @ -1 %d\n",queueFront(q1));
    enqueue(&q1,78);
    enqueue(&q1,103);
    enqueue(&q1,500);
    printf("QueueFront 2nd %d\n",queueFront(q1));
    printf("dequeueped %d\n",dequeue(&q1));
    printf("Third QueueFront %d\n",queueFront(q1));

    printf("dequeueped %d\n",dequeue(&q1));

    printf("dequeueped %d\n",dequeue(&q1));

    printf("dequeueped %d\n",dequeue(&q1));
    dequeue(&q1);

    for (int i = 0; i < 100; i++)
    {
        enqueue(&q1,i);
        printf("%dth isFull: %d\n",i,isFull(q1));
    }
    enqueue(&q1,101);
    return 0;
}