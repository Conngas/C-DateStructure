#include"BinTree.h"

int main()
{
	const char* BTInfo = "ABC##DE##F##G#H##";
	BinTree MyBinTree;
	InitBinTree(&MyBinTree,'#');

	//CreateBinTree_Node(&MyBinTree);
	CreateBinTree_Str(&MyBinTree, BTInfo);

	//PreOrder(&MyBinTree);

	//LevelOrder(&MyBinTree);

	//适用于树的其他操作
	/*printf("%d\n", Size(&MyBinTree));
	printf("%d\n", Height(&MyBinTree));

	BinTreeNode* b = Search(&MyBinTree, 'F');
	BinTreeNode* p = Parent(&MyBinTree, b);

	BinTree YourBinTree;
	InitBinTree(&YourBinTree, '#');

	Copy(&MyBinTree, &YourBinTree);

	Clear(&YourBinTree);*/

	//非遍历二叉树搜索
	NoPreOrder(&MyBinTree);
	printf("\n");
	NoInOrder(&MyBinTree);
	printf("\n");
}