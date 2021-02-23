#include"bst.h"
#include<stdio.h>

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
    
    return 0;
}