// Queue ADT for multiple Data Types

// Node of a tree (Include Guard to Handle recursive Inclusion)
#ifndef BST_H
#define BST_H
#include"bst.h"
#endif

// Node of tree as data of Queue
typedef node* qinfi;

//Greater Sizes
typedef long long INT;

// Node of a Queue
typedef struct nodeQ
{
    qinfi data;
    struct nodeQ* next;
}nodeQ;

//Queue Structure
typedef struct queue
{
    nodeQ* front;
    nodeQ* rear;
}queue;


// Functions on queue
void initQueue(queue *Q1);
void enqueue(queue *Q1, qinfi data);
qinfi dequeue(queue *Q1);
qinfi peek(queue Q1);
int isEmptyQueue(queue Q1);