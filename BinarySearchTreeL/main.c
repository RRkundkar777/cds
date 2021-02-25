#include"bst.h"
#include<stdio.h>
#include<limits.h>

// Driver Code
int main(int argc, char const *argv[])
{
    tree t1;
    initTree(&t1);
    insertI(&t1,40);
    insertR(t1,60);
    insertR(t1,20);
    insertI(&t1,70);
    insertI(&t1,50);
    insertI(&t1,30);
    insertI(&t1,10);
    
    inOrder(t1);
    printf("\n");
    inOrderI(t1);
    printf("\n\n");

    preOrder(t1);
    printf("\n");
    preOrderI(t1);
    printf("\n\n");

    postOrder(t1);
    printf("\n");
    // postOrderI(t1);
    printf("\n\n");
    
    levelOrder(t1);

    printf("\n\n");
    printf("Deleting element 60\n");
    deleteNode(t1,60);
    inOrderI(t1);
    printf("\n");

    // PostOrder Construction
    int A1[] = {20, 50, 60, 30, 10};
    int size = sizeof(A1)/sizeof(int);
    int Index = size - 1;
    tree t2 = constructFromPostOrder(A1,&Index,A1[Index],INT_MIN,INT_MAX,size);
    printf("InOrder of Constructed Tree is \n");
    inOrderI(t2);
    
    return 0;
}