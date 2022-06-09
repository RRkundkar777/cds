/* Code to test the array data structure */

// Array data structure
#include "array.h"

int main()
{
    vector<lint> v1 = {9,8,6,4,7,2,3,5};

    array a1;
    a1.display_array(v1);
    a1.insertion_sort_recursive(v1,v1.size());
    a1.display_array(v1);
}