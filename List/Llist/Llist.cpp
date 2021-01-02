#include"Llist.h"

using namespace std;

void ListInit(List *mylist)
{
	mylist->first = mylist->last = (Node*)malloc(sizeof(Node));
	assert(mylist->first != NULL);
	mylist->first->next = NULL;//��Ҫ��
	mylist->size = 0;
}

//void push_back(List* mylist, ElemType e)//����Ҫ��ָ��ָ����
//{
//	ToNode s = _buyNode(e);
//	/*
//	ToNode s = (Node*)malloc(sizeof(Node));
//	assert(s != NULL);
//	s->data = e;
//	s->next = NULL;
//	*/
//
//	mylist->last->next = s;//���ӽ��
//	mylist->last= s;//���������
//	mylist->size++;
//}

void push_back(List* mylist, ElemType e)//�Ľ��Ĳ���
{
	insert(mylist, end(mylist), e);
}

void show_list(List *mylist)//ע�⵱ͷ���޽��ʱ��Ųλβָ��
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

void push_front(List* mylist, ElemType e)//ǰ�巨�Ľ�
{
	insert(mylist, begin(mylist), e);
}

void pop_back(List* mylist)
{
	if (mylist->size == 0)
	{
		cout << "û�пռ�����ͷ�" << endl;
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
	ToNode p = mylist->first->next;//����Ϊmylist->firstʱ�Ͳ��ü��ж�������
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
		cout << "û�пռ�����ͷ���" << endl;
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
	while (p != NULL && p->data != e)//��Ҫ���˳�����pΪ���ˣ���û��dataֵ
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
		cout << "����Ϊ�գ�����ɾ���ˣ�" << endl;
		return;
	}
	ToNode p = mylist->first->next;
	p = find(mylist, e);
	if (p == NULL)
	{
		cout << "Ҫ���ҵ�ֵ�����ڣ�" << endl;
		return;
	}
	
	if (p->next == NULL)
	{
		pop_back(mylist);
		cout << "ɾ���ɹ�!" << endl;
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
		cout << "ɾ���ɹ���" << endl;
	}
}

void sort(List* mylist)//������Ͽ����������
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
		a = b;//�Ͽ��������
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

	while (b != NULL)//����next������һ��
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

///////////////////////�Ľ���////////////////////////////////

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