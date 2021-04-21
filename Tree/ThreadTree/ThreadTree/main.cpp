#include"THREAD.h"

int main()
{
	const char* TreeCode = "ABC##DE##F##G#H##";
	ThreadTree MyTree;
	InitTreadTree(&MyTree, '#');
	CreateThreadTree(&MyTree, TreeCode);
	CreateInThread(&MyTree);
	
	/*
	ThreadTreeNode* p;
	p = LastNode(&MyTree);
	printf("%c", p->data);
	*/
	/*
	//Order Test
	InOrder(&MyTree);
	*/
	//Search Test
	ThreadTreeNode* bt = Search(&MyTree, 'D');
	ThreadTreeNode* parent = Parents(&MyTree, bt);
}