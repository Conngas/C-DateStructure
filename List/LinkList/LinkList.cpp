#include "LinkList.h"
#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;

void InitList(Lnode *head)//����ʹ��ָ�봫�ݲ��������ı�
{
	//*head = NULL;
	*head = (LNode*)malloc(sizeof(LNode));
	(*head)->data = 0;
	(*head)->next = NULL;
}

void CreatList(Lnode* head)//β�巨��Ҫpָ��
{
	LNode* p = *head;
	for (int i = 1;i < 10;++i)
	{
		p = p->next = (LNode*)malloc(sizeof(LNode));
		assert(p != NULL);//�������
		p->data = i;
		p->next = NULL;
	}
	//*head = (LNode*)malloc(sizeof(LNode));
	//assert(*head != NULL);
	//(*head)->data = 1;//��������Ϊָ���->���ʵ�һ��
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

void ReCreatList(Lnode* head)//ͷ�岻��Ҫpָ��
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
	//	//β�巨����
	//	s->next = *head;
	//	*head = s;
	//}
}