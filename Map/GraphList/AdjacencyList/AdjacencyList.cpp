#include"AdjacencyList_H.h"

void InitAdjList(AdjacencyList* pAdjList)
{
	pAdjList->iMaxVertice = DDefautVerticeNum;
	pAdjList->iVerticeNum = pAdjList->iEdgeNum = 0;
	pAdjList->pVerticeList = (Vertice*)malloc(sizeof(Vertice) * pAdjList->iMaxVertice);
	assert(pAdjList->pVerticeList != NULL);

	for (int i = 0;i < pAdjList->iMaxVertice;++i)
	{
		pAdjList->pVerticeList[i].pDAdjLink = NULL;
		pAdjList->pVerticeList[i].DVerData = NULL;
	}
}

void InsertAdjList(AdjacencyList* pAdjList, Ver Dver)
{
	if (pAdjList->iEdgeNum >= pAdjList->iMaxVertice)
		return;
	pAdjList->pVerticeList[pAdjList->iVerticeNum++].DVerData = Dver;
}

void ShowAdjList(AdjacencyList* pAdjList)
{
	Edge* pTempEdge;
	for (int i = 0;i < pAdjList->iVerticeNum;++i)
	{
		printf("%d  %c:>", i, pAdjList->pVerticeList[i].DVerData);
		pTempEdge = pAdjList->pVerticeList[i].pDAdjLink;
		while (pTempEdge!=NULL)
		{
			printf("%d->", pTempEdge->sDest);
			pTempEdge = pTempEdge->pDLink;
		}
		printf("Nul.\n");
	}
	printf("\n");
}

void InsertEdge(AdjacencyList* pAdjList, Ver DFver, Ver DSver)
{
	int iFVerPos = GetVerticePos(pAdjList, DFver);
	int iSVerPos = GetVerticePos(pAdjList, DSver);
	if (iFVerPos == -1 || iSVerPos == -1)
		return;

	Edge* pTempEdge;
	//DFver to DSver
	pTempEdge = (Edge*)malloc(sizeof(Edge));
	assert(pTempEdge != NULL);
	pTempEdge->sDest = iSVerPos;
	pTempEdge->pDLink = pAdjList->pVerticeList[iFVerPos].pDAdjLink;//Continu Link
	pAdjList->pVerticeList[iFVerPos].pDAdjLink = pTempEdge;
	//DSver to DFver
	pTempEdge = (Edge*)malloc(sizeof(Edge));
	assert(pTempEdge != NULL);
	pTempEdge->sDest = iFVerPos;
	pTempEdge->pDLink = pAdjList->pVerticeList[iSVerPos].pDAdjLink;
	pAdjList->pVerticeList[iSVerPos].pDAdjLink = pTempEdge;
}

int	 GetVerticePos(AdjacencyList* pAdjList, Ver Dver)
{
	for (int i = 0;i < pAdjList->iVerticeNum;++i)
	{
		if (pAdjList->pVerticeList[i].DVerData == Dver)
			return i;
	}
	return -1;
}

