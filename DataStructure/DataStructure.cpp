// DataStructure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"
#include "Sort.h"

ZO_USE_NAMESPACE

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
	/*******************列表测试**************************/
	List<int> list;

	list.InitList();
	list.insert( 1, 6);
	list.insert( 1, 7);
	//list.insert(1, 8);
	//list.insert(1, 9);

	//ElemType e;
	//list.listDelete( 3, e);

	//SLinkList slist;

	//list.InitList(slist);
	//list.ListInsert(slist,1, 6);


	/***************排序测试*******************/
	SqList<int> sqlist;
	sqlist.length = 5;
	sqlist.data[0] = 1;
	sqlist.data[1] = 8;
	sqlist.data[2] = 2;
	sqlist.data[3] = 4;
	sqlist.data[4] = 9;
	sqlist.data[5] = 5;

	Sort<int> sort(&sqlist);

	sort.BubbleSort0();

    return 0;
}

