Terminlogy
    A tree is a non-linear data structure.
    It is ideal for representing hierarchial data.
    Tree is made up of nodes and edges.
    A tree with n nodes has n-1 edges.

    1. Root --> Topmost node of tree
    2. Parent --> Node which connects with child
    3. Child --> Node which is connected by a parent
    4. Leaf/External Node --> Node which has no child 
    5. Internal Node --> Nodes with atleast one child 
    6. Depth --> Depth of a node is defined as number of edges from root to that node
    7. Height --> Number of edges from a node to the deepest Leaf
    8. Siblings --> Nodes belonging to the same parent 
    9. Ancestors/Descendants --> Ancestors: Move upside the tree from a node. 
                                 Descendants: Move downside the tree from a node.

    10. Degree --> Degree of a node is defined as the number of direct children the node has.
    11. Degree --> Degree of a tree is the highest degree of a node present in a tree.

Binary Tree 
    A tree having degree atmost two.
    A tree in which each node has atmost two children.
    Tree of degree 2 --> Nodes can have 0,1 or 2 children.


Types of Binary Trees
    1. Full or Strict Binary Tree --> A tree having nodes with either 0 or 2 children.
    2. Perfect Binary Tree --> A tree having nodes with exactly 2 children and its all leaf nodes are on same level.
    3. Complete Binary Tree --> A tree in which all levels are completely filled (All parents have two children) except possibly the last level and last level is left aligned (having its keys as left as possible).
    4. Degenerate Tree --> A tree in which every parent has only one child.
    5. Skew Tree --> A Degenerate tree having all the children in either left or right direction.



Array Representation of Binary Tree
    In array operation, the child of a parent at index n is at index 2n+1 and 2n+2.

Linked Representation of Binary Tree
    