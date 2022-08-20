/* Operations on binary_tree */

#ifndef BINARY_TREE_OPT_H
#define BINARY_TREE_OPT_H

// binary_tree ADT
#include "binary_tree.h"

// Constructor
binary_tree::binary_tree(int val)
{
    root = new bt_node(val);
}
#endif