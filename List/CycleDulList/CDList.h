#pragma once
#ifndef _CDLIST_H_
#define _CDLIST_H_
#define ElemType int

#include<iostream>
#include<assert.h>


using namespace std;

typedef struct Node
{
	ElemType data;
	struct Node* next;
	struct Node* pre;
}Node;

typedef struct Node* ToNode;

typedef struct List
{
	struct Node* first;
	struct Node* last;
	int size;
}CDList;

ToNode BuyNode();
int InitList(CDList* List);
int Push_back(CDList* List, ElemType e);
int Push_Front(CDList* List, ElemType e);
int Show(CDList* List);
int Pop_back(CDList* List);
int Pop_front(CDList* List);
int Insert_val(CDList* List, ElemType e);
ToNode find(CDList* List, ElemType e);
int length(CDList* List);
int Sort(CDList* List);
int Reverse(CDList* List);
int DeletVal(CDList* List, ElemType e);
int AClear(CDList* List);
int SClear(CDList* List);
int Delete(CDList* List);

#endif // !_CDLIST_H_
