// Simple C++ implementation for Kruskal's
// algorithm
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

#define V 5
// int parent[V];

// Find set of vertex i
int find(int i,int parent[])
{
	while (parent[i] != i)
    {
		i = parent[i];
    }
	return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void makeUnion(int i, int j,int parent[])
{
	int a = find(i,parent);
	int b = find(j,parent);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
    // Total Cost (Sum of Edge Weights) of MST  
	int mincost = 0;

    // The array of disjoint sets.
    int parent[V];
	for (int i = 0; i < V; i++)
    {
		parent[i] = i;
    }

	// Count of Edges
	int edge_count = 0;

    // Including minimum cost edges one by one
	while(edge_count < V - 1)
    {
		int min = INT_MAX, a = -1, b = -1;

        // Finding the minimum edge by iterating over entire graph
		for (int i = 0; i < V; i++)
        {
			for (int j = 0; j < V; j++)
            {
                // Preventing Cycles
				if (find(i,parent) != find(j,parent) && cost[i][j] < min)
                {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

        // Union of a and b
		makeUnion(a, b,parent);
		printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

// driver program to test above function
int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| /	 \ |
	(3)-------(4)
			9		 */
	int cost[][V] = {
		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
		{ 2, INT_MAX, 3, 8, 5 },
		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
		{ 6, 8, INT_MAX, INT_MAX, 9 },
		{ INT_MAX, 5, 7, 9, INT_MAX },
	};

	// Print the solution
	kruskalMST(cost);

	return 0;
}
