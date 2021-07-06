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
	pAdjList->iEdgeNum++;
	//DSver to DFver
	pTempEdge = (Edge*)malloc(sizeof(Edge));
	assert(pTempEdge != NULL);
	pTempEdge->sDest = iFVerPos;
	pTempEdge->pDLink = pAdjList->pVerticeList[iSVerPos].pDAdjLink;
	pAdjList->pVerticeList[iSVerPos].pDAdjLink = pTempEdge;
	pAdjList->iEdgeNum++;
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
	while (pFrontEdge!=NULL && pFrontEdge->sDest!=iDSver)//�жϵ�ΪĿ���λ�ö�����Ŀ��ڵ�
	{
		pBackEdge = pFrontEdge;
		pFrontEdge = pFrontEdge->pDLink;
	}
	if (pFrontEdge == NULL)
	{
		printf("û�б���Ҫɾ����\n");
		return;
	}
		
	if (pBackEdge == NULL)//˵���ڵ�Ϊ��һ������ʱ��PF��û�б���ֵ����ͷ�ڵ㸳ֵ����һ��
	{
		pAdjList->pVerticeList[iDFver].pDAdjLink = pFrontEdge->pDLink;
	}
	else
	{
		pBackEdge->pDLink = pFrontEdge->pDLink; 
	}
	free(pFrontEdge);
	pAdjList->iEdgeNum--;

	//DSver>DFver
	pBackEdge = NULL;
	pFrontEdge = pAdjList->pVerticeList[iDSver].pDAdjLink;
	while (pFrontEdge != NULL && pFrontEdge->sDest != iDFver)
	{
		pBackEdge = pFrontEdge;
		pFrontEdge = pFrontEdge->pDLink;
	}
	
	if (pFrontEdge == NULL)//�˲��ֿ���ʡ�ԣ���Ϊ����ͼ���ڵ�һ�μ��߲�����ʱ����ȷ���������ٴμ�飡
	{
		printf("û�б���Ҫɾ����\n");
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
	pAdjList->iEdgeNum--;
}

void RemoveVertice(AdjacencyList* pAdjList, Ver Dver)
{
	int iDver = GetVerticePos(pAdjList, Dver);
	if (iDver == -1)
		return;

	Edge* pDeleteEdge = pAdjList->pVerticeList[iDver].pDAdjLink;
	Edge* pFrontEdge;
	Edge* pBackEdge = NULL;
	int	  iRelateEdge;
	
	//Remove Edge
	while (pDeleteEdge!=NULL)
	{
		iRelateEdge = pDeleteEdge->sDest;
		pFrontEdge = pAdjList->pVerticeList[iRelateEdge].pDAdjLink;
		while (pFrontEdge!=NULL && pFrontEdge->sDest!=iDver)
		{
			pBackEdge = pFrontEdge;
			pFrontEdge = pFrontEdge->pDLink;
		}
		if (pFrontEdge == NULL)
		{
			return;
		}
		else
		{
			if (pBackEdge == NULL)
			{
				pAdjList->pVerticeList[iRelateEdge].pDAdjLink = pFrontEdge->pDLink;
			}
			else
			{
				pBackEdge->pDLink = pFrontEdge->pDLink;//ɾ��ǰ�ã�
			}
			free(pFrontEdge);
			pAdjList->iEdgeNum--;
		}
		pAdjList->pVerticeList[iDver].pDAdjLink = pDeleteEdge->pDLink;
		free(pDeleteEdge);
		pAdjList->iEdgeNum--;
		pDeleteEdge = pAdjList->pVerticeList[iDver].pDAdjLink;
	}

	//Replace Vertice
	pAdjList->iVerticeNum--;
	pAdjList->pVerticeList[iDver].DVerData = pAdjList->pVerticeList[pAdjList->iVerticeNum].DVerData;
	pAdjList->pVerticeList[iDver].pDAdjLink = pAdjList->pVerticeList[pAdjList->iVerticeNum].pDAdjLink;

	//Adjest EdgeMap

	pDeleteEdge = pAdjList->pVerticeList[iDver].pDAdjLink;
	while (pDeleteEdge != NULL)
	{
		iRelateEdge = pDeleteEdge->sDest;
		pFrontEdge = pAdjList->pVerticeList[iRelateEdge].pDAdjLink;
		while (pFrontEdge != NULL)
		{
			if (pFrontEdge->sDest == pAdjList->iVerticeNum)
			{
				pFrontEdge->sDest = iDver;
				break;//����ȷ��һ��ֱ��
			}
			pFrontEdge = pFrontEdge->pDLink;
		}
		pDeleteEdge = pDeleteEdge->pDLink;
	}

}

void DestoryAdjList(AdjacencyList* pAdjList)
{
	Edge* pDeleteEdge=NULL;
	for (int i = 0; i < pAdjList->iMaxVertice; ++i)
	{
		pDeleteEdge = pAdjList->pVerticeList[i].pDAdjLink;
		while (pDeleteEdge != NULL)
		{
			pAdjList->pVerticeList[i].pDAdjLink = pDeleteEdge->pDLink;
			free(pDeleteEdge);
			pDeleteEdge = pDeleteEdge->pDLink;
		}
	}
	free(pAdjList->pVerticeList);
	pAdjList->pVerticeList = NULL;
	pAdjList->iEdgeNum = pAdjList->iMaxVertice = pAdjList->iVerticeNum = 0;

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

int  GetFirstNeighbor(AdjacencyList* pAdjList, Ver Dver)
{
	int iDver = GetVerticePos(pAdjList, Dver);
	if (iDver == -1)
		return -1;
	Edge* pNeighborVer = pAdjList->pVerticeList[iDver].pDAdjLink;
	if (pNeighborVer != NULL)
		return pNeighborVer->sDest;
	return -1;
}

//int  GetNextNeighbor(AdjacencyList* pAdjList, Ver DFver, Ver DSver)
//{
//	int iDFver = GetVerticePos(pAdjList, DFver);
//	int iDSver = GetVerticePos(pAdjList, DSver);
//	if (iDFver == -1 || iDSver == -1)
//		return -1;
//
//	Edge* pSearchEdge = pAdjList->pVerticeList[iDFver].pDAdjLink;
//	while (pSearchEdge != NULL && pSearchEdge->sDest != iDSver);
//	{
//		pSearchEdge = pSearchEdge->pDLink;
//	}
//	if (pSearchEdge != NULL && pSearchEdge->pDLink != NULL)
//		return pSearchEdge->pDLink->sDest;
//	return -1;
//}

int  GetNextNeighbor(AdjacencyList* pAdjList, Ver DFver, Ver DSver)
{
	int iDFver = GetVerticePos(pAdjList, DFver);
	int iDSver = GetVerticePos(pAdjList, DSver);
	if (iDFver == -1 || iDSver == -1)
		return -1;

	Edge* pSearchEdge = pAdjList->pVerticeList[iDFver].pDAdjLink;
	while (pSearchEdge != NULL && pSearchEdge->sDest != iDSver)
	{
		pSearchEdge = pSearchEdge->pDLink;
	}
	if (pSearchEdge != NULL && pSearchEdge->pDLink != NULL)
		return pSearchEdge->pDLink->sDest;
	return -1;
}