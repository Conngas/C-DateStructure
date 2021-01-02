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
		printf("ջ�����޷�����ռ䣡");
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
		printf("ջ����");
	}
	s->base[s->top++] = x;//����++�������Top���ƶ�
}
void Pop(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("ջ�գ��޷���ջ");
	}
	s->top--;
}
bool GetTop(Stack* s, StackElemType* v)
{
	if (IsEmpty(s))
	{
		printf("ջ�����޷���ջ");
		return false;
	}
	*v = s->base[s->top - 1];//�˺���ֻ��ȡ����ջ
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