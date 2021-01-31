#include"array.h"

//Driver Code
int main(){
    array A1;
    init(&A1,8);
    append(&A1,7);
    append(&A1,8);
    append(&A1,9);

    append(&A1,10);
    append(&A1,11);
    append(&A1,12);
    append(&A1,13);

    display(A1);
    insert(&A1,3,122);
    replace(&A1,1,733);
    display(A1);
}