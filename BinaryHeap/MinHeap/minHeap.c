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

// Binary MinHeap ADT (Include Guard to Handle recursive Inclusion)
#ifndef MINHEAP_H
#define MINHEAP_H
#include "minHeap.h"
#endif

// Utility Function to get left child of a node
int left(int i)
{
    return 2 * i + 1;
}

// Utility Function to get right child of a node
int right(int i)
{
    return 2 * i + 2;
}

// Utility Function to get parent of a node
int parent(int i)
{
    return (i - 1) / 2;
}

// Utility Function to swap array elements
void swapH(mHeap *M1, int e1, int e2)
{
    infi temp = M1->array[e1];
    M1->array[e1] = M1->array[e2];
    M1->array[e2] = temp;
}

// Function to initialise minHeap with memory allocation for array
void initMinHeap(mHeap *M1, int size)
{
    M1->size = size;
    M1->rear = -1;
    M1->array = (infi *)malloc(sizeof(infi) * size);
}

// Function to insert new data into minHeap
void insert(mHeap *M1, infi data)
{
    // If heap is full --> return
    if (M1->rear == M1->size - 1)
    {
        return;
    }
    // Inserting an element into heap
    M1->rear++;
    M1->array[M1->rear] = data;
    // Fixing the minHeap property (if violated)
    int traveller = M1->rear;
    while (traveller > 0 && M1->array[parent(traveller)] > M1->array[traveller])
    {
        swapH(M1, traveller, parent(traveller));
        traveller = parent(traveller);
    }
    return;
}

// Function to replace an existing element by a new element which is less than it
void decreaseKey(mHeap *M1, int index, infi data)
{
    // Replacing an existing element with new element
    M1->array[index] = data;
    // Fixing the minHeap property (if violated)
    int traveller = M1->rear - 1;
    while (traveller > 0 && M1->array[parent(traveller)] > M1->array[traveller])
    {
        swapH(M1, traveller, parent(traveller));
        traveller = parent(traveller);
    }
    return;
}

// Function to pop the root element from minHeap
infi extractMin(mHeap *M1)
{
    infi data;
    // If heap is empty --> Return Garbage
    if(M1->rear < 0)
    {
        data = INT_MIN;
        return data;
    }
    // If heap contains exactly one element --> return that element and delete it
    if(M1->rear == 0)
    {
        data = M1->array[M1->rear];
        M1->rear--;
        return data;
    }
    // Removing the root from heap
    data = M1->array[0];
    // Making the rightmost element as newRoot
    M1->array[0] = M1->array[M1->rear];
    M1->rear--;
    // Fixing the minHeap property (if violated)
    MinHeapify(M1,0);
    return data;
}

// Function to delete an element at a given index 
void deleteKey(mHeap *M1,int index)
{
    decreaseKey(M1,index,INT_MIN);
    extractMin(M1);
}

// Recursive function to heapify a minHeap 
void MinHeapify(mHeap *M1,int index)
{
    // Parent, Children and minimum index
    int leftChild = left(index);
    int rightChild = right(index);
    int min = index ;

    // Check if parent is greater than its children 
    // Also check if parent has children
    if (leftChild < M1->rear && M1->array[leftChild] <  M1->array[min])
    {
        // If left < parent --> swap them
        min = leftChild;
    }
    if (rightChild < M1->rear && M1->array[rightChild] <  M1->array[min])
    {
        // If right < parent --> swap them
        min = rightChild;
    }
    // Actual Swapping of array elements
    if (min != index)
    {
        swapH(M1,index, min);
        MinHeapify(M1,min);
    }
    return;
}

// Function to print minHeap in Two Dimensions
void print2D(mHeap M1, int index,int space)
{
    // If heap is empty
    if (M1.rear == -1)
    {
        return;
    }

    if(index > M1.rear)
    {
        return;
    }
  
    // Increase distance between levels
    space += 10;
  
    // Go To Right Child
    print2D(M1,right(index), space);
  
    // Print the Root
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", M1.array[index]);
  
    // Go To Left Child
    print2D(M1,left(index), space);

    return;
}