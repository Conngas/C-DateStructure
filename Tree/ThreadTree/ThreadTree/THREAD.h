#pragma once
#ifndef THREAD_H
#define THREAD_H

#include<iostream>
#include<malloc.h>
#include<assert.h>

#define ElemType char

typedef enum {LINK,THREAD}Tag_Type;
//typedef enum class {LINK,THREAD}Tag_Type;

typedef struct ThreadTreeNode
{
	ElemType data;
	struct ThreadTreeNode* LeftChild;
	struct ThreadTreeNode* RightChild;
	Tag_Type leftTag;
	Tag_Type rightTag;
}ThreadTreeNode;

typedef struct ThreadTree
{
	ThreadTreeNode* root;
	ElemType refvalue;
}ThreadTree;

void InitTreadTree(ThreadTree* my_tree, ElemType ref);
void CreateThreadTree(ThreadTree* my_tree, const char* c);
void CreateThreadTree(ThreadTree* my_tree, ThreadTreeNode*& node,const char*& c);
ThreadTreeNode* _BuyNode(ElemType c);
void CreateInThread(ThreadTree* my_tree);
void CreateInThread(ThreadTreeNode*& node, ThreadTreeNode*& pre);

///2
ThreadTreeNode* FirstNode(ThreadTree* bt);
ThreadTreeNode* FirstNode(ThreadTreeNode* bt);
ThreadTreeNode* LastNode(ThreadTree* bt);
ThreadTreeNode* LastNode(ThreadTreeNode* bt);
ThreadTreeNode* NextNode(ThreadTree* bt,ThreadTreeNode *cur);
ThreadTreeNode* NextNode(ThreadTreeNode* bt, ThreadTreeNode* cur);
ThreadTreeNode* PrioNode(ThreadTree* bt, ThreadTreeNode* cur);
ThreadTreeNode* PrioNode(ThreadTreeNode* bt, ThreadTreeNode* cur);
void InOrder(ThreadTree *bt);
void InOrder(ThreadTreeNode* bt);
ThreadTreeNode* Search(ThreadTree* bt, ElemType key);
ThreadTreeNode* Search(ThreadTreeNode* bt, ElemType key);
ThreadTreeNode* Parents(ThreadTree* bt, ThreadTreeNode* cur);
ThreadTreeNode* Parents(ThreadTreeNode* bt, ThreadTreeNode* cur);

#endif // !THREAD_H


