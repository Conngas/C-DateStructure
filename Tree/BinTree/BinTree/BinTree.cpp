#include"BinTree.h"

void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->Root = NULL;
	bt->refvalue = ref;
}

void CreateBinTree(BinTree* bt)
{
	//printf("%c", (*bt).refvalue);
	//printf("%c", bt->refvalue);
	//printf("%c", bt.refvalue);
	//printf("%c", (*bt)->refvalue);

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

void CreateBinTree_C(BinTree* bt)
{
	CreateBinTree_C_1(bt, &(bt->Root));
}

void CreateBinTree_C_1(BinTree* bt, ToChild* node)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (bt->refvalue == Item) node = NULL;
	else
	{
		*node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*node != NULL);
		(*node)->data = Item;
		CreateBinTree_C_1(bt, &(*node)->LeftChild);
		CreateBinTree_C_1(bt, &(*node)->RightChild);
	}
}

void CreateBinTree_C_2(BinTree* bt)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (bt->refvalue == Item) bt->Root = NULL;
	else
	{
		bt->Root = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(bt->Root != NULL);
		CreateBinTree_C_2(bt);
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

void CreateBinTree_Node(BinTree* bt)
{
	bt->Root = CreateBinTree_Node_(bt);
}

BinTreeNode* CreateBinTree_Node_(BinTree* bt)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (bt->refvalue == Item)	return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = Item;
		t->LeftChild = CreateBinTree_Node_(bt);
		t->RightChild = CreateBinTree_Node_(bt);
		return t;
	}
}

void CreateBinTree_Str(BinTree* bt, const char* str)
{
	CreateBinTree_Str(bt, (bt->Root), str);
}

void CreateBinTree_Str(BinTree* bt, BinTreeNode*& node, const char* &str)
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

