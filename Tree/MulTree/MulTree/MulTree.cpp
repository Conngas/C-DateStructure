#include"MulTree.h"

void InitMulTree(SMulTree* pSTree, ElemType DRef)
{
	pSTree->pSRoot = NULL;
	pSTree->DRefValue = DRef;
}

void CreateMulTree(SMulTree* pSTree, const char* pcMulTreeStr)
{
	CreateMulTree(pSTree, pSTree->pSRoot, pcMulTreeStr);
}
void CreateMulTree(SMulTree* pSTree, SMulNode*& prSMulNode, const char*& pcMulTreeStr)
{
	if (*pcMulTreeStr==pSTree->DRefValue)
		prSMulNode = NULL;
	else
	{
		prSMulNode = (SMulNode*)malloc(sizeof(SMulNode));
		assert(prSMulNode != NULL);
		prSMulNode->data = *pcMulTreeStr;
		CreateMulTree(pSTree, prSMulNode->pSFirstChild, ++pcMulTreeStr);
		CreateMulTree(pSTree, prSMulNode->pSSibling, ++pcMulTreeStr);
	}
}
SMulNode* FindMulTreeRoot(SMulTree* pSTree)
{
	return pSTree->pSRoot;
}
SMulNode* FindFirstChild(SMulTree* pSTree)
{
	return FindFirstChild(pSTree->pSRoot);
}
SMulNode* FindFirstChild(SMulNode* pSMulNode)
{
	if (pSMulNode == NULL)
		return NULL;
	return pSMulNode->pSFirstChild;
}
SMulNode* FindSibling(SMulTree* pSTree)
{
	return FindSibling(pSTree->pSRoot);
}
SMulNode* FindSibling(SMulNode* pSMulNode)
{
	if (pSMulNode == NULL)
		return NULL;
	return pSMulNode->pSSibling;
}
SMulNode* FindKey(SMulTree* pSTree, ElemType DKey)
{
	return FindKey(pSTree->pSRoot, DKey);
}
SMulNode* FindKey(SMulNode* pSMulNode, ElemType DKey)
{
	if (pSMulNode == NULL)
		return NULL;
	if (pSMulNode->data == DKey)
		return pSMulNode;

	SMulNode* pSKeyNode = FindKey(pSMulNode->pSFirstChild, DKey);
	if (pSKeyNode != NULL)
		return pSKeyNode;
	return FindKey(pSMulNode->pSSibling,DKey);
}
SMulNode* FindParent(SMulTree* pSTree, SMulNode* pSFinderNode)
{
	return FindParent(pSTree->pSRoot,pSFinderNode);
}
SMulNode* FindParent(SMulNode* pSMulNode, SMulNode* pSFinderNode)
{
	if (pSFinderNode == NULL || pSMulNode == pSFinderNode || pSMulNode == NULL)
		return NULL;

	SMulNode* pSNextNode = pSMulNode->pSFirstChild;
	SMulNode* pSParent;
	while (pSFinderNode!=NULL && pSFinderNode!=pSFinderNode)
	{
		pSParent = FindParent(pSNextNode, pSFinderNode);
		if (pSParent != NULL)
			return pSParent;
		pSNextNode = pSFinderNode->pSSibling;
	}
	if (pSNextNode != NULL && pSFinderNode == pSFinderNode)
		return pSMulNode;
	return NULL;
}