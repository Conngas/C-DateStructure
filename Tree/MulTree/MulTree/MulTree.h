#pragma once
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

#define ElemType char

typedef struct SMulNode
{
	ElemType data;
	struct SMulNode* pSFirstChild;
	struct SMulNode* pSSibling;
}SMulNode;

typedef struct SMulTree
{
	struct SMulNode* pSRoot;
	ElemType DRefValue;
}SMulTree;

void InitMulTree(SMulTree* pSTree, ElemType DRef);
void CreateMulTree(SMulTree* pSTree, const char *pcMulTreeStr);
void CreateMulTree(SMulTree*pSTree,SMulNode*& prSMulNode, const char*& pcMulTreeStr);
SMulNode* FindMulTreeRoot(SMulTree* pSTree);
SMulNode* FindFirstChild(SMulTree* pSTree);
SMulNode* FindFirstChild(SMulNode* pSMulNode);
SMulNode* FindSibling(SMulTree* pSTree);
SMulNode* FindSibling(SMulNode* pSMulNode);
SMulNode* FindKey(SMulTree* pSTree, ElemType DKey);
SMulNode* FindKey(SMulNode* pSMulNode, ElemType DKey);
SMulNode* FindParent(SMulTree* pSTree, SMulNode* pSFinderNode);
SMulNode* FindParent(SMulNode* pSMulNode, SMulNode* pSFinderNode);