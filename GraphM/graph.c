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
    G1->matrix = (infi**) malloc(sizeof(infi*) * vertices);

    // Allocating the individual vectors (either rows or columns) of matrix
    for (int i = 0; i < vertices; i++)
    {
        G1->matrix[i] = (infi*) malloc(sizeof(infi) * vertices);
    }
}

// Function to add an edge to the graph
void addEdge(graphM *G1,int source,int destination)
{
    // Note that g->matrix[source] is the pointer to the allocated vector
    // Also matrix[source][destination] is the exact memory location
    G1->matrix[source][destination] = 1;
}

// Function to display graph in 2 Dimensions
void displayGraph(graphM G1)
{
    // Printing the Space
    printf("  ");
    // Printing the Alphabets Corresponding to vertices (Row)
    for (int k = 0; k < G1.vertex; k++)
    {
        printf("%c ",65+k);
    }
    printf("\n");

    // Printing the Matrix
    for (int i = 0; i < G1.vertex; i++)
    {
        for (int j = 0; j < G1.vertex; j++)
        {
            // Printing the Alphabets Corresponding to vertices (Column)
            if(j == 0)
            {
                printf("%c ",65+i);
            }
            // Printing the Matrix elements
            printf("%d ",G1.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}

// Function to Create a Graph from a file containing Data
void getGraphFromFile(graphM *G1,char *location)
{
    // Vertices and Element of matrix
    infi vertices;
    infi element;
    // Initialising a File Pointer in read mode
    FILE *ostream;
    ostream = fopen(location,"r");
    // If file does not exist --> return
    if(ostream == NULL)
    {
        return;
    }
    // Scanning the number of vertices
    fscanf(ostream,"%d",&vertices);
    initGraph(G1,vertices);
    // Scanning the Adjacency Matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            fscanf(ostream,"%d",&element);
            G1->matrix[i][j] = element;
        }
    }
    return;
}