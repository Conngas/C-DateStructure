#include"THREAD.h"

void InitTreadTree(ThreadTree* my_tree, ElemType ref)
{
	my_tree->root = NULL;
	my_tree->refvalue = ref;
}

void CreateThreadTree(ThreadTree* my_tree, const char* c)
{
	CreateThreadTree(my_tree, my_tree->root, c);
}
void CreateThreadTree(ThreadTree* my_tree, ThreadTreeNode*& node, const char*& c)
{
	if (*c == my_tree->refvalue)
		node = NULL;
	else
	{
		node = _BuyNode(*c);
		CreateThreadTree(my_tree, node->LeftChild, ++c);
		CreateThreadTree(my_tree, node->RightChild, ++c);
	}
}
void CreateInThread(ThreadTree* my_tree)
{
	ThreadTreeNode* pre = NULL;
	CreateInThread(my_tree->root, pre);
	pre->rightTag = THREAD;
	pre->RightChild = NULL;
}
void CreateInThread(ThreadTreeNode*& node, ThreadTreeNode*& pre)
{
	if (node == NULL)
		return;
	CreateInThread(node->LeftChild, pre);
	if (node->LeftChild == NULL)
	{
		node->leftTag = THREAD;
		node->LeftChild = pre;
	}
	if (pre!= NULL && pre->RightChild == NULL)
	{
		pre->rightTag = THREAD;
		pre->RightChild = node;
	}
	pre = node;
	CreateInThread(node->RightChild, pre);
}

///Tools
ThreadTreeNode* _BuyNode(ElemType c)
{
	ThreadTreeNode* s = (ThreadTreeNode*)malloc(sizeof(ThreadTreeNode));
	assert(s != NULL);
	s->LeftChild = s->RightChild = NULL;
	s->data = c;
	s->leftTag = s->rightTag = LINK;
	return s;
}