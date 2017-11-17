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

/*******************列表测试**************************/
void ListText()
{

	List<int> list;

	list.InitList();
	list.insert(1, 6);
	list.insert(1, 7);
	//list.insert(1, 8);
	//list.insert(1, 9);

	//ElemType e;
	//list.listDelete( 3, e);

	//SLinkList slist;

	//list.InitList(slist);
	//list.ListInsert(slist,1, 6);
}

//冒泡排序测试
void BubbleSortText()
{
	SqList<int> sqlist;
	sqlist.length = 7;

	sqlist.data[1] = 38;
	sqlist.data[2] = 65;
	sqlist.data[3] = 97;
	sqlist.data[4] = 76;
	sqlist.data[5] = 13;
	sqlist.data[6] = 27;
	sqlist.data[7] = 10;

	Sort<int> sort(&sqlist);

	sort.BubbleSort();
}

//插入排序测试
void InsertSortText()
{
	SqList<int> sqlist;
	sqlist.length = 5;

	sqlist.data[1] = 1;
	sqlist.data[2] = 9;
	sqlist.data[3] = 4;
	sqlist.data[4] = 6;
	sqlist.data[5] = 2;

	Sort<int> sort(&sqlist);

	sort.InsertSort();
}

//快速排序测试
void QuickSortText()
{
	SqList<int> sqlist;
	sqlist.length = 15;

	sqlist.data[1] = 50;
	sqlist.data[2] = 10;
	sqlist.data[3] = 90;
	sqlist.data[4] = 30;
	sqlist.data[5] = 70;
	sqlist.data[6] = 40;
	sqlist.data[7] = 80;
	sqlist.data[8] = 60;
	sqlist.data[9] = 20;
	sqlist.data[10] = 36;
	sqlist.data[11] = 82;
	sqlist.data[12] = 27;
	sqlist.data[13] = 41;
	sqlist.data[14] = 53;
	sqlist.data[15] = 68;

	Sort<int> sort(&sqlist);

	sort.QuickSort();

}

int main()
{

	BubbleSortText();

    return 0;
}

