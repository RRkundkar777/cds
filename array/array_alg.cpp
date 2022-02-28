/* Array algorithms */

#ifndef ARRAY_ALG_H
#define ARRAY_ALG_H

// System libraries
#include <iostream>
#include <climits>

// Array ADT
#include "array.h"

// Linear search algorithm
lint array::linearSearch(lint array[], lint arraySize, lint element)
{
    int index;
    for (index = 0; index < arraySize; index++)
        if (array[index] == element)
            return index;
    return INT_MIN;
}

// Improved linear search algorithm
lint array::linearSearchImproved(lint array[], lint arraySize, lint element)
{
    lint left = 0;
    lint length = arraySize;
    lint position = INT_MIN;
    lint right = length - 1;

    // Run loop from 0 to right
    for (left = 0; left <= right;)
    {
        // If element is found at left
        if (array[left] == element)
        {
            position = left;
            break;
        }
        // If element is found at right
        if (array[right] == element)
        {
            position = right;
            break;
        }
        left++;
        right--;
    }

    // Return the index
    return position;
}

// Recursive Binary search algorithm
lint array::binarySearchR(lint array[], lint left, lint right, lint element)
{
    // If array has atleast one element
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (array[mid] == element)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (array[mid] > element)
            return binarySearchR(array, left, mid - 1, element);

        // Else the element can only be present
        // in right subarray
        return binarySearchR(array, mid + 1, right, element);
    }

    // When element is not present in array
    return INT_MIN;
}

// Iterative binary search algorithm
lint array::binarySearchI(lint array[], lint left, lint right, lint element)
{
    // While array still has atleast one element
    while (left <= right)
    {
        lint mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (array[mid] == element)
            return mid;

        // If x greater, ignore left half
        if (array[mid] < element)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // if we reach here, then element was not present
    return INT_MIN;
}

// Iterative insertion sort algorithm
void array::insertionSortI(lint array[], lint arraySize)
{
    // Key and iterators
    lint iter, key, sortedIter;
    // Iterate the complete array
    for (iter = 1; iter < arraySize; iter++)
    {
        key = array[iter];
        sortedIter = iter - 1;

        // find the right space to insert current key
        while (sortedIter >= 0 && array[sortedIter] > key)
        {
            array[sortedIter + 1] = array[sortedIter];
            sortedIter = sortedIter - 1;
        }
        // Insert the key into its rightful position
        array[sortedIter + 1] = key;
    }
}

// Recursive insertion sort
void array::insertionSortR(lint array[], lint arraySize)
{
    // If array contains only one element
    if (arraySize <= 1)
    {
        return;
    }

    // Sort first n-1 elements
    insertionSortR(array, arraySize - 1);

    // Insert last element at its correct position in sorted array.
    lint last = array[arraySize - 1];
    int j = arraySize - 2;

    // find the right space to insert current key
    while (j >= 0 && array[j] > last)
    {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = last;
}

// MergeSort algorithm
void array::mergeSort()
{
    std::cout << "Welcome to merge sort" << std::endl;
}

#endif