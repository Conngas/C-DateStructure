#pragma once
#ifndef GENLIST_H
#define GENLIST_H

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#define AutoType int

typedef enum {HEAD,AUTO,CHILDLIST}ElemTag;
typedef struct GLNode
{
	ElemTag	tag;
	union
	{
		struct GLNode* hp;
		AutoType atom;
	};
	struct GLNode* tp;
}GLNode;

typedef GLNode* GenList;

void GLInit(GenList& gl);
void CreateGenList(GenList& gl, const char* str);
bool serve(char* sub, char* hsub);
void ShowGenList(GenList& gl);
bool GenListEmpty(GenList& gl);
int  GenListLength(GenList& gl);
int GenListDepth(GenList& gl);
void ClearGenList(GenList& gl);

#endif // !GENLIST_H

