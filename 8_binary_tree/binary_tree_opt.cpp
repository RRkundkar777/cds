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

// Breadth first traversal
void binary_tree::bfs_traverse()
{
    queue<bt_node *> q;
    q.push(this->root);
    bt_node *traveller;

    while (!q.empty())
    {
        traveller = q.front();
        q.pop();

        cout << traveller->data << " ";

        if (traveller->left != NULL)
            q.push(traveller->left);
        if (traveller->right != NULL)
            q.push(traveller->right);
    }
    cout << endl;
}

// Depth first traversal
void binary_tree::dfs_traverse(int route)
{
    switch (route)
    {
    case 0:
        preorder(this->root);
        cout << endl;
        break;
    case 1:
        inorder(this->root);
        cout << endl;
        break;
    case 2:
        postorder(this->root);
        cout << endl;
        break;
    default:
        return;
    }
}

// PreOrder
void binary_tree::preorder(bt_node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// PostOrder
void binary_tree::postorder(bt_node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// InOrder
void binary_tree::inorder(bt_node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Level order insertion (left leaning)
void binary_tree::insert(int value)
{
    if (this->root == NULL)
    {
        this->root = new bt_node(value);
        return;
    }

    queue<bt_node *> q;
    q.push(this->root);

    while (!q.empty())
    {
        bt_node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = new bt_node(value);
            return;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL)
        {
            temp->right = new bt_node(value);
            return;
        }
        else
            q.push(temp->right);
    }
}

// Remove a node by (replace it by deepest node, delete the deepest node)
void binary_tree::remove(int value)
{
    if (this->root == NULL)
        return;

    if (root->left == NULL and root->right == NULL)
    {
        if (root->data == value)
        {
            delete root;
            root = NULL;
        }
        return;
    }

    queue<bt_node *> q;
    q.push(root);
    bt_node *key;
    bt_node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == value)
        {
            key = temp;
        }

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key != NULL)
    {
        int x = temp->data;
        this->trim(temp);
        key->data = x;
    }
    return;
}

// Remove the deepest node from the tree
void binary_tree::trim(bt_node *d_node)
{
    queue<bt_node *> q;
    q.push(this->root);

    // Do level order traversal until last node
    struct bt_node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

#endif