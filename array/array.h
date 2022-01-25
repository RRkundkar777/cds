/* ADT of array data structure */

#ifndef ARRAY_H
#define ARRAY_H

// Global configurations
#include "../aes-config.h"

// Class declaration
class array
{
public:
    lint *start;
    lint size;
public:
    array(lint);
    void mergeSort();
};
#endif