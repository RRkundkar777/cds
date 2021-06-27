/*
Title: Array ADT
Author: Rushikesh (@RRkundkar777)
Description: Array as an abstract data type.
*/

// Change the typedef for accomodating multiple data type
typedef int aDat;

// Greater Sizes
typedef long long INT;

// The Array ADT
typedef struct array
{
    INT total_size;
    aDat *start;
} array;

/* Basic Array Operations */

// Function to initialise array with total size and allocating memory
void initArray(array *A1, INT size);

// Displaying the array as a list
void displayArray(array A1);

// Inserting an element at end of array
void append(array *A1, aDat data);

// Replacing an element at a position
void replace(array *A1, INT position, aDat data);

// Inserting an element at a position by shifting another elements
void insert(array *A1, INT position, aDat data);

// Function to delete an element from an array by left shifting other elements
void eliminate(array *A1, INT position);

/* Other Algorithms on array */

// Function for linear search in an array
int linearSearch(int *array, int size, int query);

// Improved linear search algorithm that searches from both left and right at a time
int linearSearchImproved(int *array, int size, int query);

// Recursive Binary Search Algorithm for a sorted array
int binarySearchR(int *array, int low, int high, int query);

// Iterative Binary Search Algorithm for a sorted array
int binarySearchI(int *array, int low, int high, int query);

// Function to implement insertion sort on an array
void insertionSort(int *array, int size);

// Function to display array as a list
void displayArray(int *A1, int size);

// Recursive insertion sort algorithm on array
void insertionSortR(int array[], int size);

// Function to sort an array using binary insertion sort
void binaryInsertionSort(int array[], int size);

// Selection sort algorithm for array
void selectionSort(int array[], int size);

// Function to implement MergeSort Algorithm for array
void mergeSort(int array[], int low, int high);

// Function to implement bubbleSort for an array
void bubbleSort(int array[], int size);

// Function to implement quickSort for an array
void quickSort(int array[], int low, int high);

// Function to implement count Sort on array
void countSort(std::vector <int> &arr);

// BucketSort algorithm for float array (Does SegFault)
void bucketSort(float array[], int size, int noOfBuckets);

// Function to sort array using Comb Sort (Improved Bubble Sorting)
void combSort(int array[], int size);

// Function to sort array using shellSort (Understanding Needed)
int shellSort(int array[], int size);