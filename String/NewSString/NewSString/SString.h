#pragma once
#ifndef SSTRING_H_
#define SSTRING_H_
#define MAXSTRINGLEN 20
#include<stdio.h>
#include<string.h>

#define u_char unsigned char
typedef u_char SString[MAXSTRINGLEN + 1];

void InitString(SString s);
void Assign(SString s, const char* c);
int Length(SString s);
void Print(SString s);
void StrCopy(SString s,SString t);
void StrEmpty(SString s);
int StrCompare(SString s,SString t);
void StrConcat(SString T, SString a, SString b);

#endif // !SSTRING_H_

