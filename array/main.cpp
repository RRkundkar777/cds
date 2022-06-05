/* Code to test the array data structure */

// System Libraries
#include <iostream>

// Array data structure
#include "array.h"

int main()
{
    long long py = 4;
    array a1;
    lint arr[] = {9,8,7,4,5,6,2,1};

    // Linear search test
    std::cout << a1.linearSearch(arr,8,899) << std::endl;
    std::cout << a1.linearSearchImproved(arr,8,4) << std::endl;
}