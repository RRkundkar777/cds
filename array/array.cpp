#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <bits/stdc++.h>
#include <vector>

// -- Debugging Macro --
#define debug() printf("Line number is %d\n", __LINE__);

#define RANGE 255

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
int linearSearch(int array[], int size, int query)
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
int linearSearchImproved(int array[], int size, int query)
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
int binarySearchR(int array[], int low, int high, int query)
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
int binarySearchI(int array[], int low, int high, int query)
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
void displayArray(int A1[], int size)
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
void insertionSort(int array[], int size)
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

// Utility function which searches for position of element in binary insertion sort
int binarySearchUtil(int array[], int item, int low, int high)
{
    // If array has single element return an index accordingly
    if (high <= low)
        return (item > array[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    // If item is already --> there we insert the element next to it
    if (item == array[mid])
        return mid + 1;

    // Else recur through complete array
    if (item > array[mid])
        return binarySearchUtil(array, item, mid + 1, high);

    return binarySearchUtil(array, item, low, mid - 1);
}

// Function to sort an array using binary insertion sort
void binaryInsertionSort(int array[], int size)
{
    int i, j, k, selected;

    // Position of element to be inserted
    int position;

    for (i = 1; i < size; ++i)
    {
        j = i - 1;
        selected = array[i];

        // Find a location at which selected element should be insertes
        position = binarySearchUtil(array, selected, 0, j);

        // Move all elements after that position to create space for selected
        while (j >= position)
        {
            array[j + 1] = array[j];
            j--;
        }
        // Insert the selected element
        array[j + 1] = selected;
    }
    return;
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
        // Find the minimum element in the sub array and swap it with current element
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

// Utility merge Procedure for merge sort
void merge(int array[], int low, int mid, int high)
{
    int num1 = mid - low + 1;
    int num2 = high - mid;

    // Create two sub arrays
    int Left[num1], Right[num2];

    // Copy data to sub arrays Left[] and Right[]
    for (int i = 0; i < num1; i++)
        Left[i] = array[low + i];

    for (int j = 0; j < num2; j++)
        Right[j] = array[mid + 1 + j];

    // Merge the sub arrays back into main array

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = low;

    // Merge both sub arrays
    while (i < num1 && j < num2)
    {
        if (Left[i] <= Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else
        {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left[], if there are any
    while (i < num1)
    {
        array[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right[], if there are any
    while (j < num2)
    {
        array[k] = Right[j];
        j++;
        k++;
    }
}

// Function to implement mergeSort for an array
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return; //returns recursively
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Function to implement bubbleSort for an array
void bubbleSort(int array[], int size)
{
    int i, j;
    // Swapped variable to check for any swaps
    bool swapped;

    // After each iteration of outer for loop,
    // Maximum element of the array will be at last index.
    // Hence after each iteration of i, we need to iterate j only till size - i
    for (i = 0; i < size - 1; i++)
    {
        swapped = false;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then array is already sorted --> break
        if (!swapped)
            break;
    }
}

// Utility function for implementing quicksort
// Partitions the array around the pivot, places pivot at its correct position,
// elements < pivot at left and elements > pivot at right of it.
int partition(int array[], int low, int high)
{
    // pivot element (Last array element)
    int pivot = array[high];
    // Starting index of array of elements < Pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            // Swap the element with element at i
            // (Creates the sub array of elements < pivot)
            i++;
            swap(&array[i], &array[j]);
        }
    }
    // Finally, place the pivot element at the end of the sub array
    swap(&array[i + 1], &array[high]);
    // Return its index
    return (i + 1);
}

// Function to implement quickSort algorithm
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        int part = partition(array, low, high);

        // Separately sort elements before partition and after partition
        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
    }
    else
    {
        return;
    }
}

// To be implemented
// Bubble Sort (R + I)
// Insertion Sort (R + I)
// Selection Sort (R + I)
// Quick Sort (3 Pivots) (R + I)
// Merge Sort (R + I)
// Heap Sort (R + I)
// Radix Sort (R + I)
// Bucket Sort (R + I)
// Counting Sort (R + I)
// Shell Sort (R + I)
// Comb Sort (R + I)

// Function to implement count Sort on array
void countSort(std::vector<int> &arr)
{
    // Finding the Range of inputs
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    // Count and Output Arrays
    std::vector<int> count(range), output(arr.size());

    // Counting the number of same elements in Array
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
    // Summing the elements of Count Array
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    // Count array contains the positions of elements in sorted array
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // Creating the output(Sorted Array)
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    // Copying the Sorted Array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

// BucketSort algorithm for float array
void bucketSort(float array[], int size, int noOfBuckets)
{
    int max = INT_MIN, min = INT_MAX;
    // Finding min and max element of an array.
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    // Creating Individual Buckets
    float range = (max - min) / noOfBuckets;
    std::vector<float> buckets[noOfBuckets];

    // Scatter the Elements in buckets
    for (int i = 0; i < size; i++)
    {
        int bucketIndex = (array[i] - min) / range;
        while(bucketIndex >= noOfBuckets)
        {
            bucketIndex--;
        }
        buckets[bucketIndex].push_back(array[i]);
    }
    // Sort Individual Buckets
    for (int i = 0; i < noOfBuckets; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Concatenate all buckets into array[]
    int index = 0;
    for (int i = 0; i < noOfBuckets; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            array[index++] = buckets[i][j];

    return;
}

// Utility Function To find gap between elements for Comb Sort
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort array using Comb Sort (Improved Bubble Sorting)
void combSort(int array[], int size)
{
    // Initialize gap
    int gap = size;

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < size - gap; i++)
        {
            if (array[i] > array[i + gap])
            {
                swap(&array[i], &array[i + gap]);
                swapped = true;
            }
        }
    }
    return;
}

// Function to sort array using shellSort
int shellSort(int array[], int size)
{
    // Start with a big gap, then reduce the gap
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < size; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = array[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            // put temp (the original a[i]) in its correct location
            array[j] = temp;
        }
    }
    return 0;
}
