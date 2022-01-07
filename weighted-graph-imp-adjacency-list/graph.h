// Weighted Graph Adjacency List ADT for multiple data types

// Change the typedef for different data types
typedef int infi;

// Greater Sizes
typedef long long INT;

// Structure of the node of linked list
typedef struct alNode
{
    infi data;
    INT weight;
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
alNode *createNodeW(int data,INT weight);

// Function to initialise the graph with numner of vertices and allocate the array of lists
void initGraphW(graphAL *G1,int vertices);

// Function to add an edge between two vertices in a graph (Directed)
void addEdgeW(graphAL *G1,int source, int destination,INT weight);

// Function to add an edge between two vertices in a graph (Undirected)
void addScalarEdgeW(graphAL *G1,int source,int destination,INT weight);

// Function to display graph
void displayGraphW(graphAL G1);

// Function for BFS Traversal
void BFS(graphAL *G1,int s);

// Recursive function for DFS Traversal
void DFS(graphAL *G1,int current,int visited[G1->vertex]);

// 