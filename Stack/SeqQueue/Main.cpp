#include"SEQUEUE.h"

int main()
{
	SeqQueue s3;
	InitSeqQueueFun(&s3);
	for (int i = 0; i < 8; ++i)
	{
		EnCirSeqQueueFun(&s3, i);
	}
	//Show(&s3);
	CirShow(&s3);
	DeCirSeqQueueFun(&s3);
	EnCirSeqQueueFun(&s3, 10);
	CirShow(&s3);
	CirLength(&s3);
}

//int main()
//{
//	SeqQueue q2;
//	InitSeqQueueFun(&q2);
//	for (int i = 0; i <= 5; ++i)
//	{
//		EnSeqQueueFun(&q2, i);
//	}
//	DeSeqQueueFun(&q2);
//	Show(&q2);
//	GetHead(&q2);
//	Length(&q2);
//	Clear(&q2);
//	Show(&q2);
//}