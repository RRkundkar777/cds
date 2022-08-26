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

// check if binary tree is continous tree
bool binary_tree::isContinous()
{
    return isContinousUtil(this->root);
}

// check if a binary tree is continous
bool binary_tree::isContinousUtil(bt_node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->right == NULL and root->left == NULL)
    {
        return true;
    }

    if (root->left == NULL)
    {
        return (abs(root->data - root->right->data) == 1) and isContinousUtil(root->right);
    }

    if (root->right == NULL)
    {
        return (abs(root->data - root->left->data) == 1) and isContinousUtil(root->left);
    }

    return (abs(root->data - root->left->data) == 1) and
           (abs(root->data - root->right->data) == 1) and
           isContinousUtil(root->right) and
           isContinousUtil(root->left);
}

// check if tree is foldable or not
bool binary_tree::isFoldable()
{
    if (this->root == NULL)
        return true;

    return isFoldableUtil(root->left, root->right);
}

// check if tree is foldable or not
bool binary_tree::isFoldableUtil(bt_node *node1, bt_node *node2)
{
    if (node1 == NULL and node2 == NULL)
        return true;

    if (node1 == NULL or node2 == NULL)
        return false;

    return isFoldableUtil(node1->right, node2->left) and isFoldableUtil(node1->left, node2->right);
}

#endif