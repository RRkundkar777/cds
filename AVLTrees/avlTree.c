#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

// AVL Tree ADT (Include Guard to Handle recursive Inclusion)
#ifndef AVLTREE_H
#define AVLTREE_H
#include "avlTree.h"
#endif

// Function to initialise the AVL Tree
void initAVL(avltree *T1)
{
    *T1 = NULL;
}

// Utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Utility Function to create a  newnode
Anode *createNode(int data)
{
    // Allocating memory
    Anode *newnode = (Anode *)malloc(sizeof(Anode));
    // Assigning data to the node
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    // Assigning height to the newnode
    newnode->height = 1;

    return newnode;
}

// Utility function to get the height of the tree
int height(Anode *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return Node->height;
}

// Function to get balance factor of a node
int getBalance(Anode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Utility function to find inOrder Successor of a node
Anode *inOrderSuccessor(Anode *node)
{
	Anode *current = node->right;

	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

// Function to Right Rotate Tree
Anode *rightRotate(Anode *root)
{
    Anode *leftChild = root->left;
    Anode *rightGrandChild = leftChild->right;

    // Performing the rotation
    leftChild->right = root;
    root->left = rightGrandChild;

    // Setting the Heights
    root->height = max(height(root->left), height(root->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

    return leftChild;
}

// Function to Left Rotate Tree
Anode *leftRotate(Anode *root)
{
    Anode *rightChild = root->right;
    Anode *leftGrandChild = rightChild->left;

    // Performing the rotation
    rightChild->left = root;
    root->right = leftGrandChild;

    // Setting the Heights
    root->height = max(height(root->left), height(root->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

    return rightChild;
}

// Recursive function to insert a node into AVL Tree
Anode *insertR(avltree T1, infi data)
{
    // If Tree is empty, simply append that node in it
    if (T1 == NULL)
    {
        return createNode(data);
    }
    // If data < T1 --> Go To left subtree
    // Recursion ensures that heights are updated properly
    // It also provides backtracking so that we dont have to explicitly visit parent nodes for imbalance.
    if (data < T1->data)
    {
        T1->left = insertR(T1->left, data);
    }
    // If data > T1 --> Go To right subtree
    else if (data > T1->data)
    {
        T1->right = insertR(T1->right, data);
    }
    // Else if data == data of existing node, reject it
    else
    {
        return T1;
    }

    // Update the tree height
    T1->height = 1 + max(height(T1->left), height(T1->right));

    // Check for imbalance
    int balance = getBalance(T1);

    // Handling Cases of Imbalance

    // Left Left Case
    if (balance > 1 && data < T1->data)
    {
        return rightRotate(T1);
    }

    // Right Right Case
    if (balance < -1 && data > T1->right->data)
    {
        return leftRotate(T1);
    }
    // Left Right Case
    if (balance > 1 && data > T1->left->data)
    {
        T1->left = leftRotate(T1->left);
        return rightRotate(T1);
    }

    // Right Left Case
    if (balance < -1 && data < T1->right->data)
    {
        T1->right = rightRotate(T1->right);
        return leftRotate(T1);
    }

    return T1;
}

// Recursive function to delete a node
Anode *deleteNode(Anode *T1, int data)
{
    // If tree is empty
    if (T1 == NULL)
    {
        return T1;
    }
    // If data < T1 go to left subtree
    // Recursion ensures that heights are updated properly
    // It also provides backtracking so that we dont have to explicitly visit parent nodes for imbalance.
    if (data < T1->data)
    {
        T1->left = deleteNode(T1->left, data);
    }
    // If data > T1 go to right subtree
    else if (data > T1->data)
    {
        T1->right = deleteNode(T1->right, data);
    }
    // Actual Code for Deletion
    else
    {
        // If node has one or no child
        if ((T1->left == NULL) || (T1->right == NULL))
        {
            // Temp = left or right depending on which one is not null
            Anode *temp = T1->left ? T1->left : T1->right;

            // If both children are NULL --> Set T1 as Null
            if (temp == NULL)
            {
                temp = T1;
                T1 = NULL;
            }
            // Else give T1s place to its only child
            else
            {
                *T1 = *temp;
            }
            // Free the Node
            free(temp);
        }
        // Node with two children
        else
        {
            // Find the InOrder Successor of T1
            // This will serve as the new parent of both children
            Anode *temp = inOrderSuccessor(T1);

            T1->data = temp->data;

            // Remove the node (InOrder Successor)
            T1->right = deleteNode(T1->right, temp->data);
        }
    }

    // If tree is NULL after deletion --> Simply Return It
    if (T1 == NULL)
    {
        return T1;
    }

    // Update the Height of the Tree
    T1->height = 1 + max(height(T1->left), height(T1->right));

    // Check for imbalance
    int balance = getBalance(T1);

    // Left Left Case
    if (balance > 1 && getBalance(T1->left) >= 0)
    {
        return rightRotate(T1);
    }

    // Left Right Case
    if (balance > 1 && getBalance(T1->left) < 0)
    {
        T1->left = leftRotate(T1->left);
        return rightRotate(T1);
    }

    // Right Right Case
    if (balance < -1 && getBalance(T1->right) <= 0)
    {
        return leftRotate(T1);
    }

    // Right Left Case
    if (balance < -1 && getBalance(T1->right) > 0)
    {
        T1->right = rightRotate(T1->right);
        return leftRotate(T1);
    }

    // Return the Tree
    return T1;
}

// Function to print the avltree diagram
void print2D(avltree T1, int space)
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
