#include"Dlist.h"

int main(){
    dlist L1;
    init(&L1);
    append(&L1,56);
    display(L1);
    prepend(&L1,3);
    display(L1);
    append(&L1,2);
    display(L1);
    append(&L1,1);
    display(L1);
    append(&L1,0);
    display(L1);
    delete(&L1,65);
    delete(&L1,2);
    display(L1);
    display(L1);
    destroy(&L1);
    display(L1);
}