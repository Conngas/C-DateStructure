#include"DulHead.h"

int main()
{
	MyDulList My_DulList;
	InitList(&My_DulList);

	ElemType e;
	int Select=1;
	int count=1;
	while (Select)
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
		printf("��������ֵ������Ӧ�Ĳ�����>\n");
		scanf_s("%d", &Select);
		switch (Select)
		{
		case 1:
			printf("������Ҫβ��ı�����>(-1����)\n");
			while (scanf_s("%d", &e),e != -1)
			{
				Push_back(&My_DulList, e);
			}			
			break;
		case 2:
			printf("������Ҫͷ��ı�����>(-1����)\n");
			while (scanf_s("%d", &e), e != -1)
			{
				Push_Front(&My_DulList, e);
			}
			break;
		case 3:
			Show_list(&My_DulList);
			break;
		case 4:
			Pop_back(&My_DulList);
			break;
		case 5:
			Pop_front(&My_DulList);
			break;
		case 6:
			printf("������Ҫ�����ֵ��>\n");
			scanf_s("%d",&e);
			insert_val(&My_DulList, e);
			break;
		case 7:
			printf("������Ҫ���ҵ�ֵ��>\n");
			scanf_s("%d", &e);
			count = find(&My_DulList, e);
			if (count == NULL)
			{
				printf("�Ҳ������ݣ�\n");
			}
			else
			{
				printf("�����д��ڴ����ݣ�\n");
			}			
			break;
		case 8:
			count = length(&My_DulList);
			printf("������Ϊ%d\n", count);
			break;
		case 9:
			Sort(&My_DulList);
			break;
		case 10:
			printf("������Ҫ��ֵɾ����ֵ��>\n");
			scanf_s("%d", &e);
			Delete_val(&My_DulList, e);
			break;
		case 11:
			Inverse(&My_DulList);
			break;
		case 12:
			Clear(&My_DulList);
			break;
		case 13:
			//Destory(&My_DulList);
			break;
		default:
			break;
		}
	}
}