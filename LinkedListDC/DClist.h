//Doubly Circular Linked List for multiple data types

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node of a Doubly Circular Linked List
typedef struct node{
    infi data;
    struct node *prev,*next;
    
}node;

//Node pointer as list
typedef node* dclist;

// Doubly Circular Linked List Functions
void init(dclist *L1); // Initialises linked list with NULL
void append(dclist* L1,infi data); // Inserts an element at end of list
void prepend(dclist *L1,infi data); // Inserts an element at beginning of list
void display(dclist L1); // Displays the entire list
void delete(dclist *L1,infi data); // Deletes a specific element from list
void destroy(dclist *L1); // Destroys the entire list