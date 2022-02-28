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
    lint linearSearchImproved(lint array[], lint arraySize, lint element);
    lint binarySearchR(lint array[], lint left, lint right, lint element);
    lint binarySearchI(lint array[], lint left, lint right, lint element);
    void insertionSortI(lint array[], lint arraySize);
    void insertionSortR(lint array[], lint arraySize);
    void mergeSort();
};
#endif