#include"CDList.h"

int main()
{
	CDList List;
	InitList(&List);

	int select = 1;
	ElemType e;
	ToNode p;

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
		printf("请输入数值进行相应的操作：>\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入尾插的数据：>(-1结束)\n");
			while (scanf_s("%d", &e), e != -1)
			{
				Push_back(&List, e);
			}
			break;
		case 2:
			while(scanf_s("%d", &e),e!= -1)
			{
				Push_Front(&List, e);
			}
			break;
		case 3:
			Show(&List);
			break;
		case 4:
			Pop_back(&List);
			break;
		case 5:
			Pop_front(&List);
			break;
		case 6:
			printf("请输入要按值插入的值：>\n");
			scanf_s("%d", &e);
			Insert_val(&List, e);
			break;
		case 7:
			printf("请输入要查找的值:>");
			scanf_s("%d",&e);
			find(&List, e);
			break;
		case 8:
			printf("长度为：%d个！\n",length(&List));
			break;
		case 9:
			Sort(&List);
			break;
		case 10:
			printf("输入要删除的值！");
			scanf_s("%d", &e);
			DeletVal(&List, e);
			break;
		case 11:
			Reverse(&List);
			break;
		case 12:
			AClear(&List);
			//SClear(&List);
			break;
		case 13:
			//Delete(&List);
			break;
		default:
			break;
		}
	}
	Delete(&List);
	
}