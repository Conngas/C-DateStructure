#include"Cppstack.h"

int main()
{
	ToNode s;
	InitStack(s);
	for (int i = 0;i < 5;i++)
	{
		Push(s, i);
	}
	Pop(s);
	Show(s);
}