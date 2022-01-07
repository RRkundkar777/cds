//Circular Linked List ADT for multiple data types

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node of a Circularly Linked List
typedef struct node{
    infi data;
    struct node *next;
    
}node;

//Node pointer as list
typedef node* clist;

//Circularly Linked List Functions
void init(clist *L1); //Intialises the linked list to null
void append(clist *L1,infi data); //Inserts a node at end of list
void prepend(clist *L1,infi data); //Inserts a node at beginning of list
void display(clist L1); //Displays the entire list
void delete(clist *L1,infi data); //Deletes an node with certain data
void destroy(clist *L1); //Destroys the entire list and sets the head to NULL
