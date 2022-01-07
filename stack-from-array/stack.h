// Stack ADT for multiple Data Types (Array Implementation)

// Change the typedef for different data types
typedef int infi;

//Greater Sizes
typedef long long INT;

// Structure of Stack ADT
typedef struct stack
{
    INT size;
    INT stackTop;
    infi *array;
}stack;

// Functions on Stack
void init(stack *S1); // Initialises the Stack with Maximum size, stackTop and array.
void push(stack *S1,infi data); // Pushes an element on top of stack
infi pop(stack *S1); // Pops an element from top of stack
int isEmpty(stack S1); // Function to check whether stack is empty
int isFull(stack S1); // Function to check whether stack is full
infi peek(stack S1); // Returns element at top of stack without popping