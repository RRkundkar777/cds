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
    Q1->front = Q1->rear = -1;
    Q1->size = MAX_SIZE;
    Q1->array = (infi*) malloc(sizeof(infi)*MAX_SIZE);
}

// Function to enqueue an element into queue
void enqueue(queue *Q1, infi data)
{
    // Handling condition when queue is full
    if(Q1->rear == Q1->size - 1)
    {
        printf("QueueError: Queue Overflow\n");
        return;
    }
    // Enqueuing an element in queue
    Q1->rear++;
    Q1->array[Q1->rear] = data;
    return;
}

// Function to dequeue an element from queue
infi dequeue(queue *Q1)
{
    infi data = -917274;
    // Handling queue empty condition
    if(Q1->front == Q1->rear)
    {
        printf("QueueError: Queue Underflow\n");
        return data;
    }
    Q1->front++;
    data = Q1->array[Q1->front];
    return data;
}

// Function to get the front of queue without dequeueing
infi queueFront(queue Q1)
{
    return Q1.array[Q1.front+1];
}

// Function to check whether queue is empty
int isEmpty(queue Q1)
{
    return (Q1.front == Q1.rear);
}

// Function to check whether queue is full
int isFull(queue Q1)
{
    return (Q1.rear == Q1.size - 1);
}