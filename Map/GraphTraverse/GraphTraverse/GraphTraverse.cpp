#include"GraphTraverse.h"
#include"Queue.h"


void InitGraph(SAdjacnecyMatrix* pSAdjMatrix)
{
	pSAdjMatrix->iMaxVertices = Default_Vertices_Size;
	pSAdjMatrix->iNumEdges = pSAdjMatrix->iNumVertices = 0;

	pSAdjMatrix->pDVerticesList = (VerList*)malloc(sizeof(VerList) * pSAdjMatrix->iMaxVertices);
	assert(pSAdjMatrix->pDVerticesList != NULL);

	//Malloc space of Double-Array
	pSAdjMatrix->ppiEdge = (int**)malloc(sizeof(int*) * pSAdjMatrix->iMaxVertices);
	assert(pSAdjMatrix->ppiEdge != NULL);
	for (int i = 0; i < pSAdjMatrix->iMaxVertices; ++i)
	{
		pSAdjMatrix->ppiEdge[i] = (int*)malloc(sizeof(int) * pSAdjMatrix->iMaxVertices);
	}

	//Initial
	for (int m = 0; m < pSAdjMatrix->iMaxVertices; ++m)
	{
		for (int n = 0; n < pSAdjMatrix->iMaxVertices; ++n)
		{
			pSAdjMatrix->ppiEdge[m][n] = 0;
		}
	}
}

void ShowGraph(SAdjacnecyMatrix* pSAdjMatrix)
{
	printf("   ");
	for (int m = 0; m < pSAdjMatrix->iNumVertices; ++m)
	{
		printf("%c  ", pSAdjMatrix->pDVerticesList[m]);
	}
	printf("\n");
	for (int i = 0; i < pSAdjMatrix->iNumVertices; ++i)
	{
		printf("%c  ", pSAdjMatrix->pDVerticesList[i]);
		for (int j = 0; j < pSAdjMatrix->iNumVertices; ++j)
		{
			printf("%d  ", pSAdjMatrix->ppiEdge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void InsertVertics(SAdjacnecyMatrix* pSAdjMtrix, VerList DVer)
{
	if (pSAdjMtrix->iNumVertices >= pSAdjMtrix->iMaxVertices)
		return;
	pSAdjMtrix->pDVerticesList[pSAdjMtrix->iNumVertices++] = DVer;
}

void InsertEdge(SAdjacnecyMatrix* pSAdjMtrix, VerList DverFirst, VerList DverSecond)
{
	int iVerPosF = GetVerticePos(pSAdjMtrix, DverFirst);
	int iVerPosS = GetVerticePos(pSAdjMtrix, DverSecond);
	if (iVerPosF == -1 || iVerPosS == -1)
		return;
	if (pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] == 1)
		return;

	pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] = pSAdjMtrix->ppiEdge[iVerPosS][iVerPosF] = 1;
	pSAdjMtrix->iNumEdges++;
}

void RemoveEdge(SAdjacnecyMatrix* pSAdjMtrix, VerList DverFirst, VerList DverSecond)
{
	int iVerPosF = GetVerticePos(pSAdjMtrix, DverFirst);
	int iVerPosS = GetVerticePos(pSAdjMtrix, DverSecond);
	if (iVerPosF == -1 || iVerPosS == -1)
		return;

	if (pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] == 0)
		return;

	pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] = pSAdjMtrix->ppiEdge[iVerPosS][iVerPosF] = 0;
	pSAdjMtrix->iNumEdges--;
}

void RemoveVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver)
{
	int iVerticePos = GetVerticePos(pSAdjMtrix, Dver);
	if (iVerticePos == -1)
		return;

	/// First Setp
	int iNumEdge = 0;
	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		if (pSAdjMtrix->ppiEdge[iVerticePos][i] != 0)
		{
			iNumEdge++;
		}
	}

	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices - 1; ++i)
	{
		pSAdjMtrix->pDVerticesList[i] = pSAdjMtrix->pDVerticesList[i + 1];
	}




	/// Second Setp 
	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices - 1; ++i)
	{
		for (int j = 0; j < pSAdjMtrix->iNumVertices; ++j)
		{
			pSAdjMtrix->ppiEdge[i][j] = pSAdjMtrix->ppiEdge[i + 1][j];
		}
	}

	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices - 1; ++i)
	{
		for (int j = 0; j < pSAdjMtrix->iNumVertices; ++j)
		{
			pSAdjMtrix->ppiEdge[j][i] = pSAdjMtrix->ppiEdge[j][i + 1];
		}
	}

	pSAdjMtrix->iNumVertices--;
	pSAdjMtrix->iNumEdges -= iNumEdge;

}

void RemoveVerticeFast(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver)
{
	int iVerticePos = GetVerticePos(pSAdjMtrix, Dver);
	int iLastNumVer = pSAdjMtrix->iNumVertices - 1;
	if (iVerticePos == -1)
		return;

	int iNumEdge = 0;
	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		if (pSAdjMtrix->ppiEdge[iVerticePos][i] != 0)
			iNumEdge++;
	}

	pSAdjMtrix->pDVerticesList[iVerticePos] = pSAdjMtrix->pDVerticesList[iLastNumVer];

	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		pSAdjMtrix->ppiEdge[iVerticePos][i] = pSAdjMtrix->ppiEdge[iLastNumVer][i];
	}
	for (int j = 0; j < pSAdjMtrix->iNumVertices; ++j)
	{
		pSAdjMtrix->ppiEdge[j][iVerticePos] = pSAdjMtrix->ppiEdge[j][iLastNumVer];
	}

	pSAdjMtrix->iNumVertices--;
	pSAdjMtrix->iNumEdges -= iNumEdge;
}

void DestoryGraph(SAdjacnecyMatrix* pSAdjMtrix)
{
	free(pSAdjMtrix->pDVerticesList);
	pSAdjMtrix->pDVerticesList = NULL;

	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		free(pSAdjMtrix->ppiEdge[i]);
	}
	free(pSAdjMtrix->ppiEdge);
	pSAdjMtrix->iNumEdges = pSAdjMtrix->iNumVertices = pSAdjMtrix->iMaxVertices = 0;
}

int  GetVerticePos(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver)
{
	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		if (pSAdjMtrix->pDVerticesList[i] == Dver)
			return i;
	}
	return -1;
}

int	 GetFirstNeighborVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver)
{
	int iVerticePos = GetVerticePos(pSAdjMtrix, Dver);
	if (iVerticePos == -1)
		return -1;

	for (int i = 0; i < pSAdjMtrix->iNumVertices; ++i)
	{
		if (pSAdjMtrix->ppiEdge[iVerticePos][i] == 1)
			return i;
	}
	return -1;
}

int  GetNextNeighborVertice(SAdjacnecyMatrix* psAdjMtrix, VerList DverFirst, VerList DeverSecond)
{
	int iVerticePosF = GetVerticePos(psAdjMtrix, DverFirst);
	int iVerticePosS = GetVerticePos(psAdjMtrix, DeverSecond);
	if (iVerticePosF == -1 || iVerticePosS == -1)
		return -1;

	for (int i = iVerticePosS + 1; i < psAdjMtrix->iNumVertices; ++i)
	{
		if (psAdjMtrix->ppiEdge[iVerticePosF][i] == 1)
			return i;
	}
	return -1;
}

//Traverse

void DepthFirstSearch(SAdjacnecyMatrix* pAdjMtrix, VerList Dver)
{
	int iVerticeNum = pAdjMtrix->iNumVertices;
	bool* pVisited = (bool*)malloc(sizeof(bool) * iVerticeNum);
	assert(pVisited != NULL);
	for (int i = 0;i < iVerticeNum;++i)
	{
		pVisited[i] = false;
	}
	printf("DFS:");
	int iVerPos = GetVerticePos(pAdjMtrix, Dver);
	DepthFirstSearch(pAdjMtrix, iVerPos, pVisited);
	printf("Nul.\n");
	free(pVisited);
}

void DepthFirstSearch(SAdjacnecyMatrix* pAdjMtrix, int iVerPos, bool pVisited[])
{
	printf("%c->", GetVerticeValue(pAdjMtrix, iVerPos));
	pVisited[iVerPos] = true;
	int iVerFirstNeighborPos = GetFirstNeighborVertice(pAdjMtrix,GetVerticeValue(pAdjMtrix,iVerPos));
	while (iVerFirstNeighborPos!=-1)
	{
		if (!pVisited[iVerFirstNeighborPos])
			DepthFirstSearch(pAdjMtrix, iVerFirstNeighborPos, pVisited);
		iVerFirstNeighborPos = GetNextNeighborVertice(pAdjMtrix, GetVerticeValue(pAdjMtrix, iVerPos), GetVerticeValue(pAdjMtrix, iVerFirstNeighborPos));
	}
}

VerList GetVerticeValue(SAdjacnecyMatrix* paAdjMtrix, int iVerPos)
{
	if (iVerPos == -1)
		return 0;
	return paAdjMtrix->pDVerticesList[iVerPos];
}

//BreadthFirstSearch

void BreadthFirstSearch(SAdjacnecyMatrix* pAdjMtrix, VerList Dver)
{
	//Init Segment
	int iVerticeNum = pAdjMtrix->iNumVertices;
	int iVerPos = GetVerticePos(pAdjMtrix, Dver);
	int iVerFirstNextVerPos=-1;

	//Init VisitedList
	bool* pVisited = (bool*)malloc(sizeof(bool) * iVerticeNum);
	assert(pVisited != NULL);
	for (int i = 0;i < iVerticeNum;++i)
	{
		pVisited[i] = false;
	}
	pVisited[iVerPos] = true;
		

	//Init Queue
	Queue BFSQueue;
	InitQueueFun(&BFSQueue);
	EnterQueueFun(&BFSQueue, iVerPos);

	//Ready to Traverse
	printf("BFS:%c->", GetVerticeValue(pAdjMtrix, iVerPos));
	while (!IsEmpty(&BFSQueue))
	{
		iVerPos = GetQueueFrontElem(&BFSQueue);
		DeQueueFun(&BFSQueue);
		iVerFirstNextVerPos = GetFirstNeighborVertice(pAdjMtrix, GetVerticeValue(pAdjMtrix, iVerPos));

		while (iVerFirstNextVerPos!=-1)
		{
			if (!pVisited[iVerFirstNextVerPos])
			{
				printf("%c->", GetVerticeValue(pAdjMtrix, iVerFirstNextVerPos));
				pVisited[iVerFirstNextVerPos] = true;
				EnterQueueFun(&BFSQueue, iVerFirstNextVerPos);
			}
			iVerFirstNextVerPos = GetNextNeighborVertice(pAdjMtrix, GetVerticeValue(pAdjMtrix, iVerPos), GetVerticeValue(pAdjMtrix, iVerFirstNextVerPos));
		}
	}
	free(pVisited);
	printf("Nul.\n");
}