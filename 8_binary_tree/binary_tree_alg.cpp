/* Binary Tree algorithms */

#ifndef BINARY_TREE_ALG_H
#define BINARY_TREE_ALG_H

// Binary Tree ADT
#include "binary_tree.h"

// Breadth first traversal
void binary_tree::bfs_traverse()
{
    queue<bt_node*> q;
    q.push(this->root);
    bt_node *traveller;

    while(!q.empty()){
        traveller = q.front();
        q.pop();

        cout << traveller->data << " ";
        
        if(traveller->left != NULL)
            q.push(traveller->left);
        if(traveller->right != NULL)
            q.push(traveller->right);
    }
    cout << endl;
}

// Depth first traversal
void binary_tree::dfs_traverse(int route)
{
    switch(route){
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
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// PostOrder
void binary_tree::postorder(bt_node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// InOrder
void binary_tree::inorder(bt_node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

#endif