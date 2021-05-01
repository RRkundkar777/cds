# Binary Tree

Since a BST is a special binary tree, it is relevant to study Binary Tree

## What is a Binary Tree?
```
A binary tree is a tree having degree atmost 2.
That is, every node in binary tree can have atmost 2 children.
```
## Left and Right Skewed Binary Trees
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20191014012656/skewed-trees-1024x421.png">

## Number of Binary Trees that can be formed with n nodes

### Case1: Nodes are identical
If the nodes are identical, the number of binary trees that can be formed are:
    <sup>2n</sup>C<sub>n</sub> / (n+1)

#### Another Formula
```T(0) = 1
T(1) = 1
T(2) = 2
T(3) = 5
T(4) = 14
T(5) = 42
```

In general, 
         `T(n) = sumOf(T(i - 1) * T(n - i))` 
where i varies from 1 to n.

### Case2: Nodes are different
If the nodes are NOT identical, the number of binary trees that can be formed are:
    <sup>2n</sup>C<sub>n</sub> * n! / (n+1)



