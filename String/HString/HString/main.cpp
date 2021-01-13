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
	HStrDelete(&myHStr, 2, 7);
	HStrClear(&myHStr);
	HStrPrint(&myHStr);
}