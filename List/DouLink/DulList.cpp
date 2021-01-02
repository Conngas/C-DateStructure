#include"DulHead.h"

void InitList(List* myList)
{
	ToNode s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	myList->first = myList->last = s;
	s->next = s->prio = NULL;
	myList->size = 0;
}