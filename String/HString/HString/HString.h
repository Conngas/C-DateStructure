#pragma once
#ifndef HSTRING_H
#define HSTRING_H

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef struct HString
{
	char* ch;
	int	length = 0;
}HString;

void HStrInit(HString *main);
void HStrAssign(HString* main,const char* str);
void HStrPrint(HString* main);
int	 HStrLength(HString* main);
void HStrCopied(HString* main, HString* Origin);
int	 HStrCompare(HString* A, HString* B);
void HStrComcat(HString* main, HString* A, HString* B);
void HStrSub(HString* main, HString* sub, int pos, int len);
void HStrInsert(HString* main, HString* in, int pos);
void HStrDelete(HString* main, int pos,int len);
void HStrClear(HString* main);
#endif // HSTRING_H

