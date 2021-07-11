#include"GraphTraverse.h"

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

	InsertEdge(&SMyGraph, 'A', 'B');
	InsertEdge(&SMyGraph, 'A', 'C');
	InsertEdge(&SMyGraph, 'B', 'D');
	InsertEdge(&SMyGraph, 'B', 'E');
	InsertEdge(&SMyGraph, 'C', 'F');
	InsertEdge(&SMyGraph, 'C', 'G');
	InsertEdge(&SMyGraph, 'D', 'H');
	InsertEdge(&SMyGraph, 'H', 'E');
	InsertEdge(&SMyGraph, 'F', 'G');
	ShowGraph(&SMyGraph);

	DepthFirstSearch(&SMyGraph, 'A');
	BreadthFirstSearch(&SMyGraph, 'A');

	//printf("%d\n", GetFirstNeighborVertice(&SMyGraph, 'D'));
	//printf("%d\n", GetNextNeighborVertice(&SMyGraph, 'D', 'C'));


	//RemoveEdge(&SMyGraph, 'B', 'C');
	//ShowGraph(&SMyGraph);

	//RemoveVertice(&SMyGraph, 'C');
	//ShowGraph(&SMyGraph);

	////RemoveVerticeFast(&SMyGraph, 'C');
	////ShowGraph(&SMyGraph);


	//DestoryGraph(&SMyGraph);
}