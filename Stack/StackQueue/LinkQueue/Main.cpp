#include"Queue.h"

int main()
{
	Queue q1;
	InitQueueFun(&q1);
	for (int i = 0; i < 5; ++i)
	{
		EnterQueueFun(&q1, i);
	}
	DeQueueFun(&q1);
	Show(&q1);
	GetQueueFornt(&q1);
	Length(&q1);
	Clear(&q1);
	Destory(&q1);
}