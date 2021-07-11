#include"Queue.h"

void InitQueueFun(Queue* q)
{
	QueueNode* s = BuyQNodeFun();
	q->front = q->rear = s;
}

void EnterQueueFun(Queue* q, QueueElemType x)
{
	QueueNode* s = BuyQNodeFun();
	s->Data = x;

	q->rear->next = s;
	q->rear = s;
}

void EnterCryQueueFun(Queue* q, QueueElemType x)
{

}

void DeQueueFun(Queue* q)
{
	if (q->front->next == NULL)
	{
		printf("�ӿգ���Ԫ��\n");
		return;
	}
	QueueNode* s = q->front->next;
	QueueNode* now = s->next;
	q->front->next = now;
	free(s);
	if (now == NULL)
	{
		q->rear = q->front;
	}
}

QueueNode* BuyQNodeFun()
{
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	s->Data = NULL;
	s->next = nullptr;
	return s;
}

void Show(Queue* q)
{
	QueueNode* s = q->front->next;
	printf("Fornt:>");
	while (s != NULL)
	{
		printf("%d--", s->Data);
		s = s->next;
	}
	printf("Rear:>");
}

void GetQueueFornt(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("�ӿգ�û������\n");
		return;
	}
	printf("%d", q->front->next->Data);
}

void GetQueueFront(Queue* q, QueueElemType* Ret)
{
	if (q->front == q->rear)
	{
		printf("�ӿգ�û������\n");
		return;
	}
	*Ret = q->front->next->Data;
}

QueueElemType GetQueueFrontElem(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("�ӿգ�û������\n");
		return -1;
	}
	return q->front->next->Data;
}

void Length(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("�ӿգ�û��Ԫ��");
		return;
	}
	int num = 0;
	QueueNode* t = q->front->next;
	while (t!=NULL)
	{
		num++;
		t = t->next;
	}
	printf("%d", num);
}

void Clear(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("�ӿգ�û��Ԫ��");
		return;
	}
	QueueNode* d = q->front->next;
	QueueNode* p = d->next;
	q->rear = q->front;
	while (p->next != NULL)
	{
		free(d);
		d = p;
		p = p->next;
	}
	free(p);
}

void Destory(Queue* q)
{
	Clear(q);
	free(q->front);
	q->front = q->rear = NULL;
}

bool IsEmpty(Queue* q)
{
	return q->front == q->rear;
}