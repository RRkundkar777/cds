//Stack ADT for multiple Data Types

//Change the typedef for accomodating multiple data type
typedef int infi;

//for large data
typedef long long INT;

// Node of Stack 
typedef struct node{
    infi data;
    struct node* next;
}node;

// Node pointer as a stack
typedef node* stack;