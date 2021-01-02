#include"LinkStack.h"

void LineEdit()
{
	MyNode s3;
	LinkStackInitFun(&s3);
	char c = getchar();
	while (c!='$')
	{
		while (c != '$' && c != '\n')
		{
			switch (c)
			{
			case '#':
				Pop(&s3);
				break;
			case'@':
				Clear(&s3);
				return;
				break;
			default:
				Push(&s3, c);
				break;
			}
			c = getchar();
		}
		PrintOnChar(&s3);
		c = getchar();
	}
	
}

int main()
{
	LineEdit();
}

/*
bool IsPair(const char *str)
{
	MyNode s2;
	LinkStackInitFun(&s2);

	char v;
	while (*str != '\0')
	{
		if(*str=='[' || *str=='(')
		{
			Push(&s2, *str);
		}
		else if (*str == ']')
		{
			GetTopElem(&s2, &v);
			if (v != '[')
			{
				return false;
			}
			Pop(&s2);
		}
		else if (*str == ')')
		{
			GetTopElem(&s2, &v);
			if (v != '(')
			{
				return false;
			}
			Pop(&s2);
		}
		++str;
	}
	return IsEmpty(&s2);
}

int main()
{
	const char* a = "(([]))";
	if(IsPair(a))
	{
		printf("Success");
	}

}
*/
/*
void convert2(int v)
{
	MyNode s1;
	LinkStackInitFun(&s1);

	while (v)
	{
		Push(&s1, v % 2);
		v = v / 2;
	}
	//Show(&s1);
	while (!IsEmpty(&s1))
	{
		GetTop(&s1);
		Pop(&s1);
	}
}

int main()
{
	int a = 82934;
	convert2(a);
}
*/
/*
int main()
{
	MyNode s1;
	LinkStackInitFun(&s1);
	for (int i = 0;i < 4;i++)
	{
		Push(&s1, i);
	}
	Pop(&s1);
	Show(&s1);
}*/