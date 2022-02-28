/* ADT of array data structure */

#ifndef ARRAY_H
#define ARRAY_H

// Global configurations
#include "../aes-config.h"

// Class declaration
class array
{
public:
    lint linearSearch(lint array[], lint arraySize, lint element);
    void mergeSort();
};
#endif