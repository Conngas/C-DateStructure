#include"Stack.h"

void InitSeqStack(Stack *s)
{
	s->base = (StackElemType*)malloc(sizeof(StackElemType) * StackMaxSize);
	assert(s->base != 0);
	s->top = 0;
	s->capacity = StackMaxSize;
}

//void InitSeqStack(Stack& s)
//{
//	s.base = (StackElemType*)malloc(sizeof(StackElemType) * StackMaxSize);
//	assert(s.base != 0);
//	s.top = 0;
//	s.capacity = StackMaxSize;
//}

bool IncreaseStack(Stack* s)
{
	StackElemType* newbase = (StackElemType*)realloc(s->base, sizeof(StackElemType) * (s->capacity + StackIncSize));
	if (newbase == NULL)
	{
		printf("栈满且无法申请空间！");
		return false;
	}
	s->base = newbase;
	s->capacity += StackIncSize;
	return true;
}

void Push(Stack*s, StackElemType x)
{
	if (IsFull(s) && !IncreaseStack(s))
	{
		printf("栈已满");
	}
	s->base[s->top++] = x;//后置++插入完后Top上移动
}
void Pop(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("栈空，无法出栈");
	}
	s->top--;
}
bool GetTop(Stack* s, StackElemType* v)
{
	if (IsEmpty(s))
	{
		printf("栈满，无法入栈");
		return false;
	}
	*v = s->base[s->top - 1];//此函数只读取不出栈
	return true;
}
void Show(Stack*s)
{
	for (int i = s->top-1; i>=0;i--)
	{
		printf("%d\t", s->base[i]);
	}
}
bool IsFull(Stack* s)
{
	return s->top >= s->capacity;
}
bool IsEmpty(Stack* s)
{
	return s->top == 0;
}
int Length(Stack* s)
{
	return s->top;
}
void Clear(Stack* s)
{
	s->top = 0;
}
void Destory(Stack* s)
{
	free(s->base);
	s->base = NULL;
	s->capacity = s->top = 0;
}