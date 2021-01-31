#include<stdio.h>
#include<stdlib.h>

// Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Boolean Enum
enum{
    true = 1,
    false = 0
};

// Stack ADT
#include"stack.h"

// Maximum size of array of stack (change this value for different sizes)
#define MAX_SIZE 100

// Function to intialise stack with maximum array size, the array and StackTop
void init(stack *S1)
{
    S1->size = MAX_SIZE;
    S1->stackTop = -1;
    S1->array = (infi*) malloc(sizeof(infi)*S1->size);
    return;
}

// Function to push an element to the stack
void push(stack *S1,infi data)
{
    // Handling the condtion when stack is full
    if(S1->stackTop == S1->size - 1)
    {
        printf("StackOverflow: Failed to push\n");
        return;
    }
    // Changing the Stack Top and inserting element at its top
    S1->stackTop++;
    S1->array[S1->stackTop] = data;
    return;
}

// Function to pop an element from a stack
infi pop(stack *S1)
{
    // Data which is to be returned
    infi data = -9574773;
    // Handling the condition when stack is empty
    if(S1->stackTop == -1)
    {
        printf("StackError: Stack Underflow\n");
        return data;
    }
    data = S1->array[S1->stackTop];
    S1->stackTop--;
    return data;
}

// Function to check whether stack is empty
int isEmpty(stack S1)
{
    return (S1.stackTop == -1);
}

// Function to check whether stack is full
int isFull(stack S1)
{
    return (S1.stackTop == S1.size - 1);
}

// Function to get top of stack without popping
infi peek(stack S1)
{
    return S1.array[S1.stackTop];
}