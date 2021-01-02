#include "LinkList.h"
#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;

void InitList(Lnode *head)//必须使用指针传递才能真正改变
{
	//*head = NULL;
	*head = (LNode*)malloc(sizeof(LNode));
	(*head)->data = 0;
	(*head)->next = NULL;
}

void CreatList(Lnode* head)//尾插法需要p指针
{
	LNode* p = *head;
	for (int i = 1;i < 10;++i)
	{
		p = p->next = (LNode*)malloc(sizeof(LNode));
		assert(p != NULL);//必须断言
		p->data = i;
		p->next = NULL;
	}
	//*head = (LNode*)malloc(sizeof(LNode));
	//assert(*head != NULL);
	//(*head)->data = 1;//加括号因为指针比->访问低一级
	//(*head)->next = NULL;

	//Lnode p = *head;
	//for (int i = 2;i < 10;++i)
	//{
	//	Lnode s = (LNode*)malloc(sizeof(LNode));
	//	assert(s != NULL);
	//	s->data = i;
	//	s->next = NULL;

	//	p->next = s;
	//	p = s;
	//}

}

void ShowList(Lnode head)
{
	LNode *p = head->next;
	while (p != NULL)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void ReCreatList(Lnode* head)//头插不需要p指针
{
	for (int i = 1;i < 10;++i)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		s->next = (*head)->next;
		(*head)->next = s;
	}
	//*head = (LNode*)malloc(sizeof(LNode));
	//assert(*head != NULL);
	//(*head)->data = 1;
	//(*head)->next = NULL;

	//for (int i = 1;i < 10;++i)
	//{
	//	LNode* s = (LNode*)malloc(sizeof(LNode));
	//	assert(s != NULL);
	//	s->data = i;
	//	s->next = NULL;
	//	//尾插法核心
	//	s->next = *head;
	//	*head = s;
	//}
}