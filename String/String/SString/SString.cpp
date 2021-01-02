#include"SString.h"

void InitString(SString S)
{
	S[0] = '\0';
}
void StrAssign(SString S, char* str)
{
	int len = strlen(str);
	for (int i = 0;i < len;++i)
	{
		S[i] = str[i];
	}
	S[len] = '\0';
}
void PrintString(SString S)
{
	printf("%s", S);
}
void StrCopy(SString A,SString B)
{
	int b = StrLength(B);
	for (int i = 0;i < b;++i)
	{
		A[i] = B[i];
	}
	A[b] = '\0';

}
int  StrLength(SString S)
{
	int len = 0;
	int i = 0;
	while (S[i]!='\0')
	{
		i++;
	}
	return len;
}
bool StrCompare(SString S,SString T)
{
	int result = 0;
	while (*S!='\0' || *T!= '\0')//找到第一个不同点即可跳出
	{
		result = *S - *T;
		if (result != 0)
			break;
		S++;
		T++;
	}
	if (result < 0)
	{
		return false;
	}
	else if (result > 0)
	{
		return true;
	}	
	return result;
}