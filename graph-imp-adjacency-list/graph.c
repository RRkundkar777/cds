#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

// Graph Adjacency List ADT (Include Guard to Handle recursive Inclusion)
#ifndef GRAPH_H
#define GRAPH_H
#include"graph.h"
#endif

// Functions on Graph

// Utitlity Function to create a newnode
alNode *createNode(int data)
{
    alNode* newnode = (alNode*) malloc(sizeof(alNode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to initialise the graph with numner of vertices and allocate the array of lists
void initGraph(graphAL *G1,int vertices)
{
    // Initialising the number of vertices
    G1->vertex = vertices;
    // Allocating the array of list pointers
    G1->array = (adjList* ) malloc(sizeof(adjList)*vertices);
    // Initialising List Heads to NULL
    for (int i = 0; i < vertices; i++)
    {
        G1->array[i] = NULL;
    }
}

// Function to add an edge between two vertices in a graph (Directed)
void addEdge(graphAL *G1,int source, int destination)
{
    alNode* newnode = createNode(destination);
    newnode->next = G1->array[source];
    G1->array[source] = newnode;
}

// Function to add an edge between two vertices in a graph (Undirected)
void addScalarEdge(graphAL *G1,int source,int destination)
{
    addEdge(G1,source,destination);
    addEdge(G1,destination,source);
}

// Function to display graph
void displayGraph(graphAL G1)
{
    // Iterating over all the elements of array of lists
    for (int i = 0; i < G1.vertex; i++)
    {
        alNode* traveller = G1.array[i];
        // Simple linked list traversal
        while(traveller)
        {
            printf("%d ",traveller->data);
            traveller = traveller->next;
        }
        printf("\n");
    }
    return;
}

