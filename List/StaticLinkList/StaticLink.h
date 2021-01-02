#ifndef StaticLinkList_H
#define StaticLinkLIst_H
#define MAXSIZE 20

typedef int ElemType;

typedef struct StaticLinkListNode
{
	ElemType	data;
	int			cur;
}ListNode;

typedef ListNode StaticList[MAXSIZE];

int Malloc_Size(StaticList& space);
void Free_Size(StaticList& space, int y);

void InistStatic(StaticList& space);
void Insert(StaticList& space, ElemType e);
void Show_Static(StaticList& space);
void Delete(StaticList& space);

#endif // !StaticLinkList_H
