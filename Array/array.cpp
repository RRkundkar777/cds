#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

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
        if(A1->start[i] == INT_MIN)
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
    if(A1->start[position] != INT_MIN)
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
        A1->start[i] = A1->start[i+1];
    }
    return;
}

/* Other Algorithms on array */

// Function for linear search in an array
int linearSearch(int *array,int size,int query)
{
    for (int i = 0; i < size; i++)
    {
        if(array[i] == query)
        {
            return i;
        }
    }
    return INT_MIN;
}

// Improved linear search algorithm that searches from both left and right at a time
int linearSearchImproved(int *array,int size,int query)
{
    int left = 0;
    int right = size - 1;

    for (left = 0; left <= right;)
    {
        if(array[left] == query)
        {
            return left;
        }

        else if(array[right] == query)
        {
            return right;
        }

        left++;
        right--;
    }
    return INT_MIN;
}

