#include<stdio.h>
#include"stack.h"

int main(int argc, char const *argv[])
{
    stack S1;
    init(&S1);
    printf("Stack Empty %d\n",isEmpty(S1));
    push(&S1,1);
    printf("%d\n",stackTop(S1));
    push(&S1,2);
    printf("%d\n",stackTop(S1));
    push(&S1,3);
    printf("%d\n",stackTop(S1));
    pop(&S1);
    printf("%d\n",stackTop(S1));
    return 0;
}