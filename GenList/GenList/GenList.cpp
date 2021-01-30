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

	else if (zeroJudge != 0) exit(1);
	else
	{
		strcpy_s(hsub, n + 1, sub);
		//strcpy_s(hsub, n + 1, sub);
		sub[0] = '\0';
	}

	return true;
}

void ShowGenList(GenList& gl)
{
	GenList p = gl->tp;
	printf("(");
	while (p != NULL)
	{
		if (p->tag == AUTO)
		{
			printf("%d", p->atom);
			if (p->tp != NULL) printf(",");
			p = p->tp;
		}
		else if (p->tag == CHILDLIST)
		{
			ShowGenList(p->hp);
			if(p->tp!=NULL)	printf(",");
			p = p->tp;
		}
	}

	printf(")");
}

bool GenListEmpty(GenList& gl)
{
	return gl->tp == NULL;
}

int  GenListLength(GenList& gl)
{
	int length=0;
	GLNode* p = gl->tp;
	while(p != NULL)
	{
		++length;
		p = p->tp;
	}
	return length;
}

int GenListDepth(GenList& gl)
{
	if (gl == NULL) return 1;
	int MaxDepth = 0;
	int dep = 0;
	GLNode* p = gl->tp;
	while (p != NULL)
	{
		if (p->tag == CHILDLIST)
		{
			dep =  GenListDepth(p->hp->tp);
			if (dep > MaxDepth)	MaxDepth = dep;
		}
		p = p->tp;
	}
	return MaxDepth + 1;
}

void ClearGenList(GenList& gl)
{
	if (gl == NULL)	return;
	GLNode* p = gl->tp;
	GLNode* lp = NULL;
	free(gl);//删除头节点,并置空
	//gl = NULL;
	while (p != NULL)
	{
		if (p->tp != NULL)	lp = p->tp;
		else lp = NULL;
		if (p->tag == AUTO)
		{
			free(p);
			p = lp;
		}
		else if (p->tag == CHILDLIST)
		{
			ClearGenList(p->hp);
			free(p);
			p = lp;
		}
	}

}