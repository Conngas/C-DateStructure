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
	InsertAdjList(&MyAdjList, 'F');

	InsertEdge(&MyAdjList, 'A', 'B');
	InsertEdge(&MyAdjList, 'A', 'C');
	InsertEdge(&MyAdjList, 'A', 'D');
	InsertEdge(&MyAdjList, 'C', 'B');
	InsertEdge(&MyAdjList, 'C', 'E');
	InsertEdge(&MyAdjList, 'D', 'E');
	InsertEdge(&MyAdjList, 'F', 'D');
	InsertEdge(&MyAdjList, 'F', 'E');

	ShowAdjList(&MyAdjList);
	//RemoveEdge(&MyAdjList, 'B', 'C');
	//RemoveVertice(&MyAdjList, 'C');
	//ShowAdjList(&MyAdjList);

	TopoLogicalSort(&MyAdjList);

	int iFirstNeighbar = GetFirstNeighbor(&MyAdjList, 'A');
	printf("Neighbar :> %d\n", iFirstNeighbar);
	int iNextNeighbar = GetNextNeighbor(&MyAdjList, 'B', 'A');
	printf("Neighbar :> %d\n", iNextNeighbar);
	
}