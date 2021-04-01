#include"THREAD.h"

int main()
{
	const char* TreeCode = "ABC##DE##F##G#H##";
	ThreadTree MyTree;
	InitTreadTree(&MyTree, '#');
	CreateThreadTree(&MyTree, TreeCode);
	CreateInThread(&MyTree);

}