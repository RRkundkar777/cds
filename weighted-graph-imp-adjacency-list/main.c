// Driver Code

#include "graph.h"
#include<stdio.h>

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

int main(int argc, char const *argv[])
{
    graphAL g1;
    initGraphW(&g1, 9);

    addScalarEdgeW(&g1,0,1,2);
    addScalarEdgeW(&g1,0,2,4);
    addScalarEdgeW(&g1,0,3,6);
    addScalarEdgeW(&g1,1,2,5);
    addScalarEdgeW(&g1,2,3,1);
    addScalarEdgeW(&g1,2,4,2);
    addScalarEdgeW(&g1,3,5,3);
    addScalarEdgeW(&g1,3,7,4);
    addScalarEdgeW(&g1,4,8,3);
    addScalarEdgeW(&g1,4,6,5);
    addScalarEdgeW(&g1,4,5,1);
    addScalarEdgeW(&g1,5,6,4);

    printf("The Graph is:\n");
    displayGraphW(g1);
    printf("\n");

    printf("BFS Traversal: ");
    BFS(&g1,2);
    printf("\n\n");

    int V1[g1.vertex];
    for (int i = 0; i < g1.vertex; i++)
    {
        V1[i] = false;
    }
    
    printf("DFS Traversal: ");
    DFS(&g1,2,V1);
    printf("\n");
    return 0;
}
