#pragma once
#ifndef BINTREE_H_
#define BINTREE_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* LeftChild;
	struct BinTreeNode* RightChild;
}BinTreeNode;

typedef struct BinTreeNode* ToChild;

typedef struct BinTree
{
	BinTreeNode* Root;
	ElemType refvalue;//Stop Flag
};


void InitBinTree(BinTree* bt, ElemType ref);
void CreateBinTree(BinTree* bt);
void CreateBinTree(BinTree* bt, BinTreeNode** node);

void CreateBinTree_C(BinTree* bt);
void CreateBinTree_C_1(BinTree* bt, ToChild* node);
void CreateBinTree_C_2(BinTree* bt);

void CreateBinTree_Cpp(BinTree* bt);
void CreateBinTree_Cpp(BinTree* bt, BinTreeNode*& node);

void CreateBinTree_Node(BinTree* bt);
BinTreeNode* CreateBinTree_Node_(BinTree* bt);

void CreateBinTree_Str(BinTree* bt,const char*str);
void CreateBinTree_Str(BinTree* bt, BinTreeNode*& node, const char* &str);

#endif // !BINTREE_H_


