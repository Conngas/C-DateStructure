#pragma once
#ifndef SSTRING_H_
#define SSTRING_H_
#define MAXSTRINGLEN 20
#include<stdio.h>
#include<string.h>

#define u_char unsigned char
typedef u_char SString[MAXSTRINGLEN + 1];

void InitString(SString s);
void Assign(SString s, char* c);




#endif // !SSTRING_H_

