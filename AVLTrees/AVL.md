# Adelson-Velsky and Landis (AVL) Tree

An AVL tree (named after its inventors George-Adelson-Velsky and Evgenii-Landis)
is a self balancing Binary Search Tree.

## Balance Factor in AVL Tree
```
The Balance Factor of an AVL Tree is the difference between heights of left and right subtrees.
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

## Minimum and Maximum number of nodes in AVL Tree
Let H be the height and N be the number of nodes of an AVL Tree then,

N<sub>max</sub> = 2<sup>H + 1</sup> - 1

<code>
N<sub>min</sub>(H = 0) = 1
</code>
<br>
<code>
N<sub>min</sub>(H = 1) = 2
</code>


For H > 1,

<code>
   N<sub>min</sub>(H) = N<sub>min</sub>(H - 1) + N<sub>min</sub>(H - 2) + 1
</code>

## Range of Height of an AVL Tree
The height of an AVL Tree varies as,
    log(N+1) - 1 < H < 1.44 * log(N+2)