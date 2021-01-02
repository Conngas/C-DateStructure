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
		printf("��ѡ��>");
		//scanf("%d", &select);
		cin >> select;
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			cout << "β�巨����������Ӧ������(-1����)��" << endl;
			while (cin >> item, item != -1)
			{
				push_back(&mysqlist, item);
			}
			break;
		case 2:
			cout << "ͷ�巨����������Ӧ������(-1����)��" << endl;
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
			cout << "��������ֵ��" << endl;
			cin >> item;
			cout << "������λ�ã�" << endl;
			cin >> pos;
			insert_pos(&mysqlist,pos,item);
			break;
		case 7:
			cout << "��������ҵ���ֵ��" << endl;
			cin >> item;
			pos = find(&mysqlist, item);
			if (pos == -1)
			{
				cout << "�����" << item << "Ԫ�ز����ڣ�����������ֵ" << endl;
			}
			else
			{
				cout << "�����Ԫ��" << item << "���±�Ϊ" << pos << endl;
			}
			break;
		case 8:
			cout << "���Ա�ĳ���Ϊ��" << length(&mysqlist) << endl;
			break;
		case 9:
			sort(&mysqlist);
			break;
		case 10:
			cout << "����Ҫɾ����λ�ã�" << endl;
			cin >> pos;
			delete_pos(&mysqlist, pos);
			break;
		case 11:
			cout << "������Ҫɾ������ֵ��" << endl;
			cin >> item;
			pos = find(&mysqlist, item);
			if (pos == -1)
			{
				cout << "��������ݲ����ڣ���������" << endl;
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
			printf("��������������룡");
			break;
		}

	}
	destory(&mysqlist);
}
