/* Testing all data structures concurrently */

// System Libraries
#include<iostream>

// Configuration
#include"aes-config.h"

// Data Structures
#include "array/array.h"

int main(int argc, char const *argv[])
{
    vector<lint> v1{0,1,2,3,9,8,7,6};
    array a1;
    a1.display_array(v1);
    a1.merge_sort(v1,0,v1.size() - 1);
    a1.display_array(v1);
    return 0;
}