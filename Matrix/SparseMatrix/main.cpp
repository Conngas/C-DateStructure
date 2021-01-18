#include"SparseMatrix.h"

int main()
{
	SMatrix sm,sm1;
	memset(&sm, 0, sizeof(sm));
	CreateMatrix(&sm);
	PrintMatrix(&sm);

	//CopyTest
	CopyMatrix(&sm, &sm1);
	PrintMatrix(&sm1);
}