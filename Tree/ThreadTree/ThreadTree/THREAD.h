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

#endif // !THREAD_H


