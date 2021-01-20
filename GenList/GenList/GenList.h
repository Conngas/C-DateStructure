#pragma once
#ifndef GENLIST_H
#define GENLIST_H

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
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
};

typedef GLNode* GenList;

void GLInit(GenList& gl);
void CreateGenList(GenList& gl, char* str);

#endif // !GENLIST_H

