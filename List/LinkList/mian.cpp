#include<iostream>
#include<stdio.h>
#include"LinkList.h"

int main()//Lnode:定义一个头结点指向，LNode定义一个结点
{
	Lnode mylinklist;
	InitList(&mylinklist);
	CreatList(&mylinklist);
	ShowList(mylinklist);
}

