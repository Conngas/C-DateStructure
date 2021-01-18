#include"SparseMatrix.h"

int CreateMatrix(SMatrix* sm)
{
	//老的FILE用法
	//FILE* fp = fopen("Matrix.txt", "r");

	//新的FILE安全版用法
	FILE* fp;
	errno_t err = fopen_s(&fp, "Matrix.txt", "r");

	if (fp == NULL)exit(1);

	int temp = fscanf_s(fp, "%d %d", &sm->r_num, &sm->c_num);

	int nz = 0;
	ElemType value;

	for (int i = 0;i < sm->r_num;++i)
	{
		for (int j = 0;j < sm->c_num;++j)
		{
			fscanf_s(fp, "%d", &value);
			if (value != 0)
			{
				sm->data[nz].e = value;
				sm->data[nz].r = i;
				sm->data[nz].c = j;
				++nz;
			}
		}
	}
	sm->nz_num = nz;
	fclose(fp);
	return temp;
}

void PrintMatrix(SMatrix* sm)
{
	printf_s("Row = %d,Column = %d\n", sm->r_num, sm->c_num);
	for (int i = 0;i < sm->nz_num;++i)
	{
		printf_s("( %d , %d , %d )\n", sm->data[i].r, sm->data[i].c, sm->data[i].e);
	}
}

void CopyMatrix(SMatrix* Copy, SMatrix* Paste)
{
	Paste->r_num = Copy->r_num;
	Paste->c_num = Copy->c_num;
	Paste->nz_num = Copy->nz_num;
	for (int i = 0;i < Copy->nz_num;++i)
	{
		Paste->data[i].e = Copy->data[i].e;
		Paste->data[i].c = Copy->data[i].c;
		Paste->data[i].r = Copy->data[i].r;
	}
}
