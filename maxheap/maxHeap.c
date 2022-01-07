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
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "maxHeap.h"
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
void swapH(maxHeap *M1, int e1, int e2)
{
    infi temp = M1->array[e1];
    M1->array[e1] = M1->array[e2];
    M1->array[e2] = temp;
}

// Function to initialise minHeap with memory allocation for array
void initMaxHeap(maxHeap *M1, int size)
{
    M1->size = size;
    M1->rear = -1;
    M1->array = (infi *)malloc(sizeof(infi) * size);
}

// Function to insert new data into minHeap
void insert(maxHeap *M1, infi data)
{
    // If heap is full --> return
    if (M1->rear == M1->size - 1)
    {
        return;
    }
    // Inserting an element into heap
    M1->rear++;
    M1->array[M1->rear] = data;
    // Fixing the maxHeap property (if violated)
    int traveller = M1->rear;
    while (traveller > 0 && M1->array[parent(traveller)] < M1->array[traveller])
    {
        swapH(M1, traveller, parent(traveller));
        traveller = parent(traveller);
    }
    return;
}

// Function to replace an existing element by a new element which is less than it
void increaseKey(maxHeap *M1, int index, infi data)
{
    // Replacing an existing element with new element
    M1->array[index] = data;
    // Fixing the maxHeap property (if violated)
    int traveller = M1->rear - 1;
    while (traveller > 0 && M1->array[parent(traveller)] < M1->array[traveller])
    {
        swapH(M1, traveller, parent(traveller));
        traveller = parent(traveller);
    }
    return;
}

// Function to pop the root element from minHeap
infi extractMax(maxHeap *M1)
{
    infi data;
    // If heap is empty --> Return Garbage
    if (M1->rear < 0)
    {
        data = INT_MIN;
        return data;
    }
    // If heap contains exactly one element --> return that element and delete it
    if (M1->rear == 0)
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
    MaxHeapifyI(M1, M1->rear);
    return data;
}

// Function to delete an element at a given index
void deleteKey(maxHeap *M1, int index)
{
    increaseKey(M1, index, INT_MIN);
    extractMax(M1);
}

// Recursive function to heapify a minHeap (Top Down Approach)
void MaxHeapify(maxHeap *M1, int index)
{
    // Parent, Children and minimum index
    int leftChild = left(index);
    int rightChild = right(index);
    int max = index;

    // Check if parent is lesser than its children
    // Also check if parent has children
    if (leftChild < M1->rear && M1->array[leftChild] > M1->array[max])
    {
        // If left > parent --> swap them
        max = leftChild;
    }
    if (rightChild < M1->rear && M1->array[rightChild] > M1->array[max])
    {
        // If right > parent --> swap them
        max = rightChild;
    }
    // Actual Swapping of array elements
    if (max != index)
    {
        swapH(M1, index, max);
        MaxHeapify(M1, max);
    }
    return;
}

// Recursive Function to Heapify a maxHeap (Bottom Up Approach)
void MaxHeapifyR(maxHeap *M1, int index)
{
    int par = parent(index);
    // If Parent is > 0
    if (M1->array[par] > 0)
    {
        // If child is greater than its parent --> Swap them
        if (M1->array[index] > M1->array[par])
        {
            swapH(M1, par, index);
            // Recursively call the maxHeap Function
            MaxHeapifyR(M1, par);
        }
    }
    return;
}

// Iterative Function to heapify a minHeap
void MaxHeapifyI(maxHeap *M1, int index)
{
    // If heap is empty --> return
    if (M1->rear < 0)
    {
        return;
    }
    // Setting the index, minimum, left and right children
    index = 0;
    int max;
    int lefti, righti;
    // While index is in range of heap
    while (index <= M1->rear)
    {
        lefti = left(index);
        righti = right(index);
        // If left child_index is out of range --> return
        if (lefti > M1->rear)
        {
            return;
        }
        // Else if right child_index is out of range --> Examine the left One child
        if (righti > M1->rear)
        {
            // If parent < left child --> swap them
            if (M1->array[index] < M1->array[lefti])
            {
                swapH(M1, index, lefti);
            }
            return;
        }
        /* When both children are present */
        // Select maximum of them
        // If left child > right --> set the max to left
        if (M1->array[lefti] > M1->array[righti])
        {
            max = lefti;
        }
        else
        {
            max = righti;
        }
        // If max > index --> swap them 
        if (M1->array[max] > M1->array[index])
        {
            // Swap the contents of parent
            swapH(M1, index, max);
        }

        // Set the parent as min
        index = max;
    }
    return;
}

// Function to print minHeap in Two Dimensions
void print2D(maxHeap M1, int index, int space)
{
    // If heap is empty
    if (M1.rear == -1)
    {
        return;
    }

    if (index > M1.rear)
    {
        return;
    }

    // Increase distance between levels
    space += 10;

    // Go To Right Child
    print2D(M1, right(index), space);

    // Print the Root
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", M1.array[index]);

    // Go To Left Child
    print2D(M1, left(index), space);

    return;
}