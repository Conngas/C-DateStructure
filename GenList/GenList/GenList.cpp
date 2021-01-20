#include"GenList.h"

void GLInit(GenList& gl)
{
	gl = NULL;
}

void CreateGenList(GenList& gl, char* str)
{
	int n = strlen(str);
	char* sub = (char*)malloc(sizeof(char) * (n - 2));
	char* hsub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && hsub != NULL);


	//Old strcpy Fun
	//strncpy(sub, str+1, n - 2);
	strncpy_s(sub, sizeof(char), str+1, (n - 2));//+1表示从括号后开始计算
	sub[n - 2] = '\0';

	if (gl == NULL)
	{
		gl = (GenList)malloc(sizeof(GLNode));//注意GLNode是存储单位大小，GenList = GLNode*
		assert(gl != NULL);
		gl->hp = gl->tp = NULL;
		gl->tag = HEAD;
	}

	GLNode* p = gl;
	while (strlen(sub) != 0)
	{
		p = p->tp = (GenList)malloc(sizeof(GLNode));
		assert(p != NULL);
		if (serve(sub, hsub))
		{
			if (hsub[0] == '(')
			{
				p->tag = CHILDLIST;
				CreateGenList(p->tp, hsub);
			}
			else
			{
				p->tag = AUTO;
				p->atom = TransAtom(hsub);
			}
			
		}

	}
}

bool serve(char* sub, char* hsub)
{

}