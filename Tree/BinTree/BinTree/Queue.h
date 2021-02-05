#pragma once
#pragma once
#ifndef SEQQUEUE_H_
#define SEQQUEUE_H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

struct BinTreeNode;

#define MAXSIZE 20
#define QueueElemType_ BinTreeNode*

struct SeqQueue
{
	QueueElemType_* base;
	int	front;
	int rear;
};

typedef struct SeqQueue* ToSeqQueue;

void InitSeqQueueFun(SeqQueue* sq);
bool SeqQueueIsEmpty(SeqQueue* sq);
void EnSeqQueueFun(SeqQueue* sq, QueueElemType_ x);
void EnCirSeqQueueFun(SeqQueue* sq, QueueElemType_ x);
void DeSeqQueueFun(SeqQueue* sq);
void DeCirSeqQueueFun(SeqQueue* sq);
void Show(SeqQueue* sq);
void CirShow(SeqQueue* sq);
void Length(SeqQueue* sq);
void CirLength(SeqQueue* sq);
void GetHead(SeqQueue* sq, QueueElemType_ *v);
void Clear(SeqQueue* sq);
void Destory(SeqQueue* sq);

#endif // !SEQQUEUE_H_

void InitSeqQueueFun(SeqQueue* sq)
{
	sq->base = (QueueElemType_*)malloc(sizeof(QueueElemType_) * MAXSIZE);
	assert(sq->base != NULL);
	sq->front = sq->rear = 0;
}

bool SeqQueueIsEmpty(SeqQueue* sq)

{
	return sq->front == sq->rear;
}

void EnSeqQueueFun(SeqQueue* sq, QueueElemType_ x)
{
	if (sq->rear >= MAXSIZE)
	{
		printf("队满，无法入队");
		return;
	}
	sq->base[sq->rear++] = x;
}

void EnCirSeqQueueFun(SeqQueue* sq, QueueElemType_ x)
{
	if ((sq->rear + 1) % MAXSIZE == sq->front)
	{
		printf("队满，无法入队");
		return;
	}
	sq->base[sq->rear] = x;//放置数据
	sq->rear = (sq->rear + 1) % MAXSIZE;//定位rear到下次空位置
}

void DeSeqQueueFun(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("队空，无法出队");
		return;
	}
	sq->front++;
}

void DeCirSeqQueueFun(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("队空，无法出队");
		return;
	}
	sq->front = (sq->front + 1) % MAXSIZE;
}

void Show(SeqQueue* sq)
{
	if (sq->rear == sq->front)
	{
		printf("队空");
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
		printf("队空");
		return;
	}
	printf(">:");
	for (int i = sq->front; i != sq->rear;)
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

void GetHead(SeqQueue* sq,QueueElemType_* v)
{
	if (sq->front == sq->rear)
	{
		printf("队空");
		return;
	}
	//int i = sq->front -1;
	//printf("%d", sq->base[sq->front]);
	*v = sq->base[sq->front];
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
