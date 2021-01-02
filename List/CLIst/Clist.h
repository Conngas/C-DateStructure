#ifndef _H_CLIST_
#define _H_CLIST_

#define ElemType int
#include<iostream>
#include<stdio.h>
#include<assert.h>

using namespace std;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* ToNode;

typedef struct List
{
	ToNode first;
	ToNode last;
	int size;
}List;

void InitLinkList(List* mylist);
void Push_back(List* mylist, ElemType e);
void Push_front(List* mylist, ElemType e);
void Show_List(List* mylist);
void pop_back(List* mylist);
void pop_front(List* mylist);
void insert_val(List* mylist, ElemType e);
ToNode find(List* mylist,ElemType e);
int Length(List* mylist);
void delete_val(List* mylist, ElemType e);
void sort(List* mylist);
void resverse(List* mylist);
void clear(List* mylist);
void destory(List* mylist);

#endif // !_H_CLIST_

