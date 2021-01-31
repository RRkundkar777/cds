#include<stdio.h>
#include"stack.h"

int main(int argc, char const *argv[])
{
    stack s1;
    init(&s1);
    printf("%lld\n%lld\n",s1.size,s1.stackTop);
    printf("%d\n",isEmpty(s1));
    push(&s1,67);
    printf("%d\n",isEmpty(s1));
    printf("%d\n",peek(s1));
    push(&s1,78);
    push(&s1,103);
    push(&s1,500);
    printf("%d\n",peek(s1));
    printf("Popped %d\n",pop(&s1));
    printf("%d\n",peek(s1));

    printf("Popped %d\n",pop(&s1));

    printf("Popped %d\n",pop(&s1));

    printf("Popped %d\n",pop(&s1));
    pop(&s1);

    for (int i = 0; i < 100; i++)
    {
        push(&s1,i);
        printf("%d\n",i);
    }
    push(&s1,101);


    return 0;
}