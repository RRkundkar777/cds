#ifndef ARRAY_H
#define ARRAY_H

#include "../aes-config.h"

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