#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include"graphQueue.h"

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

// Weighted Graph Adjacency List ADT (Include Guard to Handle recursive Inclusion)
#ifndef GRAPH_H
#define GRAPH_H
#include"graph.h"
#endif

// Functions on Weighted Graph

// Utitlity Function to create a newnode
alNode *createNodeW(int data,INT weight)
{
    alNode* newnode = (alNode*) malloc(sizeof(alNode));
    newnode->data = data;
    newnode->weight = weight;
    newnode->next = NULL;
    return newnode;
}

// Function to initialise the graph with numner of vertices and allocate the array of lists
void initGraphW(graphAL *G1,int vertices)
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
void addEdgeW(graphAL *G1,int source, int destination,INT weight)
{
    alNode* newnode = createNodeW(destination,weight);
    newnode->next = G1->array[source];
    G1->array[source] = newnode;
}

// Function to add an edge between two vertices in a graph (Undirected)
void addScalarEdgeW(graphAL *G1,int source,int destination,INT weight)
{
    addEdgeW(G1,source,destination,weight);
    addEdgeW(G1,destination,source,weight);
}

// Function to display graph
void displayGraphW(graphAL G1)
{
    // Iterating over all the elements of array of lists
    for (int i = 0; i < G1.vertex; i++)
    {
        alNode* traveller = G1.array[i];
        printf("%c ",65+i);
        // Simple linked list traversal
        while(traveller)
        {
            printf("--->(%c,%lld)",65 + traveller->data,traveller->weight);
            traveller = traveller->next;
        }
        printf("\n");
    }
    return;
}

// Utility function to check if two vertices are related (connected)
int related(graphAL *G1,int m,int s)
{
    alNode *traveller = G1->array[m];
    while (traveller)
    {
        if(traveller->data == s)
        {
            return true;
        }
        traveller = traveller->next;
    }
    return false;
}

// Function for BFS Traversal
void BFS(graphAL *G1,int s)
{
    // Mark all the vertices as not visited
    int visited[G1->vertex];
    for(int i = 0; i < G1->vertex; i++)
    {
        visited[i] = false;
    }
 
    // Create a queue for BFS
    queue q1;
    init(&q1);
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    enqueue(&q1,s);
    
    // Traelling index
    int i;
 
    while(!isEmpty(q1))
    {
        // Dequeue a vertex from queue and print it
        s = dequeue(&q1);
        printf("%d ",s);
 
        // Check if it has adjacent vertices
        for (i = 0 ; i != G1->vertex; ++i)
        {
            if (!visited[i] && related(G1,s,i))
            {
                visited[i] = true;
                enqueue(&q1,i);
            }
        }
    }
}

// Recursive function for DFS Traversal
void DFS(graphAL *G1,int current,int visited[G1->vertex])
{
    // Print the current vertex and mark it as visited
    printf("%d ",current);
    visited[current] = true;
    
    // Check for its adjacent vertices
    int i;
    for (i = 0; i != G1->vertex; ++i)
        if (!visited[i] && related(G1,current,i))
        {
            DFS(G1,i,visited);
        }
}