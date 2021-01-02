#include"StaticLink.h"
#include<iostream>

using namespace std;

void InistStatic(StaticList& space)
{
	for (int i = 1;i < MAXSIZE;++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	space[0].cur = -1;
}

void Insert(StaticList& space, ElemType e)
{
	int i = Malloc_Size(space);
	

	if (i == 0)
	{
		cout << "ÁÐ±íÒÑÂú£¡" << endl;
		return;
	}
	space[i].data = e;
	if(space[0].cur==-1)
	{
		//space[0].cur = i;
		space[i].cur = -1;
	}
	else
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
}

int Malloc_Size(StaticList& space)
{
	int i = space[1].cur;
	if (space[1].cur != 0)
	{
		space[1].cur = space[i].cur;
	}
	return i;
}

void Free_Size(StaticList& space, int y)
{
	space[y].cur = space[1].cur;
	space[1].cur = y;
}

void Show_Static(StaticList& space)
{
	int i = space[0].cur;
	while (i != -1)
	{
		printf("%c->", space[i].data);
		i = space[i].cur;
	}
	cout << "NULL" << endl;
}

void Delete(StaticList& space)
{
	/*int i = space[0].cur;
	space[i].cur = space[1].cur;
	space[1].cur = i;
	i = space[i].cur;
	space[0].cur = space[i].cur;*/

	int i = space[0].cur;
	space[0].cur = space[i].cur;
	Free_Size(space, i);

	/*int i = space[0].cur;
	space[0].cur = space[i].cur;
	space[i].cur = space[1].cur;
	space[1].cur = i;*/
}