#ifndef _SLIST_H_
#define _SLIST_H_
#include<stdio.h>

#define SQLIST_SIZE 8
#define INCREASE 3
typedef int ElemType;


typedef struct Sqlist
{
	ElemType*	base;//指向初始值
	int			capcity;//容量
	int			size;//大小
}Sqlist;
bool INC(Sqlist* mysqlist);

void InitSqlist(Sqlist *mysqlist);
void push_back(Sqlist* mysqlist, ElemType e);
void push_front(Sqlist* mysqlist, ElemType e);
void pop_back(Sqlist* mysqlist);
void pop_front(Sqlist* mysqlist);
void show_list(Sqlist* mysqlist);
void insert_pos(Sqlist* mysqlist, int pos, ElemType e);
int	 find(Sqlist* mysqlist, ElemType e);
int  length(Sqlist* mysqlist);

void delete_pos(Sqlist* mysqlist, int pos);
void sort(Sqlist* mysqlist);
void resver(Sqlist* mysqlist);
void clear(Sqlist* mysqlist);
void destory(Sqlist* mysqlist);
void merge(Sqlist* list, Sqlist* la, Sqlist* lb);

#endif  _SLIST_H_