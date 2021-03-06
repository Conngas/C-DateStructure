#include"HString.h"

void HStrInit(HString* main)
{
	main->ch = NULL;
	main->length = 0;
}

void HStrAssign(HString* main, const char* str)
{
	int len = strlen(str);
	if(main->ch!=NULL)
		free(main->ch);
	main->ch = (char*)malloc(len * sizeof(char));
	assert(main->ch != NULL);
	for (int i = 0;i < len;++i)
	{
		main->ch[i] = str[i];
	}
	main->length = len;
}

void HStrPrint(HString* main)
{
	for (int i = 0; i< main->length;++i)
	{
		printf("%c", main->ch[i]);
	}
	printf("\n");
}

int	 HStrLength(HString* main)
{
	return main->length;
}

void HStrCopied(HString* main, HString* Origin)
{
	int len = HStrLength(Origin);
	if (main->ch != NULL)
		free(main->ch);
	main->ch = (char*)malloc(sizeof(char) * len);
	assert(main->ch != NULL);
	for (int i = 0;i < len;++i)
	{
		main->ch[i] = Origin->ch[i];
	}
	main->length = len;
}

int  HStrCompare(HString* A, HString* B)
{
	int i = 0;int j = 0;int result = 0;
	if (A->length == 0 && B->length == 0)
		return 0;
	while (i<A->length && j<B->length)
	{
		if (A->ch[i] > B->ch[j])
			return 1;
		if (A->ch[i] < B->ch[j])
			return -1;
		++i;
		++j;
	}
	if (A->length > B->length)
		result = 1;
	if (A->length < B->length)
		result = -1;
	return result;
}

void HStrComcat(HString* main, HString* A, HString* B)
{
	if (main->ch != NULL)
	{
		free(main->ch);
	}
	int A_len = HStrLength(A);
	int B_len = HStrLength(B);
	main->ch = (char*)malloc(sizeof(char) * (A_len + B_len));
	assert(main->ch!=NULL);
	for (int i = 0;i < A_len;++i)
	{
		main->ch[i] = A->ch[i];
	}
	for (int j = 0;j < B_len;++j)
	{
		main->ch[A_len + j] = B->ch[j];
	}
	main->length = (A_len + B_len);
}

void HStrSub(HString* main, HString* sub, int pos, int len)
{
	if (pos <0 || pos > main->length || len <0 || len >main->length)return;
	if (sub->ch != NULL)
	{
		free(sub->ch);
	}
	sub->ch = (char*)malloc(sizeof(char) * len);
	assert(sub->ch != NULL);
	for (int i = 0;i < len;++i)
	{
		sub->ch[i] = main->ch[pos + i];
	}
	sub->length = len;
}

void HStrInsert(HString* main, HString* in, int pos)
{
	if (in->length == 0 || pos<0 || pos>in->length)return;
	char* ch = (char*)realloc(main->ch, sizeof(char) * (main->length + in->length));
	assert(ch != NULL);
	main->ch = ch;
	for (int i = main->length - 1;i >= pos;--i)
	{
		main->ch[i + in->length] = main->ch[i];
	}
	for (int j = 0;j < in->length;++j)
	{
		main->ch[j + pos] = in->ch[j];
	}
	main->length = (main->length + in->length);
}

void HStrDelete(HString* main, int pos,int len)
{
	if (pos<0 || pos>main->length || len<0||len>main->length)return;
	if (pos + len > main->length)
	{
		printf("OverRange!");
		return;
	}
	for (int i = 0;i < len;++i)
	{
		main->ch[pos + i] = main->ch[pos + i + len];
	}
	main->length -= len;
}

void HStrClear(HString* main)
{
	if (main->ch != NULL)
	{
		free(main->ch);
	}
	main->length = 0;
	main->ch = NULL;
}

int	 HStrMap(HString* main, HString* sub, int pos)
{
	int i = pos;
	int j = 0;
	while (i<main->length && j<sub->length)
	{
		if (main->ch[i] == sub->ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j>=sub->length)return i - j;
	else return -1;
}

void HStrReplace(HString* main, HString* sub, HString* rep)
{
	int m_len = main->length;
	int s_len = sub->length;
	int r_len = sub->length;

	int index = -1;
	int pos = 0;
	while (pos<m_len)
	{
		index = HStrMap(main, sub, pos);
		if (index == -1)return;
		HStrDelete(main, index, s_len);
		HStrInsert(main, rep, index);

		pos = index + r_len;
	}
}

//KMP JAVA Version Uncomplete
/*
void KMP(HString* main, HString* sub)
{
	int m_len = main->length;
	int s_len = sub->length;
	int s_index = 0;
	int X = 0;
	//dp array
	int dp[DPLength][256];
	
	dp[0][s_index] = 1;
	for (int m = 1;m < s_len;++m)
	{
		for (int n = 0;n < 256;++n)
		{
			dp[m][n] = dp[X][n];
		}
		dp[m][s_index]
	}
	
	int j = 0;//j is pointer of sub
	for (int i = 0;i < m_len;++i)
	{
		
	}
}
*/

int KMP(HString* main, HString* sub, int pos)
{
	int i = 0;int j = 0;
	const int len = sub->length + 1;
	//

	//int next[20] = { -1 };
	//BuildNext(sub, next);
	//
	int nextval[20] = { -1 };
	BuildNextval(sub, nextval);

	while (i < main->length && j < sub->length)
	{
		if (main->ch[i] == sub->ch[j] || j == -1)
		{
			++i;++j;
		}
		else
		{
			j = nextval[j];
			//
			//j = next[j];
		}
	}
	if (j >= sub->length)return i - j;
	else return -1;
}

void BuildNext(HString* sub, int* next)
{
	int x = -1;int y = 0;
	while (y < sub->length)
	{
		if (sub->ch[x] == sub->ch[y] || x == -1)
		{
			next[++y] = ++x;
		}
		else
		{
			//Back
			x = next[x];
		}
	}
}

void BuildNextval(HString* sub, int* nextval)
{
	int x = -1;int y = 0;
	while (y < sub->length)
	{
		if (sub->ch[x] == sub->ch[y] || x == -1)
		{
			if (sub->ch[x] != sub->ch[y])nextval[++y] = ++x;
			else nextval[++y] = nextval[++x];
		}
		else
		{
			x = nextval[x];
		}
	}
}