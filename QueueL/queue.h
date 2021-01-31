// Queue ADT for multiple Data Types

// Change the typedef for different data types
typedef int infi;

//Greater Sizes
typedef long long INT;

// Node of a Queue
typedef struct node
{
    infi data;
    struct node* next;
}node;

//Queue Structure
typedef struct queue
{
    node* front;
    node* rear;
}queue;


// Functions on queue
void init(queue *Q1);
void enqueue(queue *Q1, infi data);
infi dequeue(queue *Q1);
infi peek(queue Q1);
int isEmpty(queue Q1);