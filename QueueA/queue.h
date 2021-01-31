// Queue ADT for multiple Data Types

// Change the typedef for different data types
typedef int infi;

//Greater Sizes
typedef long long INT;

// Structure of Queue ADT
typedef struct queue
{
    INT size;
    INT front;
    INT rear;
    infi *array;
}queue;

// Functions on queue
void init(queue *Q1); // Intialises the queue with size, front, rear and array
void enqueue(queue *Q1, infi data); // Enqueues an element to queue
infi dequeue(queue *Q1); // Dequeus an element from queue
infi queueFront(queue Q1); // Returns the front of queue without a dequeue
int isEmpty(queue Q1); // Function to check whether queue is empty
int isFull(queue Q1); // Function to check whether queue is full
