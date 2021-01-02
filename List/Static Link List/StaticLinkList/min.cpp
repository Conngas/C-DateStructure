#include "StaticHead.h"
#include <iostream>

using namespace std;

void main()
{
	StaticLinkList SL;
	InitStatic(SL);

	for (int i = 1; i < 5; i++)
	{
		InsertStatic(SL, 'A' +i -1);
	}
	ListShow(SL);
	DeleteList(SL);
	ListShow(SL);
}