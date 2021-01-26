#include"array.h"

//Driver Code
int main(){
    array A1;
    init(&A1,8);
    append(&A1,7);
    append(&A1,8);
    append(&A1,9);
    append(&A1,10);
    insert(&A1,7,78);
    display(A1); 
}