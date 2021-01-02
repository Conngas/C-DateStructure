#include"SString.h";

int main()
{
	char ar[] = {'a','b','c','d'};
	char ar1[] = "abcd";
	const char* p = "cwyjq";

	SString becopied;
	InitString(becopied);
	Assign(becopied, p);
	Print(becopied);

	SString str;
	InitString(str);
	Assign(str, ar1);
	Print(str);

	printf("%d", StrCompare(str, becopied));
	//if (StrCompare(becopied,str) > 0)
	//{
	//	printf("第一个大");
	//}
	//else if (StrCompare(str, becopied) > 0)
	//{
	//	printf("第二个大");
	//}
	//else
	//	printf("一样大");

	StrCopy(str, becopied);
	Print(str);
}