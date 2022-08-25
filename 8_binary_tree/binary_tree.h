/* ADT of binary_tree data structure */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Global configurations
#include "../aes-config.h"

// System Libraries
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>

// Class declaration
class bt_node
{
public:
    int data;
    bt_node *left;
    bt_node *right;

    bt_node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// binary tree
class binary_tree
{
public:
    bt_node *root;

public:
    binary_tree(int val);
    void bfs_traverse();
    void dfs_traverse(int route);
    long catalan(int num);
    void insert(int value);
    void remove(int value);
    void trim(bt_node *d_node);

private:
    void preorder(bt_node *root);
    void inorder(bt_node *root);
    void postorder(bt_node *root);
};

#endif