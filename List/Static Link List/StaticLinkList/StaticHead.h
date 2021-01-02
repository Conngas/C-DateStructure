#ifndef StaticHead_H
#define StaticHead_H

#include <stdio.h>
#define MAX 20
#define ElemType char

typedef struct LinkNode
{
	ElemType data;
	int cur;
}LinkNode;
typedef LinkNode StaticLinkList[MAX];

int malloc_SL(StaticLinkList &space);
void free_SL(StaticLinkList& sapce);

void InitStatic(StaticLinkList& space);
void InsertStatic(StaticLinkList& space, ElemType x);
void ListShow(StaticLinkList& space);
void DeleteList(StaticLinkList& space);
#endif // !StaticHead_H

