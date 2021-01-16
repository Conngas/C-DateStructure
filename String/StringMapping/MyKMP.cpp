#include<stdio.h>
#include<string.h>

void buildNext(const char* p,int * next)
{
	int x = -1;
	int y = 0;
	while (y < strlen(p))
	{
		if (x == -1 || p[x] == p[y])
		{
			next[++y] = ++x;//更新next数组
		}
		else
		{
			x = next[x];//使x回退匹配更少的公共前后缀
		}
	}
}

void buildNextval(const char* p, int* nextval)
{
	int x = -1;
	int y = 0;
	while (y<strlen(p))
	{
		if (p[x] == p[y] || x == -1)
		{
			++x;++y;
			if (p[x] != p[y])
				nextval[y] = x;
			else
				nextval[y] = nextval[x];
		}
		else
		{
			x = nextval[x];
		}
	}
}

int KMP(const char* main, const char* sub,int pos)
{
	int i = pos;
	int j = 0;

	int const m_len = strlen(main);
	int const s_len = strlen(sub);
	//const int len = s_len + 1;
	int next[20] = { -1 };
	int nextval[20] = { -1 };
	//buildNext(sub, next);
	buildNextval(sub, nextval);
	while (i < m_len && j < s_len)
	{
		if (main[i] == sub[j] || j == -1)
		{
			i++;j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= s_len)return i - j;
	else return -1;
}


int main()
{
	int res = KMP("AABAAAB", "AAAB", 0);
}