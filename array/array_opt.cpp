/* Operations on array */

#ifndef ARRAY_OPT_H
#define ARRAY_OPT_H

// System Libraries
#include<iostream>

// Array ADT
#include "array.h"

// Constructor of array
array::array(lint size)
{
    this->start = new lint[size];
    this->size = size;    
}

#endif