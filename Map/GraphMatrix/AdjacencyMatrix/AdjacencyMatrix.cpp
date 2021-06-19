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
			pSAdjMatrix->ppiEdge[m][n] = 0;
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

