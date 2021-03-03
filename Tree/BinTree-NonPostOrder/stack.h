#pragma once
#ifndef LINKSTACK_H_

#define LINKSTACK_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

struct BinTreeNode;

typedef enum { L, R }Tag;

typedef struct StrkNode
{
	BinTreeNode* node;
	Tag			 tag;
}StrNode;

#define StackElemType StrkNode

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
bool IsEmpty(MyNode* s);
void Clear(MyNode* s);
void PrintOnChar(MyNode* s);

///Stackcpp


void LinkStackInitFun(MyNode* s)
{
	*s = NULL;
}
void Push(MyNode* s, StackElemType x)
{
	MyNode newNode = (MyNode)malloc(sizeof(LinkStackNode));
	assert(newNode != NULL);
	newNode->Data = x;
	if (*s == NULL)
	{
		*s = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *s;
		*s = newNode;
	}
}
void Pop(MyNode* s)
{
	if (s == NULL)
	{
		printf("ջ�գ������ջ��");
		return;
	}
	LinkStackNode* p = *s;
	*s = p->next;
	free(p);
	p = NULL;
}
void Show(MyNode* s)
{
	MyNode p = *s;
	while (p != NULL)
	{
		printf("%d\n", p->Data);
		p = p->next;
	}
}
void GetTop(MyNode* s)
{
	MyNode p = *s;
	printf("%d", p->Data);
}
void GetTopElem(MyNode* s, StackElemType* t)
{
	MyNode p = *s;
	*t = p->Data;
}
bool IsEmpty(MyNode* s)
{
	MyNode p = *s;
	return p == NULL;
}
void Clear(MyNode* s)
{
	MyNode t = *s;
	MyNode p = t->next;
	while (p != NULL)
	{
		free(t);
		t = p;
		p = p->next;
	}
	free(p);
}
void PrintOnChar(MyNode* s)
{
	MyNode p = *s;
	MyNode s4;
	StackElemType tempvalue;
	LinkStackInitFun(&s4);
	while (!IsEmpty(&p))
	{
		GetTopElem(&p, &tempvalue);
		Push(&s4, tempvalue);
		Pop(&p);
	}
	while (s4 != NULL)
	{
		printf("%c", s4->Data);
		s4 = s4->next;
	}
}

#endif // !LINKSTACK_H_

