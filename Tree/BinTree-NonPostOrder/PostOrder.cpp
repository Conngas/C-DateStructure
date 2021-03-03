#include"stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<iostream>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* LeftChild;
	struct BinTreeNode* RightChild;
}BinTreeNode;

typedef struct BinTreeNode* ToChild;

typedef struct BinTree
{
	BinTreeNode* Root;
	ElemType refvalue;//Stop Flag
};

//Init
void InitBinTree(BinTree* bt, ElemType ref);
void CreateBinTree_Str(BinTree* bt, const char* str);
void CreateBinTree_Str(BinTree* bt, BinTreeNode*& node, const char*& str);
void NoPostOrder(BinTree* bt);
void NoPostOrderNode(BinTreeNode* node);
//////////////////////////////////////////////////////////////////////////////
void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->Root = NULL;
	bt->refvalue = ref;
}

void CreateBinTree_Str(BinTree* bt, const char* str)
{
	CreateBinTree_Str(bt, (bt->Root), str);
}

void CreateBinTree_Str(BinTree* bt, BinTreeNode*& node, const char*& str)
{
	if (*str == bt->refvalue)	node = NULL;
	else
	{
		node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(node != NULL);
		node->data = *str;
		CreateBinTree_Str(bt, node->LeftChild, ++str);
		CreateBinTree_Str(bt, node->RightChild, ++str);
	}
}

void NoPostOrder(BinTree* bt)
{
	NoPostOrderNode(bt->Root);
}

void NoPostOrderNode(BinTreeNode* node)
{
	if (node != NULL)
	{
		MyNode MyStack;
		LinkStackInitFun(&MyStack);
		BinTreeNode* p;
		StrkNode sn;
		do
		{
			while (node != NULL)
			{
				sn.node = node;
				sn.tag = L;
				Push(&MyStack, sn);
				node = node->LeftChild;
			}
			bool flag = true;
			while (flag != false && !IsEmpty(&MyStack))
			{
				GetTopElem(&MyStack, &sn);
				Pop(&MyStack);
				p = sn.node;
				switch (sn.tag)
				{
				case L:
					sn.tag = R;
					Push(&MyStack, sn);
					flag = false;
					node = p->RightChild;
					break;
				case R:
					printf("%c", p->data);
					break;
				default:
					break;
				}
			}
		} while (!IsEmpty(&MyStack));
	}
	 
}

///////////////////////////////////////////////////////////////////////

int main()
{
	const char* BTInfo = "ABC##DE##F##G#H##";
	BinTree MyBinTree;
	InitBinTree(&MyBinTree, '#');
	CreateBinTree_Str(&MyBinTree, BTInfo);

	NoPostOrder(&MyBinTree);
	printf("\n");
}