// Binary MaxHeap ADT for multiple data types

// Change the typedef for different data types
typedef int infi;

// Node of a MaxHeap
typedef struct maxHeap
{
    int size;
    int rear;
    infi* array;
}maxHeap;

//Greater Sizes
typedef long long INT;

// Functions on maxHeap

// Function to initialise maxHeap  with memory allocation for array
void initMaxHeap(maxHeap *M1, int size);

// Function to insert new data into maxHeap
void insert(maxHeap *M1, infi data);

// Function to replace an existing element by a new element which is greater than it
void decreaseKey(maxHeap *M1, int index, infi data);

// Function to pop the root element from maxHeap
infi extractMax(maxHeap *M1);

// Function to delete an element at a given index 
// void deleteKey(maxHeap *M1,int index);

// Recursive function to heapify a maxHeap (Top Down Approach)
void MaxHeapify(maxHeap *M1,int index);

// Recursive Function to Heapify a maxHeap  (Bottom Up Approach)
void MaxHeapifyR(maxHeap *M1, int index);

// Iterative Function to heapify a maxHeap 
void MaxHeapifyI(maxHeap *M1, int index);

// Function to print maxHeap in Two Dimensions
void print2D(maxHeap M1, int space,int index);