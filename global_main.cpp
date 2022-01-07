// Global Main for testing all DSAs concurrently

#include<iostream>

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
