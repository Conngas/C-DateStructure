#include"BinTree.h"
#include"Queue.h"

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

void PreOrder(BinTree* bt)
{
	PreOrderNode(bt->Root);
}
void PreOrderNode(BinTreeNode* node)
{
	if (node != NULL)
	{
		printf("%c", node->data);
		PreOrderNode(node->LeftChild);
		PreOrderNode(node->RightChild);
	}
}

void InOrder(BinTree* bt)
{
	InOrderNode(bt->Root);
}
void InOrderNode(BinTreeNode* node)
{
	if (node != NULL)
	{
		PreOrderNode(node->LeftChild);
		printf("%c", node->data);
		PreOrderNode(node->RightChild);
	}
}

void PostOrder(BinTree* bt)
{
	PostOrderNode(bt->Root);
}
void PostOrderNode(BinTreeNode* node)
{
	if (node != NULL)
	{
		PreOrderNode(node->LeftChild);
		PreOrderNode(node->RightChild);
		printf("%c", node->data);
	}
}

void LevelOrder(BinTree* bt)
{
	LevelOrderNode(bt->Root);
}
void LevelOrderNode(BinTreeNode* node)
{
	if (node != NULL)
	{
		BinTreeNode* v=NULL;
		SeqQueue TempQueue;
		InitSeqQueueFun(&TempQueue);
		EnSeqQueueFun(&TempQueue, node);
		while(!SeqQueueIsEmpty(&TempQueue))
		{
			GetHead(&TempQueue, &v);
			DeSeqQueueFun(&TempQueue);
			//printf("%c", v->data);
			printf_s("%c", v->data);
			if (v->LeftChild != NULL)EnSeqQueueFun(&TempQueue, v->LeftChild);
			if (v->RightChild != NULL)EnSeqQueueFun(&TempQueue, v->RightChild);
		}
	}
}

//Fuction
int Size(BinTree* bt)
{
	return Size(bt->Root);
}

int Size(BinTreeNode* node)
{
	if (node == NULL)	return 0;
	else
	{
		return (Size(node->LeftChild) + Size(node->RightChild)) + 1;
	}
}

int Height(BinTree* bt)
{
	return Height(bt->Root);
}

int Height(BinTreeNode* node)
{
	if (node == NULL)return 0;
	else
	{
		int Left_h = Height(node->LeftChild);
		int Right_h = Height(node->RightChild);
		return (Left_h > Right_h ? Left_h:Right_h) + 1;
	}
}

BinTreeNode* Search(BinTree* bt, ElemType key)
{
	return Search(bt->Root,key);
}

BinTreeNode* Search(BinTreeNode* node,ElemType key)
{
	if (node == NULL)return NULL;
	if (node->data == key)return node;
	
	BinTreeNode* p = Search(node->LeftChild, key);
	if (p != NULL)return p;
	else return Search(node->RightChild, key);
}

BinTreeNode* Parent(BinTree* bt, BinTreeNode* node)
{
	return Parent(bt->Root, node);
}

BinTreeNode* Parent(BinTreeNode* bt, BinTreeNode* node)
{
	if (bt == NULL || node == NULL)return NULL;
	if (bt->LeftChild == node || bt->RightChild == node)return bt;

	BinTreeNode* q = Parent(bt->LeftChild, node);
	if (q != NULL)return q;

	return Parent(bt->RightChild, node);
}

BinTreeNode* LeftChild(BinTreeNode* node)
{
	if (node != NULL)return node->LeftChild;
	else return NULL;
}

BinTreeNode* RightChild(BinTreeNode* node)
{
	if (node != NULL)return node->RightChild;
	else return NULL;
}

bool IsEmpty(BinTree* bt)
{
	return bt->Root == NULL;
}

void Copy(BinTree* s, BinTree* d)
{
	Copy(s->Root, d->Root);
}

void Copy(BinTreeNode*& source, BinTreeNode*& destination)
{
	if (source == NULL)destination = NULL;
	else
	{
		destination = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(destination != NULL);
		destination->data = source->data;
		Copy(source->LeftChild, destination->LeftChild);
		Copy(source->RightChild, destination->RightChild);
	}

}

void Clear(BinTree* bt)
{
	Clear(bt->Root);
}

void Clear(BinTreeNode*& node)
{
	if (node != NULL)
	{
		Clear(node->LeftChild);
		Clear(node->RightChild);
		free(node);
		node = NULL;
	}
}