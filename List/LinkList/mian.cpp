#include<iostream>
#include<stdio.h>
#include"LinkList.h"

int main()//Lnode:����һ��ͷ���ָ��LNode����һ�����
{
	Lnode mylinklist;
	InitList(&mylinklist);
	CreatList(&mylinklist);
	ShowList(mylinklist);
}

