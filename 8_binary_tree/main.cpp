/* Code to test the binary_tree data structure */

// binary_tree data structure
#include "binary_tree.h"

int main()
{
    binary_tree b(1);
 
    b.root->left = new bt_node(2);
    b.root->right = new bt_node(3);

    b.root->left->left = new bt_node(4);
    b.root->left->right = new bt_node(5);

    b.root->right->left = new bt_node(6);
    b.root->right->right = new bt_node(7);

    b.bfs_traverse();
    b.dfs_traverse(0);
    b.dfs_traverse(1);
    b.dfs_traverse(2);
}