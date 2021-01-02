#pragma once
#ifndef SEQQUEUE_H_
#define SEQQUEUE_H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define MAXSIZE 8
#define ElemType int

struct SeqQueue
{
	ElemType* base;
	int	front;
	int rear;
};

typedef struct SeqQueue* ToSeqQueue;

void InitSeqQueueFun(SeqQueue* sq);
void EnSeqQueueFun(SeqQueue* sq, ElemType x);
void EnCirSeqQueueFun(SeqQueue* sq, ElemType x);
void DeSeqQueueFun(SeqQueue* sq);
void DeCirSeqQueueFun(SeqQueue* sq);
void Show(SeqQueue* sq);
void CirShow(SeqQueue* sq);
void Length(SeqQueue* sq);
void CirLength(SeqQueue* sq);
void GetHead(SeqQueue* sq);
void Clear(SeqQueue* sq);
void Destory(SeqQueue* sq);

#endif // !SEQQUEUE_H_

