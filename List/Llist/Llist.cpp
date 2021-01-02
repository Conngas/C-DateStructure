#include"Llist.h"

using namespace std;

void ListInit(List *mylist)
{
	mylist->first = mylist->last = (Node*)malloc(sizeof(Node));
	assert(mylist->first != NULL);
	mylist->first->next = NULL;//重要！
	mylist->size = 0;
}

//void push_back(List* mylist, ElemType e)//插入要用指针指引。
//{
//	ToNode s = _buyNode(e);
//	/*
//	ToNode s = (Node*)malloc(sizeof(Node));
//	assert(s != NULL);
//	s->data = e;
//	s->next = NULL;
//	*/
//
//	mylist->last->next = s;//增加结点
//	mylist->last= s;//更新最后结点
//	mylist->size++;
//}

void push_back(List* mylist, ElemType e)//改进的插入
{
	insert(mylist, end(mylist), e);
}

void show_list(List *mylist)//注意当头插无结点时，挪位尾指针
{
	ToNode p = mylist->first->next;
	while (p != NULL)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NUl." << endl;
}

//void push_front(List* mylist, ElemType e)
//{
//	ToNode s = _buyNode(e);
//	/*
//	ToNode s = (Node*)malloc(sizeof(Node));
//	s->data = e;
//	*/
//	
//	s->next = mylist->first->next;
//	mylist->first->next = s;
//	if (mylist->size == 0)
//	{
//		mylist->last = s;
//	}
//	mylist->size++;
//}

void push_front(List* mylist, ElemType e)//前插法改进
{
	insert(mylist, begin(mylist), e);
}

void pop_back(List* mylist)
{
	if (mylist->size == 0)
	{
		cout << "没有空间可以释放" << endl;
		return;
	}
	if (mylist->size == 1)
		{
			free(mylist->last);
			mylist->last = mylist->first;
			mylist->first->next = NULL;
			mylist->size--;
			return;
		}
	ToNode p = mylist->first->next;//设置为mylist->first时就不用加判断条件了
	while (p->next != mylist->last)
		p = p->next;
	free(mylist->last);
	if (mylist->size == 1)
	{
		mylist->last = mylist->first;
	}
	else 
	{
		mylist->last = p;
	}
	mylist->last->next = NULL;
	mylist->size--;
}

void pop_front(List* mylist)
{
	if (mylist->size == 0)
	{
		cout << "没有空间可以释放了" << endl;
		return;
	}
		
	ToNode p = mylist->first->next;
	mylist->first->next = p->next;
	free(p);
	if (mylist->size == 1)
		mylist->last = mylist->first;
	mylist->size--;
}

void insert_val(List* mylist, ElemType e)
{
	ToNode s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = e;
	s->next = NULL;

	ToNode p = mylist->first;
	assert(p != NULL);
	while (p->next != NULL && p->next->data < e)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		mylist->last = s;
	}
	s->next = p->next;
	p->next = s;
	mylist->size++;
}

ToNode find(List* mylist, ElemType e)
{
	ToNode p = mylist->first->next;
	assert(p != NULL);
	while (p != NULL && p->data != e)//不要搞混顺序如果p为空了，就没有data值
		p = p->next;
	return p;
}

int	 length(List* mylist)
{
	return mylist->size;
}

void delete_value(List* mylist, ElemType e)
{
	if (mylist->size == 0)
	{
		cout << "链表为空，不能删除了！" << endl;
		return;
	}
	ToNode p = mylist->first->next;
	p = find(mylist, e);
	if (p == NULL)
	{
		cout << "要查找的值不存在！" << endl;
		return;
	}
	
	if (p->next == NULL)
	{
		pop_back(mylist);
		cout << "删除成功!" << endl;
		return;
	}
	else
	{
		p->data = p->next->data;
		ToNode s = p->next;
		p->next = s->next;
		if (s->next == NULL)
		{
			mylist->last = p;
		}
		free(s);
		mylist->size--;
		cout << "删除成功！" << endl;
	}
}

void sort(List* mylist)//将链表断开，逐个插入
{
	if (mylist->size == 0 || mylist->size == 1)
	{
		return;
	}
	ToNode a = mylist->first->next;
	ToNode b = a->next;

	mylist->last = a;//break
	a->next = NULL;

	while (b != NULL)
	{
		a = b;//断开单个结点
		b = b->next;
	
		ToNode s = mylist->first;
		while (s->next != NULL && s->next->data < a->data)
		{
			s = s->next;
		}
		if (s->next == NULL)
		{
			mylist->last = a;
		}
		a->next = s->next;
		s->next = a;
	}
	


}

void reverse(List* mylist)
{
	if (mylist->size == 0 || mylist->size == 1)
	{
		return;
	}
	ToNode a = mylist->first->next;
	ToNode b = a->next;

	mylist->last = a;
	a->next = NULL;

	while (b != NULL)//不加next不会少一个
	{
		a = b;
		b = b->next;

		a->next = mylist->first->next;
		mylist->first->next = a;
	}

}

void clear(List* mylist)
{
	if (mylist->size == 0)
		return;

	ToNode p = mylist->first->next;
	while (p != NULL)
	{
		mylist->first->next = p->next;
		free(p);
		p = mylist->first->next;
		mylist->last = mylist->first;
		mylist->size = 0;
	}
}

void destory(List* mylist)
{
	clear(mylist);
	free(mylist->first);
	mylist->first = mylist->last = NULL;
}

ToNode _buyNode(ElemType e)
{
	ToNode s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = e;
	s->next = NULL;
	return s;
}

///////////////////////改进版////////////////////////////////

It begin(List* mylist)
{
	return mylist->first->next;
}
It end(List* mylist)
{
	return mylist->last->next;
}

void insert(List* mylist, It pos, ElemType e)
{
	ToNode s = mylist->first;
	while (s->next != pos)
	{
		s = s->next;
	}
	ToNode p = _buyNode(e);
	p->next = s->next;
	s->next = p;
	if (pos == NULL)
	{
		mylist->last = p;
	}
	mylist->size++;
}