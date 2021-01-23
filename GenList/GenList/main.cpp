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
	const char* gg = "(1,(2,(3,4),5)";

	CreateGenList(mygl, ge);
}