#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#define ElemType int

#include <iostream>
#include<stdio.h>



typedef struct LNode
{
	ElemType	data;
	struct		LNode* next;
}LNode;

typedef LNode* Lnode;

void InitList(Lnode *head);
void CreatList(Lnode* head);
void ShowList(Lnode head);
void ReCreatList(Lnode* head);





#endif _LINKLIST_H_
