# Adelson-Velsky and Landis (AVL) Tree

An AVL tree (named after its inventors George-Adelson-Velsky and Evgenii-Landis)
is a self balancing Binary Search Tree.

## Balance Factor in AVL Tree
```
The Balance Factor of an AVL Tree is the difference between heights of left and right
subtrees.
```
B = height(leftSubTree) - height(RightSubTree)

## Eligibility Criteria
For a Binary Tree to be an AVL Tree:
```
1. The Tree must satisfy all criteria of a BST.
2. The absolute difference between the heights of left and right subtrees cannot be more than one.
3. That is modulus of Balance Factor cannot be more than one.
```

In order to maintain this properties, an implementation of an AVL will include an algorithm to rebalance the tree whenever an insertion or deletion is performed.