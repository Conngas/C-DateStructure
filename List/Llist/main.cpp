#include"Llist.h"
#include<string>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	List mylist;
	ListInit(&mylist);
	ElemType item;
	ToNode p;
	int select=1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] puch_back [2] push_front     *\n");
		printf("* [3] show_list [4] pop_back       *\n");
		printf("* [5] pop_front [6] insert_val     *\n");
		printf("* [7] find      [8] length         *\n");
		printf("* [9] sort      [10]delete_val     *\n");
		printf("* [11]resver    [12]clear          *\n");
		printf("* [13]destory   [0] quit_system    *\n");
		printf("************************************\n");
		printf("��ѡ�񣺡�");
		cin >> select;
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			cout << "������β�������ֵ(-1����)��>" << endl;
			while (cin >> item,item != -1)
			{
				push_back(&mylist,item);
			}
			break;
		case 2:
			cout << "������ͷ�������ֵ(-1����)��>" << endl;
			while (cin >> item, item != -1)
			{
				push_front(&mylist, item);
			}
			break;
		case 3:
			show_list(&mylist);
			break;
		case 4:
			pop_back(&mylist);
			break;
		case 5:
			pop_front(&mylist);
			break;
		case 6:
			cout << "������Ҫ��ֵ�����ֵ��" << endl;
			cin >> item;
			insert_val(&mylist, item);
			break;
		case 7:
			cout << "������Ҫ���ҵ�ֵ��" << endl;
			cin >> item;
			p = find(&mylist, item);
			if (p == NULL)
			{
				cout << "δ�ҵ�ֵ�����������룡" << endl;
			}
			else
			{
				cout << "���ݴ��ڣ�" << endl;
			}
			break;
		case 8:
			item = length(&mylist);
			cout << "��ĳ���Ϊ��";
			cout << item <<endl;
			break;
		case 9:
			sort(&mylist);
			break;
		case 10:
			cout << "����Ҫɾ����ֵ��" << endl;
			cin >> item;
			delete_value(&mylist, item);	
			break;
		case 11:
			reverse(&mylist);
			break;
		case 12:
			clear(&mylist);
			break;
		case 13:
			
			break;
		default:
			cout << "�������������������룡" << endl;
			break;
		}
	}destory(&mylist);
}