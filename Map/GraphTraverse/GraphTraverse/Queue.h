#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define QueueElemType int

struct QueueNode
{
	QueueElemType Data;
	struct QueueNode* next;
};

typedef struct Queue
{
	struct QueueNode* front;
	struct QueueNode* rear;
}MyQueue;

void InitQueueFun(Queue* q);
void EnterQueueFun(Queue* q, QueueElemType x);
void EnterCryQueueFun(Queue* q, QueueElemType x);
void DeQueueFun(Queue*q);
QueueNode* BuyQNodeFun();
void Show(Queue* q);
void GetQueueFornt(Queue* q);
void GetQueueFront(Queue* q, QueueElemType* Ret);
void Length(Queue* q);
void Clear(Queue* q);
void Destory(Queue* q);

bool IsEmpty(Queue* q);
QueueElemType GetQueueFrontElem(Queue* q);


#endif // !QUEUE_H_

