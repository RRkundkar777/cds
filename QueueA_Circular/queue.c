#include<stdio.h>
#include<stdlib.h>

// Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Boolean Enum
enum{
    true = 1,
    false = 0
};

// Queue ADT
#include"queue.h"
    
// Maximum size of array of queue (change this value for different sizes)
#define MAX_SIZE 100

// Function to initialise queue with front,rear,size and allocating array
void init(queue *Q1)
{
    Q1->front = Q1->rear = 0;
    Q1->size = MAX_SIZE;
    Q1->array = (infi*) malloc(sizeof(infi)*MAX_SIZE);
}

// Function to enqueue into circular queue
void enqueue(queue *Q1,int data)
{
    if((Q1->rear+1)%Q1->size == Q1->front)
    {
        printf("QueueError: Queue Overflow\n");
        return;
    }
    // Circular Increment of rear
    Q1->rear = (Q1->rear+1)%Q1->size;
    Q1->array[Q1->rear] = data;
}

infi dequeue(queue *Q1)
{
    infi data = -9167483;
    if(Q1->rear == Q1->front)
    {
        printf("QueueError: Queue Underflow\n");
        return data;
    }
    // Circular Increment of front
    Q1->front = (Q1->front+1)%Q1->size;
    data = Q1->array[Q1->front];
    return data;
}

// Function to check whether circular queue is full
int isFull(queue Q1)
{
    return ((Q1.rear+1)%Q1.size == Q1.front);
}

// Function to check whether circular queue is empty
int isEmpty(queue Q1)
{
    return (Q1.rear == Q1.front);
}

// Function to get the front of queue without dequeueing
infi queueFront(queue Q1)
{
    return Q1.array[(Q1.front+1)%Q1.size];
}