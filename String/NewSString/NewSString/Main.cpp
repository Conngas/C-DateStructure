#include"SString.h";

//int main()
//{
//	char ar[] = {'a','b','c','d'};
//	char ar1[] = "abcd";
//	const char* p = "cwyjq";
//
//	SString becopied;
//	InitString(becopied);
//	Assign(becopied, p);
//	Print(becopied);
//
//	SString str;
//	InitString(str);
//	Assign(str, ar1);
//	Print(str);
//
//	printf("%d", StrCompare(str, becopied));
//	//if (StrCompare(becopied,str) > 0)
//	//{
//	//	printf("第一个大");
//	//}
//	//else if (StrCompare(str, becopied) > 0)
//	//{
//	//	printf("第二个大");
//	//}
//	//else
//	//	printf("一样大");
//
//	/*Example2
//	StrCopy(str, becopied);
//	Print(str);
//	*/
//}

int main()
{
	char a[] = "abcdsdfsegr";
	const char* b = "efghfafeafsefsef";
	const char* p = "cwyjq";
	
	SString FristStr;
	InitString(FristStr);
	Assign(FristStr, p);
	
	SString Astr;
	InitString(Astr);
	Assign(Astr, a);

	SString Bstr;
	InitString(Bstr);
	Assign(Bstr, b);

	SString Teststr;
	InitString(Teststr);

	Print(FristStr);
	Print(Astr);
	Print(Bstr);
	/*StrConcat
	StrConcat(FristStr, Astr, Bstr);
	Print(FristStr);
	*/
	/*Strsub
	Strsub(FristStr, Teststr, 4, 5);
	Print(Teststr);
	*/
	/*StrInsert
	StrInsert(FristStr, Bstr, 2);
	Print(FristStr);
	*/
	StrDelete(FristStr, 2, 2);
	Print(FristStr);
}