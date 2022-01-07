// Driver Code

#include "graph.h"

int main(int argc, char const *argv[])
{
    graphAL g1;
    initGraph(&g1, 4);
    // addEdge(&g1, 0, 1);
    // addEdge(&g1, 0, 2);
    // addEdge(&g1, 0, 3);
    // addEdge(&g1, 1, 1);
    // addEdge(&g1, 1, 2);
    // addEdge(&g1, 2, 3);

    addScalarEdge(&g1,1,2);
    displayGraph(g1);
    return 0;
}
