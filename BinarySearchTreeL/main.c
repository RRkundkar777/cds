#include "bst.h"
#include <stdio.h>
#include <limits.h>

// Driver Code
int main(int argc, char const *argv[])
{
    tree t1;
    initTree(&t1);
    insertI(&t1, 40);
    insertR(t1, 60);
    insertR(t1, 20);
    insertI(&t1, 70);
    insertI(&t1, 50);
    insertI(&t1, 30);
    insertI(&t1, 10);

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
    deleteNode(t1, 60);
    printf("Inorder of T1\n");
    inOrderI(t1);
    printf("\n");

    // PostOrder Construction
    int A1[] = {20, 50, 60, 30, 10};
    // Size and Index must be initialised
    int size = sizeof(A1) / sizeof(int);
    int postIndex = size - 1;
    tree t2 = constructFromPostOrder(A1, &postIndex, A1[postIndex], INT_MIN, INT_MAX, size);

    printf("InOrder of Constructed PostOrder Tree is \n");
    inOrderI(t2);
    printf("\n");

    // PreOrder Construction
    int A2[] = {10, 5, 1, 7, 40, 50};
    // Size and Index must be initialised
    int presize = sizeof(A1) / sizeof(int);
    int preIndex = 0;
    tree t3 = constructFromPreOrder(A2, &preIndex, A2[0], INT_MIN, INT_MAX, presize);

    printf("InOrder of Constructed PreOrder Tree is \n");
    inOrderI(t3);
    printf("\n");

    // Tree Visualisation
    printf("Tree Diagram: ");
    print2D(t1, 10);

    // Internal Node Count
    printf("Internal Node Count %d\n", internalNodeCount(t1));

    // Leaf Node Count
    printf("Leaf Node Count %d\n", leafNodeCount(t1));

    // Total Node Count
    printf("Total Node Count %d\n", nodeCount(t1));

    // isComplete
    printf("Binary Tree is Complete: %d\n", isComplete(t1, 0, nodeCount(t1)));

    // isFull
    printf("Binary Tree is Full: %d\n", isFullTree(t1));

    // Construction from both inOrder and preOrder
    infi in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    infi pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    tree t4 = buildFromPreOrder(in, pre, 0, len - 1);
    printf("Tree is:\n");
    print2D(t4, 10);

    // Construction from both inOrder and postOrder
    infi in2[] = {4, 8, 2, 5, 1, 6, 3, 7};
    infi post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int size5 = sizeof(in2) / sizeof(in2[0]);
    int pIndex5 = size5 - 1;
    tree t5 = buildFromPostOrder(in2, post, 0, size5 - 1, &pIndex5);
    printf("Tree is:\n");
    print2D(t5, 10);
    preOrder(t5);

    return 0;
}