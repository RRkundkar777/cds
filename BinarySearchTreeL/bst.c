#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "treeQueue.h"
#include "treeStack.h"

// Binary Search Tree ADT (Include Guard to Handle recursive Inclusion)
#ifndef BST_H
#define BST_H
#include "bst.h"
#endif

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Function to initialise the tree
void initTree(tree *T1)
{
    *T1 = NULL;
}

// Recursive Function for InOrder Traversal
void inOrder(tree T1)
{
    if (T1 == NULL)
    {
        return;
    }
    else
    {
        // Go To the Left Subtree
        inOrder(T1->left);
        // Change the format for multiple data types
        printf("%d ", T1->data);
        // Go To the Right Subtree
        inOrder(T1->right);
    }
}

// Recursive Function for PreOrder Traversal
void preOrder(tree T1)
{
    if (T1 != NULL)
    {
        // Change the format for multiple data types
        printf("%d ", T1->data);
        // Go To the Left Subtree
        preOrder(T1->left);
        // Go To the Right Subtree
        preOrder(T1->right);
    }
    return;
}

// Recursive Function for PostOrder Traversal
void postOrder(tree T1)
{
    if (T1 == NULL)
    {
        return;
    }
    // Go To the Left Subtree
    postOrder(T1->left);
    // Go To the Right Subtree
    postOrder(T1->right);
    // Change the format for multiple data types
    printf("%d ", T1->data);
}

// Function to Iteratively insert an element into BST
void insertI(tree *T1, infi data)
{
    // Allocating a newnode
    node *newnode = (node *)malloc(sizeof(node));
    // Handling malloc failure
    if (!newnode)
    {
        return;
    }
    // Initialsing the newnode
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    // If root == NULL --> point root to newnode
    if (*T1 == NULL)
    {
        *T1 = newnode;
        return;
    }
    // Travelling Pointers
    node *leader = *T1;
    node *follower = NULL;
    // Traversing the BST for finding the correct position for newnode
    while (leader)
    {
        // If data == data of root --> return coz BST does not allow repeated nodes
        if (data == leader->data)
        {
            // Freeing the memory occupied by newnode
            free(newnode);
            return;
        }
        // Else if data < data of root --> Go To the Left subtree
        else if (data < leader->data)
        {
            follower = leader;
            leader = leader->left;
        }
        // Else Go To the Right subtree
        else
        {
            follower = leader;
            leader = leader->right;
        }
    }
    // Linking the newnode to its correct position
    if (data < follower->data)
    {
        follower->left = newnode;
    }
    else if (data > follower->data)
    {
        follower->right = newnode;
    }
    return;
}

// Recursive function to insert a node into BST
node *insertR(tree T1, infi data)
{
    if (T1 == NULL)
    {
        // Creating a newnode
        node *newnode = (node *)malloc(sizeof(node));
        // Handling Malloc Failure
        if (!newnode)
        {
            return T1;
        }
        // Initialising the newnode
        newnode->data = data;
        newnode->left = newnode->left = NULL;
        // Linking the newnode to BST
        T1 = newnode;
        return T1;
    }

    // If node data < root data --> Go To the Left subtree
    if (data < T1->data)
    {
        T1->left = insertR(T1->left, data);
    }
    // If node data > root data --> Go To the Right subtree
    else
    {
        T1->right = insertR(T1->right, data);
    }
    return T1;
}

// Function for Level Order Traversal using Queue
void levelOrder(tree T1)
{
    // Declaring a Queue
    queue nodeQueue;
    initQueue(&nodeQueue);

    // Travelling Pointer
    node *traveller = T1;

    // First Enqueue
    printf("%d ", traveller->data);
    enqueue(&nodeQueue, traveller);

    while (!isEmptyQueue(nodeQueue))
    {
        traveller = dequeue(&nodeQueue);
        if (traveller->left)
        {
            // Printing the Data (Change the format specifier for multiple data types)
            printf("%d ", traveller->left->data);
            enqueue(&nodeQueue, traveller->left);
        }
        if (traveller->right)
        {
            // Printing the Data (Change the format specifier for multiple data types)
            printf("%d ", traveller->right->data);
            enqueue(&nodeQueue, traveller->right);
        }
    }
}

// Iterative Function for PreOrder Traversal using Stack
void preOrderI(tree T1)
{
    // Intialising a Stack
    stack s1;
    initStack(&s1);
    // Travelling Pointer
    node *traveller = T1;
    // PreOrder Traversal
    while (!isEmptyStack(s1) || traveller != NULL)
    {
        if (traveller != NULL)
        {
            printf("%d ", traveller->data);
            push(&s1, traveller);
            traveller = traveller->left;
        }
        else
        {
            traveller = pop(&s1);
            traveller = traveller->right;
        }
    }
}

// Iterative Function for InOrder Traversal using Stack
void inOrderI(tree T1)
{
    // Initalising the Stack
    stack S1;
    initStack(&S1);
    // Travelling Pointer
    node *traveller = T1;
    // InOrder Traversal
    while (!isEmptyStack(S1) || traveller != NULL)
    {
        if (traveller != NULL)
        {
            push(&S1, traveller);
            traveller = traveller->left;
        }
        else
        {
            if (!isEmptyStack(S1))
            {
                traveller = pop(&S1);
                printf("%d ", traveller->data);
                traveller = traveller->right;
            }
            else
            {
                return;
            }
        }
    }
}

// Iterative Function for postOrder Traversal using Stack (REQUIRES DEBUGGING)
void postOrderI(tree T1)
{
    // Initialising a Stack
    stack S1;
    initStack(&S1);
    // Travelling Pointer
    node *traveller = T1;
    // If tree is Empty
    if (!traveller)
    {
        return;
    }
    // PostOrder Traversal
    do
    {
        while (traveller)
        {
            if (traveller->right)
            {
                push(&S1, traveller->right);
            }
            push(&S1, traveller);
            traveller = traveller->left;
        }
        traveller = pop(&S1);
        if (traveller->right && (stackTop(S1) == traveller->right))
        {
            pop(&S1);
            push(&S1, traveller);
            traveller = traveller->right;
        }
        else
        {
            printf("%d ", traveller->data);
            traveller = NULL;
        }
    } while (!isEmptyStack(S1));
}

// Utility Function for Finding the InOrder Successor
node *inOrderSuccessor(tree T1)
{
    node *current = T1->right;

    /*Look for Lowest Element in Right Subtree */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Utility Function for Finding the InOrder Predecessor
node *inOrderPredecessor(tree T1)
{
    node *current = T1->left;

    /*Look for Highest Element in Left Subtree */
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

// Recursive Function to Delete a Node of a BST
node *deleteNode(tree T1, infi data)
{
    // If Tree is Empty --> Return
    if (T1 == NULL)
    {
        return T1;
    }
    // If the data < root --> go to left subtree
    if (data < T1->data)
        T1->left = deleteNode(T1->left, data);
    // If the data > root --> go to right subtree
    else if (data > T1->data)
        T1->right = deleteNode(T1->right, data);
    // if data is same as T1's data --> Delete this Node
    else
    {
        // Node with only one child or no child
        if (T1->left == NULL)
        {
            node *temp = T1->right;
            free(T1);
            return temp;
        }
        else if (T1->right == NULL)
        {
            node *temp = T1->left;
            free(T1);
            return temp;
        }
        // Node with two children --> Get the inorder successor
        node *temp = inOrderSuccessor(T1);

        // Copy the inorder
        // successor's content to this node
        T1->data = temp->data;

        // Delete the inorder successor
        T1->right = deleteNode(T1->right, temp->data);
    }
    return T1;
}

// Recursive Function to Count Number of Internal Nodes in a BST
int internalNodeCount(tree T1)
{
    // If root of tree is NULL or it has no children then the root itself is a Leaf Node
    if (T1 == NULL || (T1->left == NULL && T1->right == NULL))
    {
        return 0;
    }
    // Else return sum of internal node counts of left and right subtrees
    return 1 + internalNodeCount(T1->left) + internalNodeCount(T1->right);
}

// Recursive Function to Calculate number of leaf nodes in a BST
int leafNodeCount(tree T1)
{
    // If root of tree is null --> return 0
    if (T1 == NULL)
    {
        return 0;
    }
    // Else if both children are null --> return 1 (it is a leaf node)
    else if (T1->left == NULL && T1->right == NULL)
    {
        return 1;
    }
    // Else goto left and right subtrees
    else
    {
        return leafNodeCount(T1->left) + leafNodeCount(T1->right);
    }
}

// Recursive Function to Calculate Total Number of Nodes in BST
int nodeCount(tree T1) 
{
    // If root of tree is null --> return 0
    if (T1 == NULL)
    {
        return 0;
    }
     // Else goto left and right subtrees
    return (1 + nodeCount(T1->left) + nodeCount(T1->right)); 
} 

// Function to print BST in 2 Dimension
void print2D(tree T1, int space)
{
    // If root of tree is NULL --> return
    if (T1 == NULL)
    {
        return;
    }
    // Increment the Space and Print the right subtree
    space += 10;
    print2D(T1->right, space);
    printf("\n");

    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }

    printf("%d\n", T1->data);
    print2D(T1->left, space);
}

// Recursive Function for Constructing a BST from a PostOrder Array
tree constructFromPostOrder(infi array[], int *Index, int data, int min, int max, int size)
{
    // If Array is Empty
    if (*Index < 0)
    {
        return NULL;
    }

    node *root = NULL;

    // Creating the root element
    if (data > min && data < max)
    {
        // Allocate memory for root of this subtree and decrement *Index
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
        *Index = *Index - 1;

        // If array is not empty --> Go To left and right subtress
        if (*Index >= 0)
        {
            // All the nodes greater than root will go to right subtree
            root->right = constructFromPostOrder(array, Index, array[*Index],
                                                 data, max, size);

            // Construct the subtree under root
            // All nodes which are in range {min .. key} will go in left
            // subtree, and first such node will be root of left subtree.
            root->left = constructFromPostOrder(array, Index, array[*Index],
                                                min, data, size);
        }
    }
    return root;
}
