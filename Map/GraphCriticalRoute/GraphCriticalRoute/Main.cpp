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
	InsertVertics(&SMyGraph, 'F');
	InsertVertics(&SMyGraph, 'G');
	InsertVertics(&SMyGraph, 'H');
	InsertVertics(&SMyGraph, 'I');

	InsertEdge(&SMyGraph, 'A', 'B',6);
	InsertEdge(&SMyGraph, 'A', 'C',4);
	InsertEdge(&SMyGraph, 'A', 'D',5);
	InsertEdge(&SMyGraph, 'B', 'E',1);
	InsertEdge(&SMyGraph, 'C', 'E',1);
	InsertEdge(&SMyGraph, 'D', 'F',2);
	InsertEdge(&SMyGraph, 'E', 'G',9);
	InsertEdge(&SMyGraph, 'E', 'H',7);
	InsertEdge(&SMyGraph, 'F', 'H',4);
	InsertEdge(&SMyGraph, 'G', 'I',2);
	InsertEdge(&SMyGraph, 'H', 'I',4);
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