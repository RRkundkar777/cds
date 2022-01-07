#include <stdio.h>
#include <stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

// Heap ADT (Include Guard to Handle recursive Inclusion)
#ifndef HEAP_H
#define HEAP_H
#include "heap.h"
#endif

// Functions on Binary Heap

// Function to initialise the heap, allocate the array and set the rear pointer
void initHeap(heap *h1, int size)
{
    (*h1)->size = size;
    (*h1)->array = (infi *)malloc(size * sizeof(infi));
    (*h1)->rear = -1;
}

// Utility Function to get children of a parent node
int leftChild(int index)
{
    return 2 * index + 1;
}

// Utility Function to get children of a parent node
int rightChild(int index)
{
    return 2 * index + 2;
}

// Utility Function to get parent of given node
int parent(int index)
{
    return (index - 1) / 2;
}

// Utility Function to Swap two Elements
void swapH(heap h1, int mindex, int nindex)
{
    infi temp = h1->array[mindex];
    h1->array[mindex] = h1->array[nindex];
    h1->array[nindex] = temp;
    return;
}

// Function to Perform insertion on heap
void insert(heap h1, infi data)
{
    // If heap is allocated --> return
    if (h1->rear == h1->size - 1)
    {
        return;
    }
    // Inserting the element
    h1->rear++;
    h1->array[h1->rear] = data;

    // Fixing the heap property
    int traveller = h1->rear;
    while (traveller > 0 && data > (h1->array[parent(traveller)]))
    {
        swapH(h1, traveller, parent(traveller));
        traveller = parent(traveller);
    }
    return;
}

// Deletion operation in heap
void deleteH(heap h1)
{
    // If array is empty --> return
    if (h1->rear == -1)
    {
        return;
    }
    // Result
    int result = h1->array[0];
    // Pushing the root to the rightmost leaf
    h1->array[0] = h1->array[h1->rear];
    h1->array[h1->rear] = result;
    h1->rear--;

    // Traveller, maxIndex, left and right children
    int i = 0;
    int max = 0;
    int left, right;

    // Restoring the Heap
    while (i < h1->rear)
    {
        debug();
        left = leftChild(i);
        right = rightChild(i);

        if (left > h1->rear)
        {
            return;
        }
        if (right > h1->rear)
        {
            if (h1->array[i] < h1->array[left])
            {
                swapH(h1, i, left);
            }
            return;
        }
        if (h1->array[left] > h1->array[right])
        {
            max = left;
        }
        else
        {
            max = right;
        }
        swapH(h1, i, max);
        i = max;
    }
}

// Recursive Function to Heapify a tree
void heapifyR(heap h1,int index)
{
    int par = parent(index);
    if(h1->array[par] > 0)
    {
        if(h1->array[index] < h1->array[par])
        {
            swapH(h1,par,index);
            heapifyR(h1,par);
        }
    }
   return;
}

void heapifyI(heap h1,int i);
void insert_heapify(heap h1, infi data)
{
    if(h1->rear == h1->size - 1)
    {
        return;
    }
    if(h1->rear < h1->size)
    {
        h1->rear++;
        h1->array[h1->rear] = data;
        heapifyR(h1,h1->rear);
    }
}

// Iterative Approach to Heapify a Binary Tree
void heapifyI(heap h1,int i)
{
    if(h1->rear < 0)
    {
        return;
    }
    i = 0;
    int max;
    int left,right;
    while(i <= h1->rear)
    {
        left = leftChild(i);
        right = rightChild(i);

        if(left > h1->size)
        {
            return;
        }
        if(right > h1->size)
        {
            if(h1->array[i] < h1->array[left])
            {
                swapH(h1,i,left);
            }
            return;
        }
        if(h1->array[left] > h1->array[right])
        {
            max = left;
        }
        else
        {
            max = right;
        }
        swapH(h1,i,max);
        i = max;
    }
    return;
}

int main(int argc, char const *argv[])
{
    heap h1;
    initHeap(&h1, 9);
    insert(h1,7);
    insert(h1,9);
    insert(h1,6);
    insert(h1,10);

    for (int i = 0; i < 9; i++)
    {
        printf("%d ",h1->array[i]);
    }
    
    return 0;
}
