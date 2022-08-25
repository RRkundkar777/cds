/* Binary Tree algorithms */

#ifndef BINARY_TREE_ALG_H
#define BINARY_TREE_ALG_H

// Binary Tree ADT
#include "binary_tree.h"

// How many unlabelled binary trees with N nodes
long binary_tree::catalan(int num)
{
    if (num <= 1)
        return 1;

    long result = 0;

    for (int i = 0; i < num; i++)
    {
        result += catalan(i) * catalan(num - i - 1);
    }

    return result;
}

#endif