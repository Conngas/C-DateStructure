#include"DulHead.h"

int InitList(MyDulList *List)
{
	ToNode p = (Node*)malloc(sizeof(Node));
	List->first = List->last = p;
	List->size = 0;
	p->pre = p->next = NULL;
	p->data = 0;
	return 0;
}

Node* Buy_Node(ElemType e)
{
	ToNode s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = e;
	s->next = s->pre = NULL;
	return s;
}

int Push_back(MyDulList* List, ElemType e)
{
	ToNode s = Buy_Node(e);
	s->pre = List->last;
	List->last->next = s;
	List->last = s;
	List->size++;
	return 0;
}

int Show_list(MyDulList* List)
{
	ToNode p = List->first->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Null\n");
	return 0;
}

int Push_Front(MyDulList* List, ElemType e)
{
	ToNode s = Buy_Node(e);
	/*if (List->first->next == NULL) 功能一样，不过下面的更严谨
	{
		Push_back(List, e);
	}*/
	if (List->first == List->last)
	{
		s->pre = List->first;
		List->first->next = s;
		List->last = s;
	}
	else
	{
		s->next = List->first->next;
		List->first->next->pre = s;
		List->first->next = s;
		s->pre = List->first;
		List->size++;
	}
	//List->first->next = s;
	//List->first->next->pre = s;
	return 0;
}

int Pop_back(MyDulList* List)
{
	if (List->size == 0)
		return 0;

	ToNode d = List->last;
	List->last = List->last->pre;
	d->pre->next  = NULL;
	d->pre = NULL;
	free(d);
	d = NULL;
	List->size--;
	return 0;
}

int Pop_front(MyDulList* List)
{
	if (List->first == List->last)
		return 0;
	ToNode d = List->first->next;
	if (List->first->next == List->last)
	{
		List->last = List->first;
		List->first = List->last = NULL;
	}
	else
	{
		List->first->next = d->next;
		d->next->pre = List->first;
	}
	free(d);
	d = NULL;
	List->size--;
	return 0;
}

int insert_val(MyDulList* List, ElemType e)
{
	ToNode p = List->first;
	ToNode s = Buy_Node(e);
	while (p->next != NULL  && p->next->data <= e)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		p->next = s;
		s->pre = p;
		List->last = s;
	}
	else
	{
		s->next = p->next;
		p->next->pre = s;
		p->next = s;
		s->pre = p;
	}	
	List->size++;
	return 0;
}

int find(MyDulList* List,ElemType e)
{
	ToNode p = List->first->next;
	while (p != NULL && p->data != e)//切不可吧为空与不为关键值搞反，有数据的前提是不为空
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	return p->data;
}

int length(MyDulList* List)
{
	return List->size;
}

int Delete_val(MyDulList* List, ElemType e)
{
	if (List == NULL)
	{
		printf("不需要删除数据！");
		return 0;
	}
	ToNode p = List->first->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("输入的数据无法找到，请重新尝试\n");
		return 0;
	}
	else if (p->next == NULL)
	{
		List->last = p->pre;
		List->last->next = NULL;
		
	}
	else
	{
		p->pre->next = p->next;
		p->next->pre = p->pre;
	}
		free(p);
		p = NULL;
		List->size--;
		return 0;
}

int Sort(MyDulList* List)
{
	if (List->size == 0 || List->size == 1)
	{
		printf("无需排序！");
		return 0;
	}

	ToNode a = List->first;
	ToNode b = List->first->next;
	ToNode t;

	List->last = a;
	a->next = NULL;

	while (b != NULL)
	{	
		a = b;
		b = b->next;

		t = List->first;
		while (t->next != NULL && t->next->data <= a->data)
		{
			t = t->next;
		}
		if (t->next == NULL)
		{
			t->next = a;
			a->pre = t;
			List->last = a;
			List->last->next = NULL;
		}
		else
		{
			t->next->pre = a;
			a->next = t->next;
			t->next = a;
			a->pre = t;
		}
	}
	return 0;
}

int Inverse(MyDulList* List)
{
	if (List->size == 0 || List->size == 1)
	{
		printf("无需逆置！");
		return 0;
	}
	ToNode a = List->first->next;
	ToNode b = a->next;

	List->last = a;
	a->next = NULL;

	while (b != NULL)
	{
		a = b;
		b = b->next;

		List->first->next->pre = a;
		a->next = List->first->next;

		List->first->next = a;
		a->pre = List->first;
	}
	return 0;
}

int Clear(MyDulList* List)
{
	if (List->size == 0)
	{
		printf("不必删除！");
		return 0;
	}
	ToNode p = List->first->next;
	while (p != NULL)
	{
		
		if (p->next == NULL)
		{
			List->last = p->pre;
			List->last->next = NULL;
		}
		else
		{
			p->next->pre = List->first;
			List->first->next = p->next;
		}

		free(p);
		p = List->first->next;
	}
	List->size = 0;
	return 0;
}

int Destroy(MyDulList* List)
{
	Clear(List);
	free(List->first);
	List->first = List->last = NULL;
	List->size = 0;
	return 0;
}