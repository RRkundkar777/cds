#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Boolean Enum
enum{
    true = 1,
    false = 0
};

// Queue ADT
#include"queue.h"

// Function to Initialise Queue
void init(queue *Q1)
{
    Q1->front = NULL;
    Q1->rear = NULL;
}

// Function to enqueue data into queue
void enqueue(queue *Q1, infi data)
{
    // Allocating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    // If malloc succeeds --> initialise with data
    if(!newnode)
    {
        printf("Memory Error\n");
    }
    // Initialising the NewNode 
    else
    {
        newnode->data = data;
        newnode->next = NULL;

        // If queue is empty --> Append Queue and return
        if(Q1->front == NULL)
        {
            Q1->front = Q1->rear = newnode;
            return;
        }
        // Else --> Link the newnode to queue
        Q1->rear->next = newnode;
        Q1->rear = newnode;
        return;
    }
}

// Function to perform dequeue operation on queue (Change some code for multiple data types)
infi dequeue(queue *Q1)
{
    // Data and travelling pointer
    infi data  = -1;
    node* traveller = Q1->front;
    // If queue is empty
    if(!traveller)
    {
        printf("Nothing to Dequeuen\n");
        return data;
    }
    Q1->front = Q1->front->next;
    data = traveller->data;
    free(traveller);
    return data;
}

// Function to view Front of queue without dequeueing
infi peek(queue Q1)
{
    return Q1.front->data;
}

// Function to check if queue is empty
int isEmpty(queue Q1)
{
    if(Q1.front == NULL)
    {
        return true;
    }
    return false;
}