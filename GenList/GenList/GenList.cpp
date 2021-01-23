#include"GenList.h"

void GLInit(GenList& gl)
{
	gl = NULL;
}

void CreateGenList(GenList& gl, const char* str)
{
	int n = strlen(str);
	char* sub = (char*)malloc(sizeof(char) * (n-1));
	char* hsub = (char*)malloc(sizeof(char) * (n-1));
	assert(sub != NULL && hsub != NULL);


	//Old strcpy Fun
	//strncpy(sub, str+1, n - 2);
	//strncpy(sub, str + 1, n - 2);
	strncpy_s(sub,sizeof(*sub)*(n-1),str+1,n-2);//+1表示从括号后开始计算
	//sub[n - 2] = '\0';//配合老版本的strncpy使用

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
		p->hp = p->tp = NULL;

		if (serve(sub, hsub))
		{
			if (hsub[0] == '(')
			{
				p->tag = CHILDLIST;
				CreateGenList(p->hp, hsub);
			}
			else
			{
				p->tag = AUTO;
				p->atom = atoi(hsub);
			}
			
		}

	}

	free(sub);
	free(hsub);
}

bool serve(char* sub, char* hsub)
{
	if (*sub == '\0' || strcmp(sub, "()"))
	{
		hsub[0] = '\0';
	}

	int n = strlen(sub);
	int zeroJudge = 0;
	int barrier = 0;
	char ch = sub[0];
	while (barrier < n && (zeroJudge != 0 || ch != ','))//截断左右两个表
	{
		if (ch == '(')
			++zeroJudge;
		if (ch == ')')
			--zeroJudge;
		++barrier;
		ch = sub[barrier];
	}

	if (barrier < n)
	{
		sub[barrier] = '\0';
		strcpy_s(hsub,barrier+1,sub);
		strcpy_s(sub, n - barrier + 2, sub + barrier + 1);
	}

	else if (zeroJudge != 0) return false;
	else
	{
		strcpy_s(hsub, n + 1, sub);
		//strcpy_s(hsub, n + 1, sub);
		sub[0] = '\0';
	}

	return true;
}