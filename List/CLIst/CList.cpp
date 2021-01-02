#include"Clist.h"

void InitLinkList(List* mylist)
{
	ToNode p = (Node*)malloc(sizeof(Node));
	mylist->first = p;
	mylist->last = p;
	mylist->size = 0;
	mylist->last->next = p;
}

ToNode buyNode(ElemType e)
{
	ToNode p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);
	p->next = NULL;
	p->data = e;
	return p;
}

void Push_back(List* mylist, ElemType e)
{
	ToNode s = buyNode(e);
	mylist->last->next = s;
	mylist->last = s;
	s->next = mylist->first;
	mylist->size++;
}

void Push_front(List* mylist, ElemType e)
{
	ToNode s = buyNode(e);
	
	s->next = mylist->first->next;
	mylist->first->next = s;
	if (mylist->size == 0)//mylist->first = mylist->last
		mylist->last = s;
	mylist->size++;
}

void Show_List(List* mylist)
{
	ToNode p = mylist->first->next;
	while (p != mylist->first)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NUL" << endl;
}

void pop_back(List* mylist)
{
	if (mylist->size == 0)
		cout << "链表已空，无需删除" << endl;
	ToNode p = mylist->first;//如果直接p为mylist->first->next就要考虑删到最后头尾归一的问题
	while (p->next != mylist->last)
	{
		p = p->next;
	}
	free(mylist->last);
	mylist->last = p;
	p->next = mylist->first;
	//if(mylist->first == 1) mylist->last = mylist->first
	mylist->size--;
}

void pop_front(List* mylist)
{
	if (mylist->size == 0)
		cout << "链表已空，无需删除" << endl;
	ToNode p = mylist->first->next;
	mylist->first->next = p->next;
	free(p);
	if (mylist->size == 1)
		mylist->last = mylist->first;
	mylist->size--;
}

void insert_val(List* mylist, ElemType e)
{
	ToNode p = mylist->first;
	while (p->next != mylist->last && p->next->data <= e)
	{
		p = p->next;
	}
	if (p->next == mylist->last && p->next->data <= e )//不添加数据比较就会落入倒数第二位置
	{
		Push_back(mylist, e);
	}
	else
	{
		ToNode s = buyNode(e);
		s->next = p->next;
		p->next = s;

		mylist->size++;
	}
}

ToNode find(List* mylist,ElemType e)
{
	ToNode p = mylist->first->next;
	while (p != mylist->first && p->data != e)
	{
		p = p->next;
	}
	if (p == mylist->first)
	{
		//cout << "未找到数据！" << endl;
		return NULL;
	}
	/*else
	{
		cout << "数据存在!" << endl;
		return p;
	}*/
	return p;
	
}

int Length(List* mylist)
{
	return mylist->size;
}

void delete_val(List* mylist, ElemType e)
{
	ToNode s = find(mylist, e);
	if (mylist->size == 0)
	{
		cout << "无需删除！" << endl;
		return;
	}
	else if (s == NULL)
	{
		cout << "数据不存在！" << endl;
	}
	else if (s == mylist->last)
	{
		pop_back(mylist);
		return;
	}
	else
	{
		ToNode p = s->next;
		s->data = p->data;
		s->next = p->next;
		free(p);
		mylist->size--;
	}
}

void sort(List* mylist)
{
	if (mylist->size == 0 || mylist->size == 1)
	{
		return;
	}
	ToNode s = mylist->first->next;
	ToNode p = s->next;
	ToNode q = mylist->first;

	mylist->last->next = NULL;
	mylist->last = s;
	mylist->last->next = mylist->first;

	while (p != NULL)
	{
		s = p;
		p = p->next;
		q = mylist->first;
		while (q->next != mylist->last && q->next->data < s->data)
			q = q->next;
		if (q->next == mylist->last && q->next->data < s->data)
		{
			s->next = mylist->last->next;
			mylist->last->next = s;
			mylist->last = s;
		}
		else
		{
			s->next = q->next;
			q->next = s;
		}
		

	}
}

void resverse(List* mylist)
{
	if (mylist->size == 1 || mylist->size == 0)
	{
		return;
	}
	else
	{
		ToNode p = mylist->first->next;
		ToNode q = p->next;

		mylist->last->next = NULL;
		mylist->last = p;
		mylist->last->next = mylist->first;

		while (q != NULL)
		{
			p = q;
			q = q->next;

			p->next = mylist->first->next;
			mylist->first->next = p;
			
		}
	}
}

void clear(List* mylist)
{
	ToNode p = mylist->first->next;
	while (p != mylist->first)
	{
		mylist->first->next = p->next;
		free(p);
		p = mylist->first->next;
	}
	mylist->last = mylist->first;
	mylist->last->next = mylist->first;
	mylist->size = 0;
}

void destory(List* mylist)
{
	clear(mylist);
	free(mylist->first);
	mylist->first = mylist->first = NULL;
	mylist->size = 0;
}