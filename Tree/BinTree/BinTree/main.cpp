#include"BinTree.h"

int main()
{
	const char* BTInfo = "ABC##DE##F##G#H##";
	BinTree MyBinTree;
	InitBinTree(&MyBinTree,'#');

	//CreateBinTree_Node(&MyBinTree);
	CreateBinTree_Str(&MyBinTree, BTInfo);

	//PreOrder(&MyBinTree);

	LevelOrder(&MyBinTree);

}