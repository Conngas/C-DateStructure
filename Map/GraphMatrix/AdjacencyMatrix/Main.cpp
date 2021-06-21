#include"AdjacencyMatrix.h"

int main()
{
	AdjacencyMatrix SMyGraph;
	InitGraph(&SMyGraph);
	InsertVertics(&SMyGraph, 'A');
	InsertVertics(&SMyGraph, 'B');
	InsertVertics(&SMyGraph, 'C');
	InsertVertics(&SMyGraph, 'D');
	InsertVertics(&SMyGraph, 'E');

	InsertEdge(&SMyGraph, 'A', 'B');
	InsertEdge(&SMyGraph, 'A', 'D');
	InsertEdge(&SMyGraph, 'B', 'C');
	InsertEdge(&SMyGraph, 'B', 'E');
	InsertEdge(&SMyGraph, 'C', 'D');
	ShowGraph(&SMyGraph);

	RemoveEdge(&SMyGraph, 'B', 'C');
	ShowGraph(&SMyGraph);
}