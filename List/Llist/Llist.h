#ifndef _LLIST_H_
#define _LLIST_H_
#define ElemType int

#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<assert.h>
#include<string>

typedef struct Node
{
	ElemType		data;
	struct Node*	next;
}Node;

typedef Node* ToNode;//不用再给*了,直接指向结点

typedef struct List
{
	ToNode first;
	ToNode last;
	size_t size;
}List;

void ListInit(List *mylist);
void push_back(List* mylist, ElemType e);
void show_list(List *mylist);
void push_front(List* mylist, ElemType e);
void pop_back(List* mylist);
void pop_front(List* mylist);
void insert_val(List* mylist,ElemType e);
ToNode find(List* mylist, ElemType e);
int	 length(List* mylist);
void delete_value(List* mylist, ElemType e);
void sort(List* mylist);
void reverse(List* mylist);
void clear(List* mylist);
void destory(List* mylist);

/////////////////////////改进版/////////////////////////////////
typedef Node* It;
ToNode _buyNode(ElemType e);
It begin(List* mylist);
It end(List* mylist);
void insert(List* mylist, It pos, ElemType e);
#endif _LLIST_H_

