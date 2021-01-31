#include"Clist.h"

int main(){
    clist L1;
    init(&L1);
    append(&L1,78);
    display(L1);
    append(&L1,88);
    display(L1);
    prepend(&L1,34);
    display(L1);
    delete(&L1,2000);
    display(L1);
    append(&L1,455);
    display(L1);
    delete(&L1,88);
    display(L1);
    destroy(&L1);
    display(L1);
}