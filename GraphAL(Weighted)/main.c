// Driver Code

#include "graph.h"

int main(int argc, char const *argv[])
{
    graphAL g1;
    initGraphW(&g1, 4);
    // addEdge(&g1, 0, 1);
    // addEdge(&g1, 0, 2);
    // addEdge(&g1, 0, 3);
    // addEdge(&g1, 1, 1);
    // addEdge(&g1, 1, 2);
    // addEdge(&g1, 2, 3);

    addScalarEdgeW(&g1,1,2,43);
    displayGraphW(g1);
    return 0;
}
