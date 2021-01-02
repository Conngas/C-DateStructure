#pragma once
#ifndef SEQSTACK_H_
#define SEQSTACK_H_
#define StackElemType int
#define StackMaxSize 8
#define StackIncSize 3

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef struct Stack
{
	StackElemType*	base;
	int				top;
	int				capacity;
}my_stack;


void InitSeqStack(Stack* s);
bool IncreaseStack(Stack* s);
void Push(Stack* s,StackElemType x);
void Pop(Stack* s);
bool GetTop(Stack* s, StackElemType *v);
void Show(Stack* s);
bool IsFull(Stack* s);
bool IsEmpty(Stack* s);
int Length(Stack* s);
void Clear(Stack* s);
void Destory(Stack* s);

#endif // !SEQSTACK_H_

