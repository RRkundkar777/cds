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

    cout << "Number of unlabelled trees with 5 nodes is " << b.catalan(4) << endl;

    b.bfs_traverse();
    b.insert(8);
    b.insert(9);
    b.bfs_traverse();
    b.remove(3);
    b.bfs_traverse();


    binary_tree b2(3);
    b2.insert(2);
    b2.insert(4);
    b2.insert(1);
    b2.insert(3);
    b2.insert(5);
    b2.bfs_traverse();

    cout << "Is b2 continous? " << b2.isContinous() << endl;

    b2.insert(6);

    cout << "Is b2 foldable? " << b2.isFoldable() << endl;

    binary_tree symm(1);
    symm.insert(2);
    symm.insert(2);
    symm.insert(3);
    symm.insert(4);
    symm.insert(4);
    symm.insert(3);

    cout << "Is symm symmetrical? " << symm.isSymmetric() << endl;
    symm.insert(8);
    cout << "Is symm still symmetrical? " << symm.isSymmetric() << endl;

    
}