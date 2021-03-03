#pragma once
#ifndef LINKSTACK_H_

#define LINKSTACK_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

struct BinTreeNode;

#define StackElemType BinTreeNode*

typedef struct LinkStackNode
{
	StackElemType Data;
	struct LinkStackNode* next;
}LinkStackNode;

typedef LinkStackNode* MyNode;

void LinkStackInitFun(MyNode* s);
void Push(MyNode* s, StackElemType x);
void Show(MyNode* s);
void Pop(MyNode* s);
void GetTop(MyNode* s);
void GetTopElem(MyNode* s, StackElemType* t);
bool IsEmpty(MyNode*s);
void Clear(MyNode* s);
void PrintOnChar(MyNode* s);


#endif // !LINKSTACK_H_

