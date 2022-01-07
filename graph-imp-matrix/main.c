#include<stdio.h>
#include<limits.h>
#include"graph.h"

// Driver Code
int main(int argc, char const *argv[])
{
    graphM g1;
    initGraph(&g1,4);
    addScalarEdge(&g1,1,3);
    addScalarEdge(&g1,0,1);

    displayGraph(g1);

    graphM g2;
    
    getGraphFromFile(&g2,"data.txt");

    displayGraph(g2);

    printf("BFS Traversal of Graph: ");
    searchBFS(&g1,0);
    printf("\n\n");

    graphM g3;
    getGraphFromFile(&g3,"primdata.txt");

    primMST(&g3);

    graphM g4;
    getGraphFromFile(&g4,"kruskaldata.txt");


    printf("\n\n");    
    kruskalMST(&g4);
    
    
    return 0;
}