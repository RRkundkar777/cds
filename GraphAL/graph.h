// Graph Adjacency List ADT for multiple data types

// Change the typedef for different data types
typedef int infi;

// Structure of the node of linked list
typedef struct alNode
{
    infi data;
    struct alNode* next;
}alNode;

// Node Pointer as a list
typedef alNode* adjList;

typedef struct graphAL
{
    int vertex;
    adjList* array;  
}graphAL;

// Functions on Graph


// Utitlity Function to create a newnode
alNode *createNode(int data);

// Function to initialise the graph with numner of vertices and allocate the array of lists
void initGraph(graphAL *G1,int vertices);

// Function to add an edge between two vertices in a graph (Directed)
void addEdge(graphAL *G1,int source, int destination);

// Function to add an edge between two vertices in a graph (Undirected)
void addScalarEdge(graphAL *G1,int source,int destination);

// Function to display graph
void displayGraph(graphAL G1);

void addScalarEdge(graphAL *G1,int src,int destn);