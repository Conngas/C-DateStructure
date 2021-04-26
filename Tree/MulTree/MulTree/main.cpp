#include"MulTree.h"

int main()
{
	const char* cOrder = "RAD#E##B#CFG#H#K#####";
	SMulTree SMyTree;
	InitMulTree(&SMyTree, '#');
	CreateMulTree(&SMyTree, cOrder);

	SMulNode* pSRec = FindKey(&SMyTree, 'C');
	SMulNode* pSPar = FindParent(&SMyTree, pSRec);
}