#pragma once
#ifndef HSTRING_H
#define HSTRING_H

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

#define DPLength 20

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
int	 HStrMap(HString* main, HString* sub, int pos);
void HStrReplace(HString* main, HString* sub, HString* rep);
int KMP(HString* main, HString* sub);
int KMP(HString* main, HString* sub,int pos);
void BuildNext(HString* sub, int* next);
void BuildNextval(HString* sub, int* nextval);
#endif // HSTRING_H

