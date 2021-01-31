#include"DClist.h"

int main(int argc, char const *argv[])
{
    dclist L1;
    init(&L1);
    append(&L1,7);
    append(&L1,8);
    prepend(&L1,6);
    prepend(&L1,5);
    append(&L1,9);
    display(L1);
    delete(&L1,5);
    display(L1);
    delete(&L1,9);
    display(L1);
    delete(&L1,7);
    display(L1);
    destroy(&L1);
    display(L1);
    return 0;
}