#include"AdjacencyList_H.h"

int main()
{
	AdjacencyList MyAdjList;
	InitAdjList(&MyAdjList);
	InsertAdjList(&MyAdjList, 'A');
	InsertAdjList(&MyAdjList, 'B');
	InsertAdjList(&MyAdjList, 'C');
	InsertAdjList(&MyAdjList, 'D');
	InsertAdjList(&MyAdjList, 'E');

	InsertEdge(&MyAdjList, 'A', 'B');
	InsertEdge(&MyAdjList, 'A', 'D');
	InsertEdge(&MyAdjList, 'B', 'C');
	InsertEdge(&MyAdjList, 'B', 'E');
	InsertEdge(&MyAdjList, 'C', 'D');
	InsertEdge(&MyAdjList, 'C', 'E');

	RemoveEdge(&MyAdjList, 'B', 'C');
	ShowAdjList(&MyAdjList);
}