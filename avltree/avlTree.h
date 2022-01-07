// Adelson-Velsky and Landis Tree ADT for multiple Data Types

// Change the typedef for different data types
typedef int infi;

// Node of an AVL Tree
typedef struct node
{
    infi data;
    struct node* left;
    struct node* right;
    int height;
}Anode;

//Greater Sizes
typedef long long INT;

//Node pointer as tree
typedef Anode* avltree;

// Functions on AVL Tree

// Function to initialise the AVL Tree
void initAVL(avltree *T1);

// Function to get balance factor of a node
int getBalance(Anode *node);

// Function to Right Rotate Tree
Anode *rightRotate(Anode *root);

// Function to Left Rotate Tree
Anode *leftRotate(Anode *root);

// Recursive function to insert a node into AVL Tree
Anode *insertR(avltree T1, infi data);

// Recursive function to delete a node
Anode *deleteNode(Anode *T1, int data);

// Function to print the avltree diagram
void print2D(avltree T1, int space);