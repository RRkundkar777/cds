#include"graph.h"

// Driver Code
int main(int argc, char const *argv[])
{
    graphM g1;
    initGraph(&g1,4);
    addEdge(&g1,0,3);
    addEdge(&g1,1,2);
    addEdge(&g1,2,1);
    addEdge(&g1,3,0);
    addEdge(&g1,3,3);

    displayGraph(g1);



    graphM g2;
    
    getGraphFromFile(&g2,"data.txt");

    displayGraph(g2);
    

    return 0;
}