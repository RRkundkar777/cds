#include"Dlist.h"

int main(){
    dlist L1;
    init(&L1);
    append(&L1,56);
    prepend(&L1,3);
    append(&L1,2);
    append(&L1,1);
    append(&L1,0);
    delete(&L1,65);
    display(L1);
    destroy(&L1);
    display(L1);
}