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

## Relation between number of nodes and height of binary tree
Let H be the height of binary tree and N be the number of nodes.
Then,

For a given height H the minimum number of nodes is,
N<sub>min</sub> = H + 1

For a given height H the maximum number of nodes is,
N<sub>max</sub> = 2<sup>H + 1</sup> - 1

For given number of nodes N the minimum height of tree is,
H<sub>min</sub> = log<sub>2</sub>(n+1) - 1

For given number of nodes N the maximum height of tree is,
H<sub>max</sub> = n - 1


## Range of height and number of nodes
From the above analysis, we can say that 
<code> log<sub>2</sub>(n+1) <= H <= n - 1 </code>

<code>  H+1 <= N <= 2<sup>(H+1)<sup></code>

## Relation between Degree 0 and Degree 2 nodes
Let n<sub>2</sub> be nodes with degree 2 and n<sub>0</sub> be nodes with degree 0
Then

<code>n<sub>0</sub> = n<sub>2</sub> + 1</code>

## Types of Binary Trees

### Full Binary Tree
In a full binary tree, every node has either 0 or 2 children.
```
In case of a Full Binary Tree, 
    Leaf Nodes = Internal Nodes + 1
```

Maximum number of nodes of full binary tree of height H is  <code> 2<sup>H + 1</sup> - 1  </code><br>
Minimum number of nodes of full binary tree of height H is   <code>2*H + 1 </code>  <br>
Minimum height of the full binary tree of with number of nodes as N is   <code>⌈ log(N+1) ⌉ - 1  </code><br>
Maximum height of the full binary tree of with number of nodes as N is   <code>(N - 1) / 2 </code> <br>


### Complete Binary Tree
Also known as Strict / Proper Binary Tree, it follows: 
   1. Every level is completely filled except possibly the last level.
   2. The last level has its keys as left as possible.

Maximum number of nodes of complete binary tree of height H is  <code>2<sup>H+1</sup> - 1 </code> <br>
Minimum number of nodes of complete binary tree of height H is  <code>2<sup>H</sup> </code> <br>
Minimum height of complete binary tree of with number of nodes as N is  <code>⌈ log(N+1) ⌉ - 1</code> <br>
Maximum height of complete binary tree of with number of nodes as N is  <code>log(N) </code><br>


### Perfect Binary Tree
A perfect binary tree follows:
   1. Every node has either 0 or 2 children.
   2. All the leaf nodes are at same level.


