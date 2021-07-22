#include"AdjacencyMatrix.h"

int main()
{
	AdjacencyMatrix MyGraphMatrix;
	InitGraph(&MyGraphMatrix);
	InsertVertics(&MyGraphMatrix, 'A');
	InsertVertics(&MyGraphMatrix, 'B');
	InsertVertics(&MyGraphMatrix, 'C');
	InsertVertics(&MyGraphMatrix, 'D');
	InsertVertics(&MyGraphMatrix, 'E');
	InsertVertics(&MyGraphMatrix, 'F');

	InsertEdge(&MyGraphMatrix, 'A', 'B', 6);
	InsertEdge(&MyGraphMatrix, 'A', 'C', 1);
	InsertEdge(&MyGraphMatrix, 'A', 'D', 5);
	InsertEdge(&MyGraphMatrix, 'B', 'C', 5);
	InsertEdge(&MyGraphMatrix, 'B', 'E', 3);
	InsertEdge(&MyGraphMatrix, 'C', 'E', 6);
	InsertEdge(&MyGraphMatrix, 'C', 'D', 5);
	InsertEdge(&MyGraphMatrix, 'C', 'F', 4);
	InsertEdge(&MyGraphMatrix, 'D', 'F', 2);
	InsertEdge(&MyGraphMatrix, 'E', 'F', 6);
	ShowGraph(&MyGraphMatrix);

	
	MinSpainTree_Kruskal(&MyGraphMatrix);

	DestoryGraph(&MyGraphMatrix);
}