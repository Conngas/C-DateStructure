#include"SString.h";

void InitString(SString s)
{
	s[0] = '\0';
}

void Assign(SString s, const char* c)
{
	int len = strlen(c);
	for (int i = 0; i < len; ++i)
	{
		s[i] = c[i];
	}
	s[len] = '\0';
}

void Print(SString s)
{
	printf("%s\n", s);
}

int Length(SString s)
{
	int len = 0;
	while (*s!='\0')
	{
		s++;//指针值++
		len++;
	}
	return len;
}

void StrCopy(SString s,SString t)
{
	int len_t = Length(t);
	for (int i = 0;i < len_t;++i)
	{
		s[i] = t[i];
	}
	s[len_t] = '\0';
}

void StrEmpty(SString s)
{
	s[0] = '\0';
}

int StrCompare(SString s,SString t)//1>2 正；1<2 负
{
	int result = 0;
	while (*s!='\0' || *t!='\0')
	{
		result = *s - *t;
		if (result != 0)
			break;
		s++;
		t++;
	}
	if (result < 0)
		return 1;
	else if (result > 0)
		return -1;
	else
		return result;
}

void StrConcat(SString T, SString a, SString b)
{

}