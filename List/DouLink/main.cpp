#include"DulHead.h"

int main()
{
	List myList;
	InitList(&myList);
	int select = 1;
	ElemType item = 0;
	ToNode p;

	//while (1)
	//{
	//	printf("************************************\n");
	//	printf("* [1] puch_back [2] push_front     *\n");
	//	printf("* [3] show_list [4] pop_back       *\n");
	//	printf("* [5] pop_front [6] insert_val     *\n");
	//	printf("* [7] find      [8] length         *\n");
	//	printf("* [9] sort      [10]delete_val     *\n");
	//	printf("* [11]resver    [12]clear          *\n");
	//	printf("* [13]destory   [0] quit_system    *\n");
	//	printf("************************************\n");
	//	printf("��ѡ�񣺡�");
	//	cin >> select;
	//	if (select == 0)
	//	{
	//		break;
	//	}
	//	switch (select)
	//	{
	//	case 1:
	//		cout << "������β��Ҫ�����ֵ(-1����)��" << endl;
	//		while (cin >> item, item != -1)
	//		{
	//			//Push_back(&mylist, item);
	//		}
	//		break;
	//	case 2:
	//		cout << "������ͷ��Ҫ�����ֵ(-1����)��" << endl;
	//		while (cin >> item, item != -1)
	//		{
	//			//Push_front(&mylist, item);
	//		}
	//		break;
	//	case 3:
	//		//Show_List(&mylist);
	//		break;
	//	case 4:
	//		//pop_back(&mylist);
	//		break;
	//	case 5:
	//		//pop_front(&mylist);
	//		break;
	//	case 6:
	//		cout << "������Ҫ��ֵ�����ֵ��" << endl;
	//		cin >> item;
	//		//insert_val(&mylist, item);
	//		break;
	//	case 7:
	//		cout << "������Ҫ���ҵ�ֵ��" << endl;
	//		cin >> item;
	//		//p = find(&mylist, item);
	//		if (p == NULL)
	//			cout << "����ֵ�����ڣ�" << endl;

	//		break;
	//	case 8:
	//		///cout << "���ݳ���Ϊ" << Length(&mylist) << endl;
	//		break;
	//	case 9:
	//		//sort(&mylist);
	//		break;
	//	case 10:
	//		cout << "������Ҫɾ����ֵ��" << endl;
	//		cin >> item;
	//		//delete_val(&mylist, item);
	//		break;
	//	case 11:
	//		//resverse(&mylist);
	//		break;
	//	case 12:
	//		//clear(&mylist);
	//		break;
	//	default:
	//		break;
	//	}
	//}
}