# Tree Terminology
Before we get into the implementation of Binary Search Tree, let us see some important terminology
related to trees.

- A tree is a collection of nodes and edges.
- A tree grows downward.

## A tree data structure
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/binary-tree-to-DLL.png">

1. Root: The root is the first node of tree (1 in above diagram).
2. Subtree: A subtree is a part of the tree.
3. Parent: The node which has a node at its edge (in the diagram, 4 is parent of 8 and 9).
4. Child: The node which has some parent (in the diagram 8 is child of 4).
5. Sibling: Two nodes which have the same parent are called siblings. (8 and 9 are siblings).
6. Ancestor: An ancestor of any node 'A' is any other node 'B' on the path from the 'A' to root.
    Ex. 3 is ancestor of 13 but 2 is NOT AN ancestor of 13 since 2 doesnt lie on the path.
7. Descendant: The node 'A' in above definition is descendant of node 'B'
    Ex. 10 is descendant of 2 bcoz 2 is ancestor of 10.
8. Leaf node: The node with children is called a leaf node (14 is a leaf node).
9. Non Leaf/ Internal Node: Node with atleast one child.

## Level of a node
```
Level of a node 'A' is the number of parent nodes from 'A' to the root of the tree.
    Ex. Level of 13 is 3 (parent nodes: 6,3 and 1)
Note that root is at level 0.
```
## Height of a Tree
```
Height of a Tree is defined as the maximum level of any node in a tree.
    Ex. Height of given tree is 3.
```
## Degree of a node
```
Degree of a node is defined as number of children of that node.
    Ex. (3 has degree 2, 14 has degree 0, 6 has degree 1)
```
## Degree of a Tree
```
The maximum degree of node. 
```