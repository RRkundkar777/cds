//Binary Search Tree ADT for multiple data types

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node pointer as tree
typedef infi* tree;

// Binary Search Tree Functions
void init(tree *T1); //Intialises the root node to null
void insertI(tree T1,infi data); // Iteratively inserts element to BST
void insertR(tree T1,infi data); // Recursively inserts element to BST
void inOrder(tree T1,int index); // Recursive In Order Traversal
void preOrder(tree T1,int index); // Recursive Pre Order Traversal
void postOrder(tree T1,int index); // Recursive Post Order Traversal
int Isearch(tree T1,infi data); // Iterative Search for an element in BST
void print2D(tree T1,int index,int space); // Prints BST as a 2D diagram