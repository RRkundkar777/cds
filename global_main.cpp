/* Testing all data structures concurrently */

// System Libraries
#include<iostream>

// Configuration
#include"aes-config.h"

// Data Structures
#include "aa-sample-dsa/sample.h"
#include "array/array.h"

int main(int argc, char const *argv[])
{
    array a1(34);
    a1.mergeSort();

    sample s1(56);
    s1.mergeSort();
    return 0;
}