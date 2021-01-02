#pragma once
#ifndef CPPSTACK_H_
#define CPPSTACK_H_

#include<iostream>
using namespace std;

#define ElemType int

typedef struct Node
{
	ElemType Data;
	struct Node* next;
	Node(ElemType x=0)
	{
		Data = x;
		next = NULL;
	}
}Node;

typedef Node* ToNode;

void InitStack(ToNode& s);
void Push(ToNode& s, ElemType x);
void Pop(ToNode&s);
void Show(ToNode& s);
#endif // !CPPSTACK_H_

