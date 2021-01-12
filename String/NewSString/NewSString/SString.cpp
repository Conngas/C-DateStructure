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
		return 1;//S大于T串
	else if (result > 0)
		return -1;//T串大于S串
	else
		return result;
}

void StrConcat(SString T, SString a, SString b)
{
	//int ptr = 0;//Point to Empty
	int len1 = Length(a);
	int len2 = Length(b);

	for (int i = 0; i < len1; ++i)
	{
		T[i] = a[i];
	}

	if (len1 + len2 < MAXSTRINGLEN)
	{
		for (int j = 0; j < len2; ++j)
		{
			T[len1 + j] = b[j];
		}
		T[len1 + len2] = '\0';
	}
	else if (len1+len2 > MAXSTRINGLEN)
	{
		for (int j = 0; j < MAXSTRINGLEN - len1; ++j)
		{
			T[len1 + j] = b[j];
		}
		T[MAXSTRINGLEN] = '\0';
	}
	else
	{
		T[MAXSTRINGLEN] = '\0';
	}
}

void Strsub(SString Main, SString sub, int pos, int s_len)
{
	int len = Length(Main);
	if (pos<0 || pos >= s_len || s_len>len || s_len < 0)
	{
		return;
	}

	for (int i = 0; i < s_len; ++i)
	{
		sub[i] = Main[pos + i];
	}
	sub[s_len] = '\0';
}

void StrInsert(SString Main, SString Addstr, int pos)
{

	int M_len = Length(Main);
	int A_len = Length(Addstr);
	int Leftlen = 0;
	if (pos <0 || pos > M_len)
		return;
	if (M_len + A_len <= MAXSTRINGLEN)
	{
		Leftlen = A_len;
		Main[M_len + A_len] = '\0';
	}
	else if (M_len+A_len > MAXSTRINGLEN)
	{
		Leftlen = MAXSTRINGLEN - M_len;
		Main[MAXSTRINGLEN] = '\0';
	}
	else
	{
		A_len =0;
		printf("Can Not Insert!");
	}
	for (int i = M_len - 1; i >= pos; --i)
	{
		Main[Leftlen + i] = Main[i];
	}
	for (int j = 0; j < Leftlen; ++j)
	{
		Main[pos + j] = Addstr[j];
	}
}

void StrDelete(SString Main, int pos, int len)
{
	int M_len = Length(Main);
	if (pos <0 || pos >len || len < 0 || len >M_len)return;
	for (int i = pos; i <M_len; ++i)
	{
		Main[i] = Main[i + len];
	}
	Main[M_len - len] = '\0';
}

void StrClear(SString Main)
{
	Main[0] = '\0';
}