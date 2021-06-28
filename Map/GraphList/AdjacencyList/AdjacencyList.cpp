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

void RemoveEdge(AdjacencyList* pAdjList, Ver DFver, Ver DSver)
{
	int iDFver = GetVerticePos(pAdjList, DFver);
	int iDSver = GetVerticePos(pAdjList, DSver);
	if (iDFver == -1 || iDSver == -1)
		return;

	Edge* pBackEdge = NULL;
	Edge* pFrontEdge;
	pFrontEdge = pAdjList->pVerticeList[iDFver].pDAdjLink;
	while (pFrontEdge!=NULL && pFrontEdge->sDest!=iDSver)//判断的为目标的位置而不是目标节点
	{
		pBackEdge = pFrontEdge;
		pFrontEdge = pFrontEdge->pDLink;
	}
	if (pFrontEdge == NULL)
	{
		printf("没有边需要删除！\n");
		return;
	}
		
	if (pBackEdge == NULL)//说明节点为第一个，此时的PF还没有被赋值，让头节点赋值给下一个
	{
		pAdjList->pVerticeList[iDFver].pDAdjLink = pFrontEdge->pDLink;
	}
	else
	{
		pBackEdge->pDLink = pFrontEdge->pDLink; 
	}
	free(pFrontEdge);

	//DSver>DFver
	pBackEdge = NULL;
	pFrontEdge = pAdjList->pVerticeList[iDSver].pDAdjLink;
	while (pFrontEdge != NULL && pFrontEdge->sDest != iDFver)
	{
		pBackEdge = pFrontEdge;
		pFrontEdge = pFrontEdge->pDLink;
	}
	
	if (pFrontEdge == NULL)//此部分可以省略，因为无向图，在第一次检测边不存在时就以确定，不必再次检查！
	{
		printf("没有边需要删除！\n");
		return;
	}

	if (pBackEdge == NULL)
	{
		pAdjList->pVerticeList[iDSver].pDAdjLink = pFrontEdge->pDLink;
	}
	else
	{
		pBackEdge->pDLink = pFrontEdge->pDLink;
	}
	free(pFrontEdge);
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

