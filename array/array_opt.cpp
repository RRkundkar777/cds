#ifndef ARRAY_OPT_H
#define ARRAY_OPT_H

#include "array.h"
#include<iostream>

array::array(lint size)
{
    this->start = new lint[size];
    this->size = size;    
}

#endif