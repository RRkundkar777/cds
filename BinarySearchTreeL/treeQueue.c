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
#include"treeQueue.h"

// Function to Initialise Queue
void initQueue(queue *Q1)
{
    Q1->front = NULL;
    Q1->rear = NULL;
}

// Function to enqueue data into queue
void enqueue(queue *Q1, qinfi data)
{
    // Allocating a newnode
    nodeQ* newnode = (nodeQ*) malloc(sizeof(nodeQ));
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
qinfi dequeue(queue *Q1)
{
    // Data and travelling pointer
    qinfi data;
    nodeQ* traveller = Q1->front;
    // If queue is empty
    if(!traveller)
    {
        printf("Nothing to Dequeue\n");
        return data;
    }
    Q1->front = Q1->front->next;
    data = traveller->data;
    free(traveller);
    return data;
}

// Function to view Front of queue without dequeueing
qinfi peek(queue Q1)
{
    return Q1.front->data;
}

// Function to check if queue is empty
int isEmptyQueue(queue Q1)
{
    if(Q1.front == NULL)
    {
        return true;
    }
    return false;
}