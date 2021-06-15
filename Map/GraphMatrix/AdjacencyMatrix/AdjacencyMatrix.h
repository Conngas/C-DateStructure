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