#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Default_Vertices_Size 10
#define VerList char
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
void InsertEdge(SAdjacnecyMatrix* pSAdjMatrix, VerList DverFirst, VerList DverSecond);
void RemoveVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList DVer);
void RemoveEdge(SAdjacnecyMatrix* pSAdjMtrix, VerList DverFirst, VerList DeverSecond);
int	 GetFirstNeighborVertice(SAdjacnecyMatrix* pSAdjMtrix, VerList Dver);
int  GetNextNeighborEdge(SAdjacnecyMatrix* psAdjMtrix, VerList DverFirst, VerList DeverSecond);