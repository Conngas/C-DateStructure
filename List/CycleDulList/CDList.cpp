#include"CDList.h"

ToNode BuyNode()
{
	ToNode p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);
	p->next = p->pre = NULL;
	p->data = 0;
	return p;
}

int InitList(CDList* List)
{
	ToNode p = BuyNode();
	List->first = p;
	List->last = p;
	List->size = 0;
	p->next = List->first;
	List->first->pre = List->last;
	return 0;
}

int Push_back(CDList* List, ElemType e)
{
	ToNode p = BuyNode();
	p->data = e;
	//
	List->last->next = p;
	p->pre = List->last;
	//
	List->last = p;
	p->next = List->first;
	List->first->pre = List->last;

	List->size++;

	return 0;
}

int Push_Front(CDList* List, ElemType e)
{
	ToNode p = BuyNode();
	p->data = e;
	if (List->last == List->first)
	{
		List->last = p;

		p->pre = List->first;
		List->first->next = p;

		p->next = List->first;
		List->first->pre = List->last;

		List->size++;
	}
	else
	{
		List->first->next->pre = p;
		p->next = List->first->next;
		
		List->first->next = p;
		p->pre = List->first;

		List->size++;
	}
	return 0;
}

int Show(CDList* List)
{
	ToNode p = List->first->next;
	while (p!=List->first)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Null\n");
	return 0;
}

int Pop_back(CDList* List)
{
	if (List->size == 0)
	{
		printf("不必删除！\n");
		return 0;
	}
	else if (List->size == 1)
	{
		ToNode p = List->last;
		
		List->first->next = List->first;
		List->last = List->first;
		List->first->pre = List->last;
		List->size--;

		free(p);

		return 0;
	}
	else
	{
		ToNode p = List->last;

		p->pre->next = List->first;
		List->last = p->pre;
		List->first->pre = List->last;

		List->size--;

		free(p);

		return 0;
	}
}

int Pop_front(CDList* List)
{
	if (List->size == 0)
	{
		printf("不必删除！\n");
		return 0;
	}
	else if (List->size == 1)
	{
		ToNode p = List->first->next;

		List->first->next = List->first;
		List->last = List->first;
		List->first->pre = List->last;

		List->size--;

		free(p);

		return 0;
	}
	else
	{
		ToNode p = List->first->next;

		List->first->next = p->next;
		p->next->pre = List->first;
		List->first->pre = List->last;

		List->size--;

		free(p);

		return 0;
	}
}

int Insert_val(CDList* List, ElemType e)
{
	ToNode p = BuyNode();
	ToNode f = List->first->next;

	p->data = e;

	while (f != List->first && f->data < e)
	{
		f = f->next;
	}
	if (f == List->first)
	{
		p->pre = List->last;
		List->last->next = p;

		p->next = List->first;
		List->last = p;

		List->first->pre = List->last;

		List->size++;
		return 0;
	}
	else
	{
		p->pre = f->pre;
		f->pre->next = p;

		p->next = f;
		f->pre = p;

		List->first->pre = List->last;

		List->size++;

		return 0;
	}
	

}

ToNode find(CDList* List, ElemType e)
{
	ToNode f = List->first->next;
	while (f != List->first && f->data == e)
	{
		f = f->next;
	}
	if (f == List->first)
	{
		printf("无法找到相应值！");
		return 0;
	}
	else
	{
		printf("已找到值！");
		return f;
	}
}

int length(CDList* List)
{
	return List->size;
}

int Sort(CDList* List)
{
	if (List->size == 0 || List->size == 1)
	{
		printf("无需排序！");
		return 0;
	}
	else
	{
		ToNode a = List->first->next;
		ToNode b = a->next;
		ToNode f;
		List->last = a;
		a->next = List->first;
		List->first->pre = List->last;

		while (b != List->first)
		{
			a = b;
			b = b->next;
			f = List->first->next;

			while (f->next != List->first && a->data >= f->data)//如果a的值大于f的值，f++，如果跟if条件一样循环一直传递
			{
				f = f->next;
			}
			if(a->data < f->data)
			{
				f->pre->next = a;
				a->pre = f->pre;

				f->pre = a;
				a->next = f;
			}
			else
			{
				a->pre = f;
				f->next = a;

				a->next = List->first;
				List->last = a;

				List->first->pre = List->last;
			}
		}
		return 0;
	}
}

int DeletVal(CDList* List, ElemType e)
{
	ToNode f = List->first->next;
	while (f != List->first && f->data != e)
	{
		f = f->next;
	}

	if (f == List->first)
	{
		printf("未找到删除的值！\n");
		return 0;
	}
	else if (f->next == List->first)
	{
		f->next = NULL;
		List->last = f->pre;
		List->last->next = List->first;
		List->first->pre = List->last;

		List->size--;
		free(f);
		return 0;
	}
	else
	{
		f->pre->next = f->next;
		f->next->pre = f->pre;

		free(f);
		List->size--;
		return 0;
	}
}

int Reverse(CDList* List)
{
	ToNode a = List->first->next;
	ToNode b = a->next;

	a->next = List->first;
	List->last = a;

	List->first->pre = List->last;

	while (b != List->first)
	{
		a = b;
		b = b->next;

		a->next = List->first->next;
		List->first->next->pre = a;

		List->first ->next = a;
		a->pre = List->first;
	}
	return 0;
}

int AClear(CDList* List)
{
	if (List->size == 0)
	{
		printf("无需删除！\n");
		return 0;
	}

	ToNode d = List->last;
	ToNode p;

	while (List->size > 0)
	{
		p = d;
		d = d->pre;

		d->next = List->first;
		List->last = d;
		List->first->pre = List->last;

		List->size--;
		free(p);
	}
	return 0;
}

int SClear(CDList* List)
{
	if (List->size == 0)
	{
		printf("无需删除！\n");
		return 0;
	}

	ToNode d = List->last;
	ToNode p;

	
	p = d;
	d = d->pre;

	d->next = List->first;
	List->last = d;
	List->size--;
	free(p);
	
	return 0;
}

int Delete(CDList* List)
{
	AClear(List);
	
	free(List->first);

	List->first = List->last = NULL;
	List->size = 0;
	return 0;
}