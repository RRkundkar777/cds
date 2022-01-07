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
#include"charStack.h"

// Intialising the Stack
void initCharStack(charStack *S1)
{
    *S1 = NULL;
}

// Function to push data into stack
void pushChar(charStack *S1,cinfi data)
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
cinfi popChar(charStack *S1)
{
    cinfi data = -1;
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
int isEmpty(charStack S1)
{
    if(S1 == NULL)
    {
        return true;
    }
    return false;
}

// Function to view top of stack without popping it
cinfi CstackTop(charStack S1)
{
    return S1->data;
}