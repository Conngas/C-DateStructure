#include"BinTree.h"

int main()
{
	const char* BTInfo = "ABC##DE##F##G#H##";
	BinTree MyBinTree;
	InitBinTree(&MyBinTree,'#');

	//CreateBinTree_Node(&MyBinTree);
	CreateBinTree_Str(&MyBinTree, BTInfo);

	PreOrder(&MyBinTree);
	printf("\t");
	InOrder(&MyBinTree);
	printf("\t");
	PostOrder(&MyBinTree);
	printf("\n");

	//LevelOrder(&MyBinTree);

	//������������������
	/*printf("%d\n", Size(&MyBinTree));
	printf("%d\n", Height(&MyBinTree));

	BinTreeNode* b = Search(&MyBinTree, 'F');
	BinTreeNode* p = Parent(&MyBinTree, b);

	BinTree YourBinTree;
	InitBinTree(&YourBinTree, '#');

	Copy(&MyBinTree, &YourBinTree);

	Clear(&YourBinTree);*/

	//�Ǳ�������������
	/*NoPreOrder(&MyBinTree);
	printf("\n");
	NoInOrder(&MyBinTree);
	printf("\n");
	*/

	const char* VLR = "ABCDEFGH";
	const char* LVR = "CBEDFAGH";
	const char* LRV = "CEFDBHGA";
	int n = strlen(VLR);

	//CreateBinTree_VLR(&MyBinTree, VLR, LVR, n);
	CreateBinTree_LRV(&MyBinTree, LRV, LVR, n);
	PreOrder(&MyBinTree);
	printf("\t");
	InOrder(&MyBinTree);
	printf("\t");
	PostOrder(&MyBinTree);
	printf("\t");
}