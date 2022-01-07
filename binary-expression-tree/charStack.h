//Stack ADT for multiple Data Types

//Change the typedef for accomodating multiple data type
typedef char cinfi;

// For Large Data
typedef long long INT;

// Node of Stack 
typedef struct node{
    cinfi data;
    struct node* next;
}node;

// Node pointer as a stack
typedef node* charStack;

// Functions on Stack
void initCharStack(charStack *S1);
void pushChar(charStack *S1,cinfi data);
cinfi popChar(charStack *S1);
int isEmpty(charStack S1);
cinfi CstackTop(charStack S1);