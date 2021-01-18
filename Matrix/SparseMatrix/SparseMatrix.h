#pragma once
#ifndef SPAREMATRIX_H

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define ElemType int
#define MAXSIZE 100

typedef struct Triple
{
	int r;
	int c;
	ElemType e;
}Triple;

typedef struct SMatrix
{
	Triple data[MAXSIZE];
	int r_num;
	int c_num;
	int nz_num;
};

int CreateMatrix(SMatrix* sm);
void PrintMatrix(SMatrix* sm);
void CopyMatrix(SMatrix* Copy, SMatrix* Paste);
void SubMatrix(SMatrix* A, SMatrix* B);
void SupMatrix(SMatrix* A, SMatrix* B);
void MulMatrix(SMatrix* A, SMatrix* B);
void 
#endif // SPAREMATRIX_H

