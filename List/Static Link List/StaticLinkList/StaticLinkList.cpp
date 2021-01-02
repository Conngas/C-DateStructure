// StaticLinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "StaticHead.h"


void InitStatic(StaticLinkList& space)
{
	for (int i = 1; i < MAX - 1; i++)
	{
		space[i].cur = i+1;
	}
	space[0].cur = -1;
	space[MAX - 1].cur = 0;
}

int malloc_SL(StaticLinkList& space)
{
	int i = space[1].cur;
	if (space[1].cur != 0)
		space[1].cur = space[i].cur;//将i的下一个空结点给头结点，头结点确定空闲位置
	return i;
}

void free_SL(StaticLinkList& space,int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
}

void InsertStatic(StaticLinkList& space, ElemType x)
{

	int i = malloc_SL(space);
	if (space[i].cur == -1)
	{
		printf("输入数据失败");
		return ;
	}

	space[i].data = x;
	if (space[0].cur == -1)
	{
		//space[0].cur = i;
		space[i].cur = -1;
	}
	else
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
}

void DeleteList(StaticLinkList& space)
{
	int i = space[0].cur;
	space[0].cur = space[i].cur;
	free_SL(space, i);
}

void ListShow(StaticLinkList& space)
{
	int i = space[0].cur;
	while (i != -1)
	{
		printf("%c-->", space[i].data);
		i = space[i].cur;
	}
	printf("NULL\n");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
