#include"Slist.h"
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	Sqlist mysqlist;
	InitSqlist(&mysqlist);
	int select = 1;
	int pos;
	ElemType item;
	while (select)
	{
		printf("******************************************\n");
		printf("*	[1] puch_back   [2] push_front       *\n");
		printf("*	[3] show_list   [4] pop_back         *\n");
		printf("*	[5] pop_front   [6] insert_pos       *\n");
		printf("*	[7] find        [8] length           *\n");
		printf("*	[9] sort        [10]delete_pos       *\n");
		printf("*	[11]delete_val	[12]resver           *\n");
		printf("*	[13]clear       [14]destory          *\n");
		printf("*	[0] quit_system                      *\n");
		printf("******************************************\n");
		printf("请选择：>");
		//scanf("%d", &select);
		cin >> select;
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			cout << "尾插法：请输入相应的数据(-1结束)：" << endl;
			while (cin >> item, item != -1)
			{
				push_back(&mysqlist, item);
			}
			break;
		case 2:
			cout << "头插法：请输入相应的数据(-1结束)：" << endl;
			while (cin >> item, item != -1)
			{
				push_front(&mysqlist, item);
			}
			break;
		case 3:
			show_list(&mysqlist);
			break;
		case 4:
			pop_back(&mysqlist);
			break;
		case 5:
			pop_front(&mysqlist);
			break;
		case 6:
			cout << "请输入数值：" << endl;
			cin >> item;
			cout << "请输入位置：" << endl;
			cin >> pos;
			insert_pos(&mysqlist,pos,item);
			break;
		case 7:
			cout << "请输入查找的数值：" << endl;
			cin >> item;
			pos = find(&mysqlist, item);
			if (pos == -1)
			{
				cout << "输入的" << item << "元素不存在，请输入其他值" << endl;
			}
			else
			{
				cout << "输入的元素" << item << "的下标为" << pos << endl;
			}
			break;
		case 8:
			cout << "线性表的长度为：" << length(&mysqlist) << endl;
			break;
		case 9:
			sort(&mysqlist);
			break;
		case 10:
			cout << "输入要删除的位置：" << endl;
			cin >> pos;
			delete_pos(&mysqlist, pos);
			break;
		case 11:
			cout << "请输入要删除的数值：" << endl;
			cin >> item;
			pos = find(&mysqlist, item);
			if (pos == -1)
			{
				cout << "输入的数据不存在，重新输入" << endl;
			}
			else
			{
				delete_pos(&mysqlist, pos);
			}
			break;
		case 12:
			resver(&mysqlist);
			break;
		case 13:
			clear(&mysqlist);
			break;
		case 14:
			destory(&mysqlist);
			break;
		default:
			printf("输入错误，重新输入！");
			break;
		}

	}
	destory(&mysqlist);
}
