#include"Cppstack.h"

void InitStack(ToNode& s)
{
	s = NULL;
}

void Push(ToNode& s, ElemType x)
{
	ToNode temp = new Node(x);
	if (s == NULL)
	{
		s = temp;
	}
	else
	{
		temp->next = s;
		s = temp;
	}
}
void Pop(ToNode& s)
{
	ToNode temp = s;
	s = s->next;
	delete(temp);
	temp = NULL;
}
void Show(ToNode& s)
{
	ToNode temp = s;
	while (temp != NULL)
	{
		cout << temp->Data << endl;
		temp = temp->next;
	}
}