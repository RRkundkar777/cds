// Graph Adjacency Matrix ADT for multiple data types

// Change the typedef for different data types
typedef int infi;

// Structure of Graph
typedef struct graphM
{
    int vertex;
    infi **matrix;
}graphM;

//Greater Sizes
typedef long long INT;

// Functions on graph

// Function to initialise graph and allocate the Adjacency Matrix
void initGraph(graphM *G1, int vertices);

// Function to add an edge to the graph
void addEdge(graphM *G1,int source,int destination);

// Function to display graph in 2 Dimensions
void displayGraph(graphM G1);

// Function to Create a Graph from a file containing Data
void getGraphFromFile(graphM *G1,char *location);

