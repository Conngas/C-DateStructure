#pragma once
#ifndef BINTREE_H_
#define BINTREE_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<iostream>

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

//Init
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

void PreOrder(BinTree* bt);
void PreOrderNode(BinTreeNode* node);
void InOrder(BinTree* bt);
void InOrderNode(BinTreeNode* node);
void PostOrder(BinTree* bt);
void PostOrderNode(BinTreeNode* node);
void LevelOrder(BinTree* bt);
void LevelOrderNode(BinTreeNode* node);

//Function
int Size(BinTree* bt);
int Size(BinTreeNode* node);

int Height(BinTree* bt);
int Height(BinTreeNode* node);

BinTreeNode* Search(BinTree* bt,ElemType key);
BinTreeNode* Search(BinTreeNode*node, ElemType key);

BinTreeNode* Parent(BinTree* bt, BinTreeNode* node);
BinTreeNode* Parent(BinTreeNode* bt, BinTreeNode* node);

BinTreeNode* LeftChild(BinTreeNode* node);
BinTreeNode* RightChild(BinTreeNode* node);

bool IsEmpty(BinTree* bt);

void Copy(BinTree* s,BinTree* d);
void Copy(BinTreeNode*& source, BinTreeNode*& destination);

void Clear(BinTree* bt);
void Clear(BinTreeNode*& node);
#endif // !BINTREE_H_


