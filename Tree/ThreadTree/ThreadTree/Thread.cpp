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


///Part2 Func
ThreadTreeNode* FirstNode(ThreadTree* bt)
{
	return FirstNode(bt->root);
}
ThreadTreeNode* FirstNode(ThreadTreeNode* bt)//根据Ltag判断头结点
{
	if (bt == NULL)return NULL;
	ThreadTreeNode* p=bt;
	while (p->leftTag == LINK)
	{
		p = p->LeftChild;
	}
	return p;
}
ThreadTreeNode* LastNode(ThreadTree* bt)
{
	return LastNode(bt->root);
}
ThreadTreeNode* LastNode(ThreadTreeNode* bt)
{
	if (bt == NULL)return NULL;
	ThreadTreeNode* p = bt;
	while (p->rightTag == LINK)
		p = p->RightChild;
	return p;
}
ThreadTreeNode* NextNode(ThreadTree* bt, ThreadTreeNode* cur)
{
	return NextNode(bt->root,cur);
}
ThreadTreeNode* NextNode(ThreadTreeNode* bt, ThreadTreeNode* cur)
{
	if (bt == NULL || cur == NULL)
		return NULL;
	if (cur->rightTag == THREAD)
		return cur->RightChild;
	return FirstNode(cur->RightChild);
}
ThreadTreeNode* PrioNode(ThreadTree* bt, ThreadTreeNode* cur)
{
	return PrioNode(bt->root, cur);
}
ThreadTreeNode* PrioNode(ThreadTreeNode* bt, ThreadTreeNode* cur)
{
	if (bt == NULL || cur == NULL)
		return NULL;
	if (cur->leftTag == THREAD)
		return cur->LeftChild;
	return LastNode(cur->LeftChild);
}
void InOrder(ThreadTree* bt)
{
	InOrder(bt->root);
}
void InOrder(ThreadTreeNode* bt)
{
	ThreadTreeNode* p;
	for (p = FirstNode(bt);p != NULL; p = NextNode(bt, p))
	{
		printf(" %c ", p->data);
	}
	printf("\n");
}
ThreadTreeNode* Search(ThreadTree* bt, ElemType key)
{
	return Search(bt->root, key);
}
ThreadTreeNode* Search(ThreadTreeNode* bt, ElemType key)
{
	if (key == NULL)
		return NULL;
	if (key == bt->data)
		return bt;
	ThreadTreeNode* p;
	for (p = FirstNode(bt);p != NULL;p = NextNode(bt, p))
	{
		if (key == p->data)
			return p;
	}
	return NULL;
}
ThreadTreeNode* Parents(ThreadTree* bt, ThreadTreeNode* cur)
{
	return Parents(bt->root, cur);
}
ThreadTreeNode* Parents(ThreadTreeNode* bt, ThreadTreeNode* cur)
{
	if (bt == NULL || cur == NULL)return NULL;
	if (bt == cur)return NULL;
	ThreadTreeNode* p;
	if (cur->leftTag == THREAD)
	{
		p = cur->LeftChild;
		if (p->RightChild == cur)return p;
	}
	if (cur->rightTag == THREAD)
	{
		p = cur->RightChild;
		if (p->LeftChild == cur)return p;
	}
	
	p = FirstNode(cur->LeftChild);
	p = p->LeftChild;
	if (p != NULL && p->RightChild == cur)return p;
	p = LastNode(cur->RightChild);
	return p->LeftChild;
}