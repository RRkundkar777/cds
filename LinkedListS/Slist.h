//Singly Linked List ADT for multiple data types

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node of a Linked List
typedef struct node{
    infi data;
    struct node* next;
    
}node;

//Node pointer as list
typedef node* slist;

// Linked List Functions 
void init(slist *L1); //Initialises the linked list with NULL
void append(slist *L1,infi data); //Inserts a node at end of list
void prepend(slist * L1,infi data); //Inserts a node beginnning of linked list
void display(slist L1); //Displays the entire list
void delete(slist *L1,infi data); //Removes the node containing a certain data
void destroy(slist* L1); //Destroys/Empties the entire list 