#include"Slist.h"
#include<stdio.h>
int main(){
    slist L1;
    init(&L1);
    display (L1);
    append(&L1,2);display(L1);
    append(&L1,3);display(L1);
    append(&L1,4);display(L1);
    prepend(&L1,1);display(L1);
    delete(&L1,6);display(L1);
    destroy(&L1);
    printf("%p\n",L1);
    return 0;
}
