#include"HString.h"

int main()
{
	HString myHStr;
	HStrInit(&myHStr);

	const char *Isolatestr= "abdefghj";
	const char* Teststr = "def";
	char Testchar[] = { 'a','b','d' };

	HStrAssign(&myHStr, Isolatestr);
	HStrPrint(&myHStr);

	HString myTeststr;
	HStrInit(&myTeststr);
	HStrAssign(&myTeststr, Teststr);
	HStrPrint(&myTeststr);
	/*Copy
	HStrCopied(&myTeststr,&myHStr);
	HStrPrint(&myHStr);
	*/
	/*
	HStrAssign(&myTeststr, Testchar);
	int res = HStrCompare(&myHStr, &myTeststr);
	*/
	/*
	HStrAssign(&myTeststr, Teststr);
	HStrPrint(&myTeststr);

	HString Comcatstr;
	HStrInit(&Comcatstr);
	HStrComcat(&Comcatstr, &myHStr, &myTeststr);
	HStrPrint(&Comcatstr);
	*/
	/*
	HStrSub(&myHStr, &myTeststr, 2, 2);
	HStrPrint(&myTeststr);
	*/
	/*
	HStrAssign(&myTeststr, "Can I insert?");
	HStrInsert(&myHStr, &myTeststr, 2);
	HStrPrint(&myHStr);
	*/
	/*
	HStrDelete(&myHStr, 2, 7);
	HStrClear(&myHStr);
	HStrPrint(&myHStr);*/
	/*
	int res = HStrMap(&myHStr, &myTeststr, 0);*/
	/*
	HString Rep;
	HStrInit(&Rep);
	HStrAssign(&Rep, "--");

	HStrReplace(&myHStr, &myTeststr, &Rep);
	HStrPrint(&myHStr);*/
	int res = KMP(&myHStr, &myTeststr, 0);
}