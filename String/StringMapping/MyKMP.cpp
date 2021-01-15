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
			next[++y] = ++x;
		}
		else
		{
			x = next[x];
		}
	}
}

int main()
{
	const char* p = "abcabdcaba";
	const int len = 1 + strlen(p);
	int next[20] = {-1};
	buildNext(p, next);
	for (int i : next)
	{
		printf("%d ", i);
	}
}