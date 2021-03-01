// Binary Search Tree ADT for multiple Data Types

// Change the typedef for different data types
typedef int infi;

// Node of a Tree
typedef struct node
{
    infi data;
    struct node* left;
    struct node* right;
}node;

//Greater Sizes
typedef long long INT;

//Node pointer as tree
typedef node* tree;

// Functions on Binary Search Tree

// Function to initialise the tree
void initTree(tree *T1);

// Recursive Function for InOrder Traversal
void inOrder(tree T1);

// Recursive Function for PreOrder Traversal
void preOrder(tree T1);

// Recursive Function for PostOrder Traversal
void postOrder(tree T1);

// Function to Iteratively insert an element into BST
void insertI(tree *T1, infi data);

// Recursive function to insert a node into BST
node* insertR(tree T1, infi data);

// Function for Level Order Traversal using Queue
void levelOrder(tree T1);

// Iterative Function for PreOrder Traversal using Stack
void preOrderI(tree T1);

// Iterative Function for InOrder Traversal using Stack
void inOrderI(tree T1);

// Iterative Function for postOrder Traversal using Stack
void postOrderI(tree T1);

// Recursive Function to Delete a Node of a BST
node* deleteNode(tree T1, infi data);

// Recursive Function for Constructing a BST from a Post Order Array
tree constructFromPostOrder(infi array[], int *Index, int data, int min, int max, int size);

// Recursive Function to Count Number of Internal Nodes in a BST
int internalNodeCount(tree T1);

// Function to print BST in 2 Dimension
void print2D(tree T1,int space);

// Recursive Function to Calculate number of leaf nodes in a BST
int leafNodeCount(tree T1);

// Recursive Function to Calculate Total Number of Nodes in BST
int nodeCount(tree T1);

// Recursive function to check whether a BST is a complete BST or not
// index = 0 and nodeCount = total number of nodes
int isComplete (tree T1, int index,int nodeCount);

// Recursive function to check whether a BST is full BST or not
int isFullTree(tree T1);

// Recursive Function for Constructing a BST from a PreOrder Array
tree constructFromPreOrder(infi array[], int* Index,int data, int min, int max,int size);

// Recursive function to construct binary search tree from Inorder traversal in[] and Preorder traversal pre[].
tree buildFromPreOrder(infi in[], infi pre[], int inStrt, int inEnd);

// Recursive function to construct binary search tree from Inorder traversal in[] and Postorder traversal post[].
tree buildFromPostOrder(infi in[], infi post[], int inStrt,int inEnd, int* pIndex);