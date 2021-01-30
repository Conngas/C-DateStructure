#include"GenList.h"

int main()
{
	GenList mygl;
	GLInit(mygl);

	const char* ga = "(1,2,3)";
	const char* gb = "(1,(2,3))";
	const char* gc = "(1,(2),3)";
	const char* gd = "((1,2),3)";
	const char* ge = "((1,2,3))";
	const char* gf = "()";
	const char* gg = "(1,(2,(3,(0,()),4)),5)";

	CreateGenList(mygl, gg);
	ShowGenList(mygl);
	int len = 0;
	int dep = 0;
	len = GenListLength(mygl);
	dep = GenListDepth(mygl);
	printf("Len=%d,Dep=%d", len, dep);
	ClearGenList(mygl);
}