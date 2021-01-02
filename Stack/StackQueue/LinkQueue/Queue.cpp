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
		printf("队空，无元素");
		return;
	}
	QueueNode* s = q->front->next;
	QueueNode* now = s->next;
	q->front->next = now;
	free(s);
	if (now->next == NULL)
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
		printf("队空，没有数据");
		return;
	}
	printf("%d", q->front->next->Data);
}

void Length(Queue* q)
{
	if (q->front == q->rear)
	{
		printf("队空，没有元素");
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
		printf("队空，没有元素");
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