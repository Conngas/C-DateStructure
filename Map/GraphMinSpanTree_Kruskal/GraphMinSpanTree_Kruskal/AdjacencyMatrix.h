#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

#define Default_Vertices_Size 10
#define VerList char

#define Weight int
#define MAX_COST 0x7FFFFFFF

typedef struct SAdjacnecyMatrix
{
	int iMaxVertices;
	int iNumVertices;
	int iNumEdges;

	VerList*	pDVerticesList;
	int**		ppiEdge;
}AdjacencyMatrix;

void InitGraph(SAdjacnecyMatrix* pSAdjMatrix);
void ShowGraph(SAdjacnecyMatrix* pSAdjMatrix);
void InsertVertics(SAdjacnecyMatrix* pSAdjMtrix,VerList DVer);
void InsertEdge(SAdjacnecyMatrix* pSAdjMatrix, VerList DverFirst, VerList DverSecond, Weight Dweight);
void RemoveVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver);
void RemoveVerticeFast(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver);
void RemoveEdge(SAdjacnecyMatrix* pSAdjMtrix, VerList DverFirst, VerList DeverSecond);
void DestoryGraph(SAdjacnecyMatrix* pSAdjMtrix);
int  GetVerticePos(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver);
int	 GetFirstNeighborVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver);
int  GetNextNeighborVertice(SAdjacnecyMatrix* psAdjMtrix, VerList DverFirst, VerList DeverSecond);

//Kruskal
typedef struct Edge
{
	int iStartEdge;
	int iEndEdge;
	Weight Dweight;
}Edge;

void MinSpainTree_Kruskal(SAdjacnecyMatrix* psAdjMtrix);