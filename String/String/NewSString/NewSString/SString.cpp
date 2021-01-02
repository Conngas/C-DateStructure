#include"SString.h";

void InitString(SString s)
{
	s[0] = '\0';
}

void Assign(SString s, char* c)
{
	int len = strlen(c);
	for (int i = 0; i < len; ++i)
	{
		s[i] = c[i];
	}
	s[len + 1] = '\0';
}