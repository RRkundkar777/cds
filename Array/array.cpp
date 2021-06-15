#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// -- Debugging Macro --
#define debug() printf("Line number is %d\n", __LINE__);

// Array ADT
#ifndef ARRAY_H
#define ARRAY_H
#include "array.h"
#endif

/* Basic Array Operations */

// Function to initialise array with total size and allocating memory
void initArray(array *A1, INT size)
{
    A1->total_size = size;
    A1->start = (aDat *)malloc(sizeof(aDat) * size);

    for (int i = 0; i < size; i++)
    {
        A1->start[i] = INT_MIN;
    }
}

// Displaying the array as a list
void displayArray(array A1)
{
    printf("[");
    // Printing the array
    if (A1.total_size)
    {
        //NOTE: PLEASE CHANGE THE FORMAT SPECIFIER FOR DIFFERENT DATA TYPES
        for (int i = 0; i < (A1.total_size); i++)
        {
            printf("%d,", A1.start[i]);
        }
        printf("\b");
    }
    printf("]\n");
    return;
}

// Inserting an element at end of array
void append(array *A1, aDat data)
{
    // Handling Filled Array
    if (A1->start[A1->total_size - 1] != INT_MIN)
    {
        printf("IndexError: Array Overflow Detected\n");
        return;
    }
    for (int i = 0; i < A1->total_size; i++)
    {
        if (A1->start[i] == INT_MIN)
        {
            A1->start[i] = data;
            return;
        }
    }
    return;
}

// Replacing an element at a position
void replace(array *A1, INT position, aDat data)
{
    // Handling Index out of Bounds
    if (position > A1->total_size - 1)
    {
        printf("IndexError: Index out of bounds\n");
        return;
    }
    // Inserting array element
    if (A1->start[position] != INT_MIN)
    {
        A1->start[position] = data;
    }
    return;
}

// Inserting an element at a position by shifting another elements
void insert(array *A1, INT position, aDat data)
{
    // Handling filled Array
    if (A1->start[A1->total_size - 1] != INT_MIN)
    {
        printf("ArrayOverflow: Cannot Insert without replacing\n");
        return;
    }
    //  Handling Index out of Bounds
    if (position > A1->total_size - 1)
    {
        printf("IndexError: Array Index out of Bounds\n");
        return;
    }
    // Shifting the elements to the right
    for (INT i = A1->total_size - 1; i >= position; i--)
    {
        A1->start[i] = A1->start[i - 1];
    }
    // Inserting the element
    A1->start[position] = data;
    return;
}

// Function to delete an element from an array
void eliminate(array *A1, INT position)
{
    //  Handling Index out of Bounds
    if (position > A1->total_size - 1)
    {
        printf("IndexError: Array Index out of Bounds\n");
        return;
    }
    // Shifting the elements to the  left
    for (INT i = position; i < A1->total_size - 1; i++)
    {
        A1->start[i] = A1->start[i + 1];
    }
    return;
}

/* Other Algorithms on array */

// Function for linear search in an array
int linearSearch(int *array, int size, int query)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == query)
        {
            return i;
        }
    }
    return INT_MIN;
}

// Improved linear search algorithm that searches from both left and right at a time
int linearSearchImproved(int *array, int size, int query)
{
    int left = 0;
    int right = size - 1;

    for (left = 0; left <= right;)
    {
        if (array[left] == query)
        {
            return left;
        }

        else if (array[right] == query)
        {
            return right;
        }

        left++;
        right--;
    }
    return INT_MIN;
}

// Recursive Binary Search Algorithm for a sorted array
int binarySearchR(int *array, int low, int high, int query)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == query)
        {
            return mid;
        }

        else if (array[mid] < query)
        {
            return binarySearchR(array, mid + 1, high, query);
        }

        return binarySearchR(array, low, mid - 1, query);
    }

    return INT_MIN;
}

// Iterative Binary Search Algorithm for a sorted array
int binarySearchI(int *array, int low, int high, int query)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == query)
        {
            return mid;
        }
        else if (array[mid] > query)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return INT_MIN;
}

// Function to display array as a list
void displayArray(int *A1, int size)
{
    printf("[");
    // Printing the array
    if (size)
    {

        for (int i = 0; i < (size); i++)
        {
            printf("%d,", A1[i]);
        }
        printf("\b");
    }
    printf("]\n");
    return;
}

// Function to implement insertion sort on an array
void insertionSort(int *array, int size)
{
    // Initialising loop variables and keys
    int i, key, j;

    // Iterating through each element
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        // Compare the current key with its predecessors.
        // Make space for the current key in the sorted array by shifting greater elements to right of it.
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        // Assign this empty space to current key
        array[j + 1] = key;
    }
}

// Recursive insertion sort algorithm on array
void insertionSortR(int array[], int size)
{
    // If array contains single element --> return
    if (size <= 1)
        return;

    // Recursively sort the sub arrays (Top-Down Approach)
    insertionSortR(array, size - 1);

    // Insert last element at its correct position in sorted (sub) array.
    int last = array[size - 1];
    int j = size - 2;

    // Compare the current key with its predecessors.
    // Make space for the current key in the sorted array by shifting greater elements to right of it.
    while (j >= 0 && array[j] > last)
    {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = last;
}

// Utility function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort algorithm for array
void selectionSort(int array[], int size)
{
    // Loop variables and index of minimum element
    int i, j, minIndex;

    // Iterate entire array
    for (int i = 0; i < size; i++)
    {
        // Initially i is minimum element
        minIndex = i;
        // Find the minimum element and swap it with current element
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&array[minIndex], &array[i]);
    }
}

