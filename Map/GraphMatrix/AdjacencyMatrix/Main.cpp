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
	InsertEdge(&SMyGraph, 'C', 'E');
	ShowGraph(&SMyGraph);

	printf("%d\n", GetFirstNeighborVertice(&SMyGraph, 'D'));
	printf("%d\n", GetNextNeighborVertice(&SMyGraph, 'D','C'));


	RemoveEdge(&SMyGraph, 'B', 'C');
	ShowGraph(&SMyGraph);

	RemoveVertice(&SMyGraph, 'C');
	ShowGraph(&SMyGraph);

	//RemoveVerticeFast(&SMyGraph, 'C');
	//ShowGraph(&SMyGraph);


	DestoryGraph(&SMyGraph);
}