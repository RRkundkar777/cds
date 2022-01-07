#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "graphQueue.h"

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Graph Adjacency Matrix ADT (Include Guard to Handle recursive Inclusion)
#ifndef GRAPH_H
#define GRAPH_H
#include "graph.h"
#endif

// Function to initialise graph and allocate the Adjacency Matrix
void initGraph(graphM *G1, int vertices)
{
    // Initialising the number of vertices
    G1->vertex = vertices;

    // Initialising the Matrix
    // Allocating pointers based on number of vertices
    G1->matrix = (infi **)malloc(sizeof(infi *) * vertices);

    // Allocating the individual vectors (either rows or columns) of matrix
    for (int i = 0; i < vertices; i++)
    {
        G1->matrix[i] = (infi *)malloc(sizeof(infi) * vertices);
    }
}

// Function to add an edge to the graph
void addEdge(graphM *G1, int source, int destination)
{
    // Note that g->matrix[source] is the pointer to the allocated vector
    // Also matrix[source][destination] is the exact memory location
    G1->matrix[source][destination] = 1;
}

// Function to add an edge to the graph (Undirected Graph)
void addScalarEdge(graphM *G1, int source, int destination)
{
    // Note that g->matrix[source] is the pointer to the allocated vector
    // Also matrix[source][destination] is the exact memory location
    G1->matrix[source][destination] = 1;
    G1->matrix[destination][source] = 1;
}

// Function to add a weighted edge to the graph (Undirected Graph)
void addWeightedEdge(graphM *G1, int source, int destination, int weight)
{
    // Note that g->matrix[source] is the pointer to the allocated vector
    // Also matrix[source][destination] is the exact memory location
    G1->matrix[source][destination] = weight;
    G1->matrix[destination][source] = weight;
}

// Function to display graph in 2 Dimensions
void displayGraph(graphM G1)
{
    // Printing the Space
    printf("  ");
    // Printing the Alphabets Corresponding to vertices (Row)
    for (int k = 0; k < G1.vertex; k++)
    {
        printf("%c ", 65 + k);
    }
    printf("\n");

    // Printing the Matrix
    for (int i = 0; i < G1.vertex; i++)
    {
        for (int j = 0; j < G1.vertex; j++)
        {
            // Printing the Alphabets Corresponding to vertices (Column)
            if (j == 0)
            {
                printf("%c ", 65 + i);
            }
            // Printing the Matrix elements
            printf("%d ", G1.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}

// Function to Create a Graph from a file containing Data
void getGraphFromFile(graphM *G1, char *location)
{
    // Vertices and Element of matrix
    infi vertices;
    infi element;
    // Initialising a File Pointer in read mode
    FILE *ostream;
    ostream = fopen(location, "r");
    // If file does not exist --> return
    if (ostream == NULL)
    {
        return;
    }
    // Scanning the number of vertices
    fscanf(ostream, "%d", &vertices);
    initGraph(G1, vertices);
    // Scanning the Adjacency Matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            fscanf(ostream, "%d", &element);
            G1->matrix[i][j] = element;
        }
    }
    return;
}

// Function to implement Breadth First Search in Graph
void searchBFS(graphM *G1, int current)
{
    // Mark all the vertices as not visited
    int visited[G1->vertex];
    for (int i = 0; i < G1->vertex; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    queue q1;
    init(&q1);

    // Mark the current node as visited and enqueue it
    visited[current] = true;
    enqueue(&q1, current);

    while (!isEmpty(q1))
    {
        // Dequeue a vertex from queue and print it
        current = dequeue(&q1);
        printf("%d ", current);

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int i = 0; i != G1->vertex; ++i)
        {
            if (!visited[i] && G1.matrix[current][i])
            {
                visited[i] = true;
                enqueue(&q1, i);
            }
        }
    }
}

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(graphM *G1, int key[], bool isInMST[])
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < G1->vertex; v++)
    {
        if (isInMST[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Utility Function to printMST 
int displayPrimMST(int Mst[], graphM *G1)
{
    printf("The MST is: \n");
    printf("Edge \tCost\n");
    for (int i = 1; i < G1->vertex; i++)
    {
        printf("%d - %d \t%d \n", Mst[i], i, G1->matrix[i][Mst[i]]);
    }
}

// Prims Algorithm to find Minimum Spanning tree of graph
void primMST(graphM *G1)
{
    // MST Array (The actual MST)
    int Mst[G1->vertex];
    // Array to store minimum edge length
    int key[G1->vertex];
    // Set of vertices inside MST (if they are present inside MST)
    bool isInMST[G1->vertex];

    // Initialising all the keys as Infinite and all the isInMST as false
    for (int i = 0; i < G1->vertex; i++)
    {
        key[i] = INT_MAX;
        isInMST[i] = false;
    }

    // MST Starting from first vertex
    key[0] = 0;
    // Initialising the root of tree
    Mst[0] = -1;

    // minVertex --> The vertex with minimum edge
    int minVertex;
    
    // Iterate all the vertices for adjacent vertices
    for (int i = 0; i < G1->vertex - 1; i++)
    {
        minVertex = minKey(G1, key, isInMST);
        isInMST[minVertex] = true;

        // Updating key value and Mst index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < G1->vertex; v++)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (G1->matrix[minVertex][v] && isInMST[v] == false && G1->matrix[minVertex][v] < key[v])
            {
                Mst[v] = minVertex;
                key[v] = G1->matrix[minVertex][v];
            }
        }
    }
    displayPrimMST(Mst, G1);
}

// Utitlity Function to find Trace of Vertex
int findTrace(int i,int parent[])
{
	while (parent[i] != i)
    {
		i = parent[i];
    }
	return i;
}

// Utility Function to make union of two sets 
void makeUnion(int i, int j,int parent[])
{
	int a = findTrace(i,parent);
	int b = findTrace(j,parent);
	parent[a] = b;
}

// Utility Function to display kruskal tree
void displayKruskalMST(int result[],graphM *G1)
{
    printf("The MST is: \n");
    for (int i = 0; i < 4*(G1->vertex-1); i+=4)
    {
        printf("Edge %d:(%d, %d) cost:%d \n",result[i], result[i+1], result[i+2], result[i+3]);
        
    }
    
    // printf("Edge %d:(%d, %d) cost:%d \n",result[], a, b, min);
}

// Function to find MST of a Graph using kruskals algorithm
void kruskalMST(graphM *G1)
{
    // The Array Storing 
    int result[G1->vertex*4];
    int point = 0;

    // Total Cost (Sum of Edge Weights) of MST  
	int mincost = 0;

    // Number of Vertices in Graph
    int Vertices = G1->vertex;

    // The array of disjoint sets.
    int parent[Vertices];
	for (int i = 0; i < Vertices; i++)
    {
		parent[i] = i;
    }

	// Count of Edges
	int edgeCount = 0;

    // Including minimum cost edges one by one 
    // MST has (V - 1) Edges
	while(edgeCount < Vertices - 1)
    {
        // minimum cost, arbitrary vertices a and b
		int min = INT_MAX, a = -1, b = -1;

        // Finding the minimum edge by iterating over entire graph
		for (int i = 0; i < Vertices; i++)
        {
			for (int j = 0; j < Vertices; j++)
            {
                // Preventing Cycles
				if (findTrace(i,parent) != findTrace(j,parent) && G1->matrix[i][j] < min)
                {
					min = G1->matrix[i][j];
					a = i;
					b = j;
				}
			}
		}

        // Union of a and b
		makeUnion(a, b,parent);

        // Printing the MST
        result[point] = edgeCount++;point++;
        result[point] = a;point++;
        result[point] = b;point++;
        result[point] = min;point++;
        
        // Incrementing the min Cost
		mincost += min;
	}
    displayKruskalMST(result,G1);
	printf("\nMinimum cost is %d \n", mincost);
    return;
}