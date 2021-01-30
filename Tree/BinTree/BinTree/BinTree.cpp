#include"BinTree.h"

void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->Root = NULL;
	bt->refvalue = ref;
}

void CreateBinTree(BinTree* bt)
{
	CreateBinTree(bt, &(bt->Root));
}

void CreateBinTree(BinTree* bt, BinTreeNode** node)//node  =  bt->root
{
	ElemType Item;
	if(!scanf_s("%c", &Item)) exit(-1);
	if (bt->refvalue == Item) (*node) = NULL;
	else
	{
		(*node) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*node != NULL);
		(*node)->data = Item;
		CreateBinTree(bt, &((*node)->LeftChild));
		CreateBinTree(bt, &((*node)->RightChild));
	}
}

//void CreateBinTree_C(BinTree* bt)
//{
//	CreateBinTree_C(bt, bt->Root);
//}
//void CreateBinTree_C(BinTree* bt, ToChild node)
//{
//	ElemType Item;
//	scanf_s("%c", &Item);
//	if (bt->refvalue == Item) node = NULL;
//	else
//	{
//		node = (ToChild)malloc(sizeof(BinTreeNode));
//		assert(node != NULL);
//		CreateBinTree_C(bt, node->LeftChild);
//		CreateBinTree_C(bt, node->RightChild);
//	}
//}

void CreateBinTree_Cpp(BinTree* bt)
{
	CreateBinTree_Cpp(bt, bt->Root);
}

void CreateBinTree_Cpp(BinTree* bt, BinTreeNode*& node)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (bt->refvalue == Item)	node = NULL;
	else
	{
		node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(node != NULL);
		node->data = Item;
		CreateBinTree_Cpp(bt, node->LeftChild);
		CreateBinTree_Cpp(bt, node->RightChild);
	}
}

