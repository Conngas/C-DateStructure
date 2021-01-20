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

void TransposeMatrix(SMatrix* M, SMatrix* T)
{
	T->c_num = M->r_num;
	T->r_num = M->c_num;
	T->nz_num = M->nz_num;

	int k = 0;
	if (M->nz_num != 0)
	{
		for (int col = 0;col < M->c_num;++col)
		{
			for (int nz_num = 0;nz_num < M->nz_num;++nz_num)
			{
				if (M->data[nz_num].c == col)
				{
					T->data[k].c = M->data[nz_num].r;
					T->data[k].r = M->data[nz_num].c;
					T->data[k].e = M->data[nz_num].e;
					++k;
				}
			}
		}
	}
}

void FastTransposeMatrix(SMatrix* M, SMatrix* T)
{
	T->c_num = M->r_num;
	T->r_num = M->c_num;
	T->nz_num = M->nz_num;

	int* num = (int*)malloc(sizeof(int) * M->nz_num);
	assert(num != 0);
	int* copt = (int*)malloc(sizeof(int) * M->nz_num);
	assert(copt != 0);
	memset(num, 0, sizeof(int) * M->nz_num);
	memset(copt, 0, sizeof(int) * M->nz_num);

	if (M->nz_num != 0)
	{
		for (int pos = 0;pos < M->nz_num;++pos)//
		{
			num[M->data[pos].c]++;
		}
		for (int add = 1;add < M->nz_num;++add)
		{
			copt[add] = copt[add - 1] + num[add - 1];
		}
	}
	int q = 0;
	for (int i = 0;i < M->nz_num;++i)
	{
		int col = M->data[i].c;
		q = copt[col];
		T->data[q].c = M->data[i].r;
		T->data[q].r = M->data[i].c;
		T->data[q].e = M->data[i].e;
		copt[col]++;
	}
	free(copt);
	free(num);
}
