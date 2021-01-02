#include"Slist.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<iostream>
using namespace std;

bool INC(Sqlist* mysqlist)
{
	ElemType* newbase = (ElemType*)realloc(mysqlist->base, sizeof(ElemType) *(mysqlist->capcity + INCREASE));
	if (newbase == NULL)
	{
		cout << "分配内存失败，内存不足！" << endl;
		return false;
	}
	mysqlist->capcity += INCREASE;
	mysqlist->base = newbase;
	return true;
}

void InitSqlist(Sqlist* mysqlist)
{
	mysqlist->base = (ElemType*)malloc(SQLIST_SIZE * sizeof(ElemType));
	assert(mysqlist->base != NULL);
	mysqlist->capcity = SQLIST_SIZE;
	mysqlist->size = 0;
}
void push_back(Sqlist*mysqlist, ElemType e)
{
	if (mysqlist->size >= mysqlist->capcity  && !INC(mysqlist))
	{
		cout << "尾插空间已满，请另寻他法！" << endl;
		return;
	}
	mysqlist->base[mysqlist->size] = e;
	mysqlist->size++;
}
void push_front(Sqlist* mysqlist, ElemType e)
{
	if (mysqlist->size >= mysqlist->capcity && !INC(mysqlist))
	{
		cout << "头插空间已满，请另寻他法！" << endl;
		return;
	}
	for (int i = mysqlist->size;i > 0;--i)
	{
		mysqlist->base[i] = mysqlist->base[i - 1];
	}
	mysqlist->base[0] = e;
	mysqlist->size++;
}

void show_list(Sqlist* mysqlist)
{
	for (int i = 0;i < mysqlist->size;++i)
	{
		cout << mysqlist->base[i] << "->";
	}
	cout << endl;
}

void pop_back(Sqlist* mysqlist)
{
	if (mysqlist->size == 0)
	{
		cout << "尾删没有数据，请输入数据在删除" << endl;
		return;
	}
	mysqlist->size--;
}

void pop_front(Sqlist* mysqlist)
{
	if (mysqlist->size == 0)
	{
		cout << "头删没有数据，请输入数据在删除" << endl;
		return;
	}
	for (int i = 0;i < mysqlist->size - 1;++i)
	{
		mysqlist->base[i] = mysqlist->base[i + 1];
	}
	mysqlist->size--;
}

void insert_pos(Sqlist* mysqlist, int pos, ElemType e)//无边界判定条件
{
	if (pos <0 || pos>mysqlist->size)
	{
		cout << "输入位置失败，请重新输入" << endl;
		return;
	}
	if (mysqlist->size >= mysqlist->capcity && !INC(mysqlist))
	{
		cout << "头插空间已满，请另寻他法！" << endl;
		return;
	}

	for (int i = mysqlist->size; i > pos;--i)
	{
		mysqlist->base[i] = mysqlist->base[i + 1];
	}
	mysqlist->base[pos] = e;
	mysqlist->size++;
}

int	 find(Sqlist* mysqlist, ElemType e) 
{
	for (int i = 0;i < mysqlist->size;++i)
	{
		if (mysqlist->base[i] == e)
			return i;
	}
	return -1;
}

int  length(Sqlist* mysqlist)
{
	return mysqlist->size;
}

void delete_pos(Sqlist* mysqlist, int pos)
{
	if (pos<0 || pos>mysqlist->size-1)
	{
		cout << "输入位置不正确，不能够进行删除" << endl;
		return;
	}
	for (int i = pos;i < mysqlist->size-1;++i)
	{
		mysqlist->base[i] = mysqlist->base[i + 1];
	}
	mysqlist->size--;
}

void sort(Sqlist* mysqlist)
{
	for (int i = 0;i < mysqlist->size;++i)
	{
		for (int j = 0;j < mysqlist->size - i - 1;++j)
		{
			if (mysqlist->base[j] > mysqlist->base[j + 1])
			{
				ElemType temp = mysqlist->base[j];
				mysqlist->base[j] = mysqlist->base[j + 1];
				mysqlist->base[j + 1] = temp;
			}
		}
	}
}

void resver(Sqlist* mysqlist)//高低指针置换
{
	if (mysqlist->size == 0 || mysqlist->size == 1)
		return;
	ElemType temp;
	int low = 0;
	int high = mysqlist->size - 1;
	/*for (int i = 0;i < mysqlist->size;++i)
	{
		if (low < high)
			{
				temp = mysqlist->base[low];
				mysqlist->base[low] = mysqlist->base[high];
				mysqlist->base[high] = temp;
				low++;
				high--;
			}
	}*/
	while (low < high)
	{
		temp = mysqlist->base[low];
		mysqlist->base[low] = mysqlist->base[high];
		mysqlist->base[high] = temp;
		low++;
		high--;
	}
}

void clear(Sqlist* mysqlist)
{
	mysqlist->size = 0;
}

void destory(Sqlist* mysqlist)
{
	free(mysqlist->base);
	mysqlist->base = NULL;
	mysqlist->capcity = 0;
	mysqlist->size = 0;
}

void merge(Sqlist* list, Sqlist* la, Sqlist* lb)
{
	int ia=0;
	int ib=0;
	int ic=0;
	list->capcity = la->capcity + lb->capcity;

	while (ic < la->size && ib < la->size)
	{
		if (la->base[ia] > lb->base[ib])
		{
			list->base[ic++] = lb->base[ib++];
		}
		else
		{
			list->base[ic++] = la->base[ia];
		}
	}
	while (ia < la->size)
	{
		list->base[ic++] = la->base[ia++];
	}
	while (ib < lb->size)
	{
		list->base[ic++] = lb->base[ib++];
	}

	list->size = la->size + lb->size;
}