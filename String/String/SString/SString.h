#pragma once
#ifndef SSTRING_H_
#define SSTRING_H_

#define MAXSIZE 20
#define u_char unsigned char

#include<stdio.h>
#include<string.h>

typedef u_char SString[MAXSIZE + 1];//+1为了给\0留空间

void InitString(SString S);
void StrAssign(SString S, char* str);
void PrintString(SString S);
void StrCopy(SString A, SString B);
int  StrLength(SString S);
bool StrCompare(SString S,SString T);




#endif // !SSTRING_H_

