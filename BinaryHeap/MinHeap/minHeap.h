// Binary MinHeap ADT for multiple data types

// Change the typedef for different data types
typedef int infi;

// Node of an AVL Tree
typedef struct mHeap
{
    int size;
    int rear;
    infi* array;
}mHeap;

//Greater Sizes
typedef long long INT;

// Functions on minHeap

// Function to initialise minHeap with memory allocation for array
void initMinHeap(mHeap *M1, int size);

// Function to insert new data into minHeap
void insert(mHeap *M1, infi data);

// Function to replace an existing element by a new element which is less than it
void decreaseKey(mHeap *M1, int index, infi data);

// Function to pop the root element from minHeap
infi extractMin(mHeap *M1);

// Function to delete an element at a given index 
// void deleteKey(mHeap *M1,int index);

// Recursive function to heapify a minHeap (Top Down Approach)
void MinHeapify(mHeap *M1,int index);

// Recursive Function to Heapify a minHeap (Bottom Up Approach)
void MinHeapifyR(mHeap *M1, int index);

// Iterative Function to heapify a minHeap
void MinHeapifyI(mHeap *M1, int index);

// Function to print minHeap in Two Dimensions
void print2D(mHeap M1, int space,int index);