#ifndef sample_H
#define sample_H

#include "../aes-config.h"

class sample
{
public:
    lint *start;
    lint size;
public:
    sample(lint);
    void mergeSort();
};
#endif