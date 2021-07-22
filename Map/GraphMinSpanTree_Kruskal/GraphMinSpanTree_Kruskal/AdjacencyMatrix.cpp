#include"AdjacencyMatrix.h"

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
			if (m == n)
			{
				pSAdjMatrix->ppiEdge[m][n] = 0;
			}
			else
			{
				pSAdjMatrix->ppiEdge[m][n] = MAX_COST;
			}
		}
	}
}

void ShowGraph(SAdjacnecyMatrix* pSAdjMatrix)
{
	printf("   ");
	for(int m = 0; m < pSAdjMatrix->iNumVertices; ++m)
	{
		printf("%c  ", pSAdjMatrix->pDVerticesList[m]);
	}
	printf("\n");
	for (int i = 0; i < pSAdjMatrix->iNumVertices; ++i)
	{
		printf("%c  ", pSAdjMatrix->pDVerticesList[i]);
		for (int j = 0; j < pSAdjMatrix->iNumVertices; ++j)
		{
			if (pSAdjMatrix->ppiEdge[i][j] == MAX_COST)
			{
				printf("%c  ", '-');
			}
			else
			{
				printf("%d  ", pSAdjMatrix->ppiEdge[i][j]);
			}
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

void InsertEdge(SAdjacnecyMatrix* pSAdjMtrix, VerList DverFirst, VerList DverSecond,Weight Dweight)
{
	int iVerPosF = GetVerticePos(pSAdjMtrix,DverFirst);
	int iVerPosS = GetVerticePos(pSAdjMtrix,DverSecond);
	if (iVerPosF == -1 || iVerPosS == -1)
		return;
	if (pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] == 1)
		return;

	pSAdjMtrix->ppiEdge[iVerPosF][iVerPosS] = pSAdjMtrix->ppiEdge[iVerPosS][iVerPosF] = Dweight;
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

	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices-1; ++i)
	{
		pSAdjMtrix->pDVerticesList[i] = pSAdjMtrix->pDVerticesList[i + 1];
	}



	
	/// Second Setp 
	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices-1; ++i)
	{
		for (int j = 0; j < pSAdjMtrix->iNumVertices; ++j)
		{
			pSAdjMtrix->ppiEdge[i][j] = pSAdjMtrix->ppiEdge[i + 1][j];
		}
	}

	for (int i = iVerticePos; i < pSAdjMtrix->iNumVertices-1; ++i)
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

//Kruskal

int CompEdge(const void* pFComp, const void* pSComp)
{
	return(*(Edge*)pFComp).Dweight - (*(Edge*)pSComp).Dweight;
}

bool Is_SimGroup(int* pRoot, int iStart, int iEnd)//Trace Base Root
{
	while (pRoot[iStart]!=iStart)
	{
		iStart = pRoot[iStart];
	}
	while (pRoot[iEnd] != iEnd)
	{
		iEnd = pRoot[iEnd];
	}
	return iStart == iEnd;
}

void MergeEdge(int* pRoot, int iStart, int iEnd)
{
	while (pRoot[iStart]!=iStart)
	{
		iStart = pRoot[iStart];
	}
	while (pRoot[iEnd] != iEnd)
	{
		iEnd = pRoot[iEnd];
	}
	pRoot[iEnd] = iStart;
}
//void MergeEdge(int* pRoot, int iStart, int iEnd)
//{
//	pRoot[iEnd] = iStart;
//}

void MinSpainTree_Kruskal(SAdjacnecyMatrix* psAdjMtrix)
{
	int iVerticeNum = psAdjMtrix->iNumVertices;
	//int iOrgainEdgeNum = psAdjMtrix->iNumEdges;
	//Edge = MaxEdge
	Edge* pCompEdge = (Edge*)malloc(sizeof(Edge) * ((iVerticeNum*(iVerticeNum-1))/2));//Contain All Weight Edge
	assert(pCompEdge != NULL);

	int iEdgeNum = 0;
	for (int i = 0; i < iVerticeNum; ++i)
	{
		for (int j = i; j < iVerticeNum; ++j)
		{
			if (psAdjMtrix->ppiEdge[i][j] != 0 && psAdjMtrix->ppiEdge[i][j] != MAX_COST)
			{
				pCompEdge[iEdgeNum].iStartEdge = i;
				pCompEdge[iEdgeNum].iEndEdge = j;
				pCompEdge[iEdgeNum].Dweight = psAdjMtrix->ppiEdge[i][j];
				iEdgeNum++;
			}
		}
	}


	/*int m, n;
	for (int i = 0; i < iEdgeNum; ++i)
	{
		m = pCompEdge[i].iStartEdge;
		n = pCompEdge[i].iEndEdge;
		printf("%c--->%c : %d\n", psAdjMtrix->pDVerticesList[m], psAdjMtrix->pDVerticesList[n], pCompEdge[i].Dweight);
	}*/
	//Sort CompEdge
	qsort(pCompEdge,iEdgeNum,sizeof(Edge),CompEdge);
	//printf("--------------------------------------------\n");
	//for (int i = 0; i < iEdgeNum; ++i)
	//{
	//	m = pCompEdge[i].iStartEdge;
	//	n = pCompEdge[i].iEndEdge;
	//	printf("%c--->%c : %d\n", psAdjMtrix->pDVerticesList[m], psAdjMtrix->pDVerticesList[n], pCompEdge[i].Dweight);
	//}


	//Recongnize Edge
	int* pRoot = (int*)malloc(sizeof(int) * iVerticeNum);
	int iStartX, iEndY;
	assert(pRoot != NULL);
	for (int i = 0; i < iVerticeNum; ++i)
	{
		pRoot[i] = i;
	}

	for (int i = 0; i < iEdgeNum; ++i)//Keep eyes on iEdgeNum Not iVertice or Use While
	{
		if (!Is_SimGroup(pRoot, pCompEdge[i].iStartEdge, pCompEdge[i].iEndEdge))
		{
			iStartX = pCompEdge[i].iStartEdge;
			iEndY = pCompEdge[i].iEndEdge;
			printf("%c->%c : %d\n", psAdjMtrix->pDVerticesList[iStartX], psAdjMtrix->pDVerticesList[iEndY], pCompEdge[i].Dweight);
			MergeEdge(pRoot, pCompEdge[i].iStartEdge, pCompEdge[i].iEndEdge);
		}
	}
}