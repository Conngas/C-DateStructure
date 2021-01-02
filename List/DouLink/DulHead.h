#ifndef _DULHEAD_H_
#define _DULHEAD_H_
#define ElemType int

#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<assert.h>

using namespace std;



typedef struct Node
{
	ElemType data;
	struct Node* prio;
	struct Node* next;
}Node;

typedef Node* ToNode;

typedef struct List
{
	ToNode first;
	ToNode last;
	int	   size;
}MyList;

void InitList(List* mylist);

#endif // !_DULHEAD_H_

