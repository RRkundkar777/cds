# Binary Heap
A binary heap is binary tree with some special proprties.

## Eligibility Criteria
For a Binary Tree to be a Binary Heap:
```
1. It must a complete binary tree.
2. It can be a min heap or a max heap.
3. In a min heap, the parent node is always smaller than its children.
4. In a max heap, the parent node is alwats greater than its children.
```

Because of this properties, the root element is greatest in case of max heap and smallest 
in case of min heap.

Insert Operation has a time complexity of O(log(n)).
Delete Operation has a time complexity of O(log(n)).

## Heapify
It is the process of creating a heap data structure.

Creating a heap from a Binary Tree has a time complexity of O(nlog(n)).

## Heap Sort
Heap sort is a comparison based sorting technique based on Binary Heap.
It has a time complexity of O(nlog(n)).