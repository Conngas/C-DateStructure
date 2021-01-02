#include"SEQUEUE.h"

void InitSeqQueueFun(SeqQueue* sq)
{
	sq->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	assert(sq->base != NULL);
	sq->front = sq->rear = 0;
}

void EnSeqQueueFun(SeqQueue* sq, ElemType x)
{
	if (sq->rear >= MAXSIZE)
	{
		printf("�������޷����");
		return;
	}
	sq->base[sq->rear++] = x;
}

void EnCirSeqQueueFun(SeqQueue* sq, ElemType x)
{
	if ((sq->rear + 1) % MAXSIZE == sq->front)
	{
		printf("�������޷����");
		return;
	}
	sq->base[sq->rear] = x;//��������
	sq->rear = (sq->rear + 1) % MAXSIZE;//��λrear���´ο�λ��
}

void DeSeqQueueFun(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("�ӿգ��޷�����");
		return;
	}
	sq->front++;
}

void DeCirSeqQueueFun(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("�ӿգ��޷�����");
		return;
	}
	sq->front = (sq->front + 1) % MAXSIZE;
}

void Show(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("�ӿ�");
		return;
	}
	printf(">:");
	for (int i = sq->front; i < sq->rear; i++)
	{
		printf(" %d ", sq->base[i]);
	}
	printf(":<");
}

void CirShow(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("�ӿ�");
		return;
	}
	printf(">:");
	for (int i = sq->front;i!= sq->rear;)
	{
		printf("%d", sq->base[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf(":<");
}

void Length(SeqQueue* sq)
{
	printf("%d", sq->rear - sq->front);
}

void CirLength(SeqQueue* sq)
{
	if ((sq->rear - sq->front) < 0)
	{
		printf("%d", MAXSIZE + (sq->rear - sq->front));
		return;
	}
	printf("%d", sq->rear - sq->front);
}

void GetHead(SeqQueue* sq)
{
	if (sq->front == sq->rear)
	{
		printf("�ӿ�");
		return;
	}
	//int i = sq->front -1;
	printf("%d", sq->base[sq->front]);
}
void Clear(SeqQueue* sq)
{
	sq->front = sq->rear = 0;
}
void Destory(SeqQueue* sq)
{
	Clear(sq);
	free(sq->base);
	sq->base = NULL;
	sq->front = sq->rear = 0;
}