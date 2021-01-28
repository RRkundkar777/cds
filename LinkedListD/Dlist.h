//Doubly Linked List ADT for multiple data types

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node of a Doubly Linked List
typedef struct node{
    infi data;
    struct node *prev,*next;
    
}node;

//Node pointer as list
typedef node* dlist;

//Doubly Linked List Functions
void init(dlist *L1); //Intialises the linked list to NULL
void append(dlist *L1,infi data); //Inserts an element to end of list
void prepend(dlist *L1,infi data); //Inserts an element to beginning of list
void display(dlist L1); //Displays the entire list
void delete(dlist *L1,infi data); //Deletes an element containing a certain data
void destroy(dlist* L1); //Destroys the entire list