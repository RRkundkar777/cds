// Std Libraries
#include<limits.h>

// Maximum limit of array size
#define LIM 9223372036854775807

// Makes life easy
#define TMP template <typename Data>

// Array Class
template <typename Data>
class Array
{
    // Array contents
public:
    Data *start;
    long long size;

    // Array methods and operations
public:
    Array(long long);

    Data atIndex(long long int);
    Data atEnd();
    Data atStart();
    void display();

    bool setIndex(long long int,Data key);
    void insert(long long,Data);
    Data replaceAt(long long,Data);

    Data pop(long long);
    void erase(long long);

    // Utility and To Be wrapped functions
private:
    long long binarySearchI(Data,long long low = 0,long long high = 0);
    long long binarySearchR(Data,long long low = 0,long long high = 0);
    long long binarySearchUtil(Data,long long,long long);

    void swap(long long,long long);
    void simpleInsertionSort();
    void binaryInsertionSort();
    void recursiveInsertionSort(long long size);

    void merge(long long,long long,long long);

    // Algorithms on Array
    // Wrapper functions
public:
    long long linearSearch(Data);
    long long bSearch(Data,long long low = 0,long long high = 0,bool recur = true);

    void bubbleSort();
    void insertionSort(bool fast = true,bool recur = false);
    void selectionSort();
    void mergeSort(long long low = 0,long long high = 0,bool full = true);
};

// Merge procedure of MergeSort Algorithm
TMP
void Array<Data>::merge(long long low,long long mid,long long high)
{
    long long subArr1 = mid - low + 1;
    long long subArr2 = high - mid;

    // Create two sub arrays
    Array<Data> Left(subArr1);
    Array<Data> Right(subArr2);

    // Copy data to sub arrays Left[] and Right[]
    for (int i = 0; i < subArr1; i++)
        Left.setIndex(i,this->start[low + i]);

    for (int j = 0; j < subArr2; j++)
        Right.setIndex(j,this->start[mid + 1 + j]);

    // Merge the sub arrays back into main array

    // Initial index of first subarray
    long long subIndex1 = 0;

    // Initial index of second subarray
    long long subIndex2 = 0;

    // Initial index of merged subarray
    long long mainIndex = low;

    // Merge both sub arrays
    while (subIndex1 < subArr1 && subIndex2 < subArr2)
    {
        if (Left.atIndex(subIndex1) <= Right.atIndex(subIndex2))
        {
            this->setIndex(mainIndex,Left.atIndex(subIndex1));
            subIndex1++;
        }
        else
        {
            this->setIndex(mainIndex,Right.atIndex(subIndex2));
            subIndex2++;
        }
        mainIndex++;
    }

    // Copy the remaining elements of Left[], if there are any
    while (subIndex1 < subArr1)
    {
        this->setIndex(mainIndex,Left.atIndex(subIndex1));
        subIndex1++;
        mainIndex++;
    }

    // Copy the remaining elements of Right[], if there are any
    while (subIndex2 < subArr2)
    {
        this->setIndex(mainIndex,Right.atIndex(subIndex2));
        subIndex2++;
        mainIndex++;
    }
}

// Function to implement mergeSort on a given array
TMP
void Array<Data>::mergeSort(long long low, long long high,bool full)
{
    // If full array has to be sorted
    if(full)
    {
        if(!high)
        {
            high = this->size;
        }
    }

    // If array has only one element --> return
    if(low >= high)
    {
        return;
    }
    // Split into subArrays and sort each subArray
    long long mid = low + (high - low)/2;
    mergeSort(low,mid,false);
    mergeSort(mid + 1,high,false);

    // Merge the Sorted SubArrays
    merge(low,mid,high);
}