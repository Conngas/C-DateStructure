#include"Stack.h"

int main()
{
	Stack s1;
	InitSeqStack(&s1);

	for (int i = 0;i <= 10;i++)
	{
		Push(&s1, i);
	}
	Show(&s1);
	StackElemType a;
	GetTop(&s1, &a);
	printf("%d", a);
	Length(&s1);
	Clear(&s1);
	Show(&s1);
	Destory(&s1);
}