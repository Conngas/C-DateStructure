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