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
	InsertVertics(&SMyGraph, 'I');
	InsertVertics(&SMyGraph, 'J');
	InsertVertics(&SMyGraph, 'K');
	InsertVertics(&SMyGraph, 'L');
	InsertVertics(&SMyGraph, 'M');

	InsertEdge(&SMyGraph, 'A', 'B');
	InsertEdge(&SMyGraph, 'A', 'C');
	InsertEdge(&SMyGraph, 'A', 'F');
	InsertEdge(&SMyGraph, 'A', 'L');
	InsertEdge(&SMyGraph, 'B', 'M');
	InsertEdge(&SMyGraph, 'L', 'J');
	InsertEdge(&SMyGraph, 'L', 'M');
	InsertEdge(&SMyGraph, 'J', 'M');
	InsertEdge(&SMyGraph, 'D', 'E');
	InsertEdge(&SMyGraph, 'G', 'I');
	InsertEdge(&SMyGraph, 'G', 'K');
	InsertEdge(&SMyGraph, 'G', 'H');
	InsertEdge(&SMyGraph, 'H', 'K');

	ShowGraph(&SMyGraph);
	DFSComponents(&SMyGraph);
}

//int main()
//{
//	AdjacencyMatrix SMyGraph;
//	InitGraph(&SMyGraph);
//	InsertVertics(&SMyGraph, 'A');
//	InsertVertics(&SMyGraph, 'B');
//	InsertVertics(&SMyGraph, 'C');
//	InsertVertics(&SMyGraph, 'D');
//	InsertVertics(&SMyGraph, 'E');
//	InsertVertics(&SMyGraph, 'F');
//	InsertVertics(&SMyGraph, 'G');
//	InsertVertics(&SMyGraph, 'H');
//
//	InsertEdge(&SMyGraph, 'A', 'B');
//	InsertEdge(&SMyGraph, 'A', 'C');
//	InsertEdge(&SMyGraph, 'B', 'D');
//	InsertEdge(&SMyGraph, 'B', 'E');
//	InsertEdge(&SMyGraph, 'C', 'F');
//	InsertEdge(&SMyGraph, 'C', 'G');
//	InsertEdge(&SMyGraph, 'D', 'H');
//	InsertEdge(&SMyGraph, 'H', 'E');
//	InsertEdge(&SMyGraph, 'F', 'G');
//	ShowGraph(&SMyGraph);
//
//	DepthFirstSearch(&SMyGraph, 'A');
//	BreadthFirstSearch(&SMyGraph, 'A');
//
//	//printf("%d\n", GetFirstNeighborVertice(&SMyGraph, 'D'));
//	//printf("%d\n", GetNextNeighborVertice(&SMyGraph, 'D', 'C'));
//
//
//	//RemoveEdge(&SMyGraph, 'B', 'C');
//	//ShowGraph(&SMyGraph);
//
//	//RemoveVertice(&SMyGraph, 'C');
//	//ShowGraph(&SMyGraph);
//
//	////RemoveVerticeFast(&SMyGraph, 'C');
//	////ShowGraph(&SMyGraph);
//
//
//	//DestoryGraph(&SMyGraph);
//}