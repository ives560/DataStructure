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
	sqlist.length = 6;

	sqlist.data[1] = 8;
	sqlist.data[2] = 2;
	sqlist.data[3] = 4;
	sqlist.data[4] = 9;
	sqlist.data[5] = 5;
	sqlist.data[6] = 3;

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
	sqlist.length = 8;

	sqlist.data[1] = 50;
	sqlist.data[2] = 10;
	sqlist.data[3] = 90;
	sqlist.data[4] = 30;
	sqlist.data[5] = 70;
	sqlist.data[6] = 40;
	sqlist.data[7] = 80;
	sqlist.data[8] = 60;
	//sqlist.data[9] = 20;

	Sort<int> sort(&sqlist);

	sort.QuickSort();

}

#include "HuffmanTree.h"
//霍夫曼编码测试
void HuffmanCodingText()
{
	
	HuffmanCode code;
	Huffman hfm;
	int wight[5] = {5,4,3,2,1};
	HuffmanTree tree = hfm.create_HuffmanTree(wight, 5);
	hfm.HuffmanCoding(tree, code, 5);
}

//希尔排序测试
void ShellSortText()
{
	SqList<int> sqlist;
	sqlist.length = 9;

	sqlist.data[1] = 9;
	sqlist.data[2] = 1;
	sqlist.data[3] = 5;
	sqlist.data[4] = 8;
	sqlist.data[5] = 3;
	sqlist.data[6] = 7;
	sqlist.data[7] = 4;
	sqlist.data[8] = 6;
	sqlist.data[9] = 2;

	Sort<int> sort(&sqlist);

	sort.ShellSort();
}



int main()
{

	//InsertSortText();
	ShellSortText();
    return 0;
}

