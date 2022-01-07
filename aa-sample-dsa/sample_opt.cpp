#ifndef sample_OPT_H
#define sample_OPT_H

#include "sample.h"
#include<iostream>

sample::sample(lint size)
{
    this->start = new lint[size];
    this->size = size;    
}

#endif