#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Boolean Enum
enum{
    true = 1,
    false = 0
};

// Stack ADT
#include"stack.h"

// Intialising the Stack
void init(stack *S1)
{
    *S1 = NULL;
}

// Function to push data into stack
void push(stack *S1,infi data)
{
    // Allocating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    // Handling malloc failure
    if(!newnode)
    {
        printf("Memory Error\n");
        return;
    }
    // Intialising the newnode
    else
    {
        newnode->data = data;
        newnode->next = (*S1);
        (*S1) = newnode;
        return;
    }
}

// Function to pop the first element from stack (Change some code for multiple data types)
infi pop(stack *S1)
{
    infi data = -1;
    // If stack is empty --> Return
    if(!(*S1))
    {
        printf("Stack is Empty\n");
        return data;
    }
    // Else --> Remove an element from the stack
    else
    {
        node* traveller = *S1;
        *S1 = (*S1)->next;
        data = traveller->data;
        free(traveller);
    }
    return data;
}

// Function to check if Stack is empty
int isEmpty(stack S1)
{
    if(S1 == NULL)
    {
        return true;
    }
    return false;
}

// Function to view top of stack without popping it
infi stackTop(stack S1)
{
    return S1->data;
}