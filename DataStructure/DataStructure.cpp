// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"

int op(int a, char Op, int b)
{
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a*b;
	if (Op == '/')
	{
		if (b == 0)
		{
			return 0;
		}
		else
		{
			return a / b;
		}
	}
}

//后续算数表达式运算
int com(char exp[])
{
	int i, a, b, c;
	int stack[MAX];
	int top = -1;

	char Op;
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] >= '0'&&exp[i] <= '9')
		{
			stack[++top] = exp[i] - '0';
		}
		else
		{
			Op = exp[i];
			b = stack[top--];
			a = stack[top--];
			c = op(a, Op, b);
			stack[++top] = c;
		}
	}
	return stack[top];
}

int main()
{
	List list;

	list.InitList(list.list);
	list.insert(list.list, 1, 6);
	list.insert(list.list, 1, 7);
	list.insert(list.list, 1, 8);
	list.insert(list.list, 1, 9);

	ElemType e;
	list.listDelete(list.list, 3, e);

	SLinkList slist;

	list.InitList(slist);
	list.ListInsert(slist,1, 6);

    return 0;
}

