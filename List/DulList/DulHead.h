#ifndef _DULHEAD_H_
#define _DULHEAD_H_

#define ElemType int

#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


using namespace std;

typedef struct Node
{
	ElemType data;
	struct Node* pre;
	struct Node* next;
}Node;

typedef Node* ToNode;

typedef struct MyDulList
{
	ToNode first;
	ToNode last;
	int size;	
}MyDulList;

Node* Buy_Node(ElemType e);

int InitList(MyDulList *List);
int Push_back(MyDulList* List, ElemType e);
int Show_list(MyDulList* List);
int Push_Front(MyDulList* List, ElemType e);
int Pop_back(MyDulList* List);
int Pop_front(MyDulList* List);
int insert_val(MyDulList* List, ElemType e);
int find(MyDulList*List,ElemType e);
int length(MyDulList* List);
int Delete_val(MyDulList* List, ElemType e);
int Sort(MyDulList* List);
int Inverse(MyDulList* List);
int Clear(MyDulList* List);
int Destory(MyDulList* List);

#endif // _DULHEAD_H_

