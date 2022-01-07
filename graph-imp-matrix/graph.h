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

// Function to add an edge to the graph (Directed Graph)
void addEdge(graphM *G1,int source,int destination);

// Function to add an edge to the graph (Undirected Graph)
void addScalarEdge(graphM *G1,int source,int destination);

// Function to add a weighted edge to the graph (Undirected Graph)
void addWeightedEdge(graphM *G1,int source,int destination,int weight);

// Function to display graph in 2 Dimensions
void displayGraph(graphM G1);

// Function to Create a Graph from a file containing Data
void getGraphFromFile(graphM *G1,char *location);

// Function to implement Breadth First Search in Graph
void searchBFS(graphM *G1, int startVertex);

// Prims Algorithm to find Minimum Spanning tree of graph
void primMST(graphM *G1);

// Function to find MST of a Graph using Kruskal's algorithm
void kruskalMST(graphM *G1);