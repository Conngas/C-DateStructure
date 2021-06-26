#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define DDefautVerticeNum 10
#define Ver char


typedef struct Edge//Edge
{
	size_t sDest;
	struct Edge* pDLink;
}Edge;

typedef struct Vertice
{
	Ver DVerData;
	struct Edge* pDAdjLink;
}Vertice;

typedef struct AdjacencyList
{
	int iMaxVertice;
	int iVerticeNum;
	int iEdgeNum;
	struct Vertice* pVerticeList;
}AdjacencyList;

void InitAdjList(AdjacencyList* pAdjList);
void InsertAdjList(AdjacencyList* pAdjList, Ver Dver);
void ShowAdjList(AdjacencyList* pAdjList);
void InsertEdge(AdjacencyList* pAdjList, Ver DFver, Ver DSver);
void RemoveVertice(AdjacencyList* pAdjList, Ver Dver);
void RemoveEdge(AdjacencyList* pAdjList, Ver DFver, Ver DSver);
void DestoryAdjList(AdjacencyList* pAdjList);
int	 GetVerticePos(AdjacencyList* pAdjList, Ver Dver);
int  GetFirstNeighbor(AdjacencyList* pAdjList, Ver Dver);
int  GetNextNeighbor(AdjacencyList* pAdjList, Ver DFver, Ver DSver);

