#include"StaticLink.h"

int main()
{
	StaticList SL;
	InistStatic(SL);
	for (int i = 0;i <= 5;++i)
	{
		Insert(SL, 'A' + i);
	}
	Show_Static(SL);
	Delete(SL);
	Show_Static(SL);
}