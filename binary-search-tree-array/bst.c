#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Binary Search Tree ADT
#include"bst.h"

// Maximum Tree Size
#define MAX_SIZE 100

// Function to initialise BST
void init(tree *T1)
{
    // Allocating an array of max size and Assigning it to the root
    *T1 = (infi*)calloc(MAX_SIZE,sizeof(infi));
    return;
}

// Function to iteratively insert an element into BST
void insertI(tree T1,infi data)
{
    // For accessing values inside tree
    int index = 0;
    // Travelling Pointer
    infi* traveller = T1;

    // While we dont reach the leaf node --> iterate the BST wrt data
    while(index<MAX_SIZE && T1[index] != 0)
    {
        // If root > tree --> go to the left subtree
        if(traveller[index] > data)
        {
            index = (2 * index) + 1;
        }
        // If root < tree --> go to the right subtree
        else if(traveller[index] < data)
        {
            index = (2 * index) + 2;
        }
        // If root == tree --> return bcoz BST does not allow repeated Nodes
        else
        {
            return;
        }
    }
    // If index is greater than array size --> there is no space left for newnode --> Return
    if(index >= MAX_SIZE)
    {
        return;
    }
    // Else --> Add the Node to its right place in the BST
    else
    {
        traveller[index] = data;
    }
    return;
}

// Function to recursively insert an element into BST
void insertR(tree T1,infi data)
{
    static int index = 0;
    // If array is full --> return
    if(index>MAX_SIZE)
    {
        return;
    }
    // If there is an empty node --> Insert at that node
    if(T1[index] == 0)
    {
        T1[index] = data;
    }
    // If data is less than root --> Go To Left Subtree
    else if(T1[index] > data)
    {
        index = 2*index + 1;
        insertR(T1,data);
    }
    // If data is greater than root --> Go To Right Subtree
    else if(T1[index] < data)
    {
        index = 2*index + 2;
        insertR(T1,data);
    }
    // If data is equal to that of root --> Return coz BST does not allow repeated nodes
    else
    {
        return;
    }
}

// Recursive Function for InOrder Traversal
void inOrder(tree T1,int index){
    // If the resulting node is a leaf node --> return
	if(T1[index] ==  0 || index >= MAX_SIZE){
        return;
    }
    // Go To the Left Subtree
	inOrder(T1,2*index + 1);
    // Change the format specifier for multiple data types
	printf("%d ", T1[index]);
    // Go To the Right Subtree
	inOrder(T1, 2*index + 2);
	return;
}

// Recursive Function for PreOrder Traversal
void preOrder(tree T1,int index){
    // If the resulting node is a leaf node --> return
	if(T1[index] ==  0 || index >= MAX_SIZE){
        return;
    }

    // Change the format specifier for multiple data types
	printf("%d ", T1[index]);
    // Go To the Left Subtree
	preOrder(T1,2*index + 1);
    // Go To the Right Subtree
	preOrder(T1, 2*index + 2);
	return;
}

// Recursive Function for PostOrder Traversal
void postOrder(tree T1,int index){
    // If the resulting node is a leaf node --> return
	if(T1[index] ==  0 || index >= MAX_SIZE){
        return;
    }
    // Go To the Left Subtree
	postOrder(T1,2*index + 1);
    // Go To the Right Subtree
	postOrder(T1, 2*index + 2);
    // Change the format specifier for multiple data types
	printf("%d ", T1[index]);
	return;
}

// Function to iteratively Search an element of BST
int Isearch(tree T1,infi data)
{
    // For accessing values inside tree
    int index = 0;
    // Travelling Pointer
    infi* traveller = T1;

    // While we dont reach the leaf node --> iterate wrt data
    while(index<MAX_SIZE && T1[index] != 0)
    {
        // If root > tree --> go to the left subtree
        if(traveller[index] > data)
        {
            index = (2 * index) + 1;
        }
        // If root < tree --> go to the right subtree
        else if(traveller[index] < data)
        {
            index = (2 * index) + 2;
        }
        // If root == tree --> then it must be equal to the element we are finding (return 1t)
        else
        {
            return 1;
        }
    }

    // If element not found --> Return 0
    return 0;
}

// Function to print BST in 2 Dimension
void print2D(tree T1,int index,int space)
{
    if(T1[index] == 0)
    {
        return;
    }
    space += 10;
    print2D(T1,2*index+2,space);
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", T1[index]);
    print2D(T1,2*index+1,space); 
}