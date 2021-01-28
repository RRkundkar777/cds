//Stack ADT for multiple Data Types

//Change the typedef for accomodating multiple data type
typedef int infi;

// For Large Data
typedef long long INT;

// Node of Stack 
typedef struct node{
    infi data;
    struct node* next;
}node;

// Node pointer as a stack
typedef node* stack;

// Functions on Stack
void init(stack *S1);
void push(stack *S1,infi data);
infi pop(stack *S1);
int isEmpty(stack S1);
infi stackTop(stack S1);