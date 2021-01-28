#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// BinaryTree ADT
#include"BinaryTree.h"

// Function to initialise the tree
void init(tree *T1)
{
    *T1 = (node*) malloc(sizeof(node));
    if(*T1)
    {
        (*T1)->data = 67;
        (*T1)->left = (*T1)->right = NULL;
        return;
    }
    else
    {
        printf("Memory unavailable\n");
        return;
    }   
}

void inOrderTraverse(tree T1)
{
    if(T1!=NULL)
    {
        // Change the format for multiple data types
        inOrderTraverse(T1->left);
        printf("%d\n",T1->data);
        inOrderTraverse(T1->right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    tree t1;
    init(&t1);
    printf("%d\n",t1->data);
    return 0;
}
