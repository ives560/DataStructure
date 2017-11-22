// DataStructure.cpp : ∂®“Âøÿ÷∆Ã®”¶”√≥Ã–Úµƒ»Îø⁄µ„°£
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

//∫Û–¯À„ ˝±Ì¥Ô Ω‘ÀÀ„
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

/*******************¡–±Ì≤‚ ‘**************************/
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

//√∞≈›≈≈–Ú≤‚ ‘
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

//≤Â»Î≈≈–Ú≤‚ ‘
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

//øÏÀŸ≈≈–Ú≤‚ ‘
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
//ªÙ∑Ú¬¸±‡¬Î≤‚ ‘
void HuffmanCodingText()
{
	
	HuffmanCode code;
	Huffman hfm;
	int wight[5] = {5,4,3,2,1};
	HuffmanTree tree = hfm.create_HuffmanTree(wight, 5);
	hfm.HuffmanCoding(tree, code, 5);
}

//œ£∂˚≈≈–Ú≤‚ ‘
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

//∂—≈≈–Ú≤‚ ‘
void HeapSortText()
{
	SqList<int> sqlist;
	sqlist.length = 9;

	sqlist.data[1] = 50;
	sqlist.data[2] = 10;
	sqlist.data[3] = 90;
	sqlist.data[4] = 30;
	sqlist.data[5] = 70;
	sqlist.data[6] = 40;
	sqlist.data[7] = 80;
	sqlist.data[8] = 60;
	sqlist.data[9] = 20;

	Sort<int> sort(&sqlist);

	sort.HeapSort();
}

//≤¢πÈ≈≈–Ú≤‚ ‘
void MergeSortText()
{
	SqList<int> sqlist;
	sqlist.length = 9;

	sqlist.data[1] = 50;
	sqlist.data[2] = 10;
	sqlist.data[3] = 90;
	sqlist.data[4] = 30;
	sqlist.data[5] = 70;
	sqlist.data[6] = 40;
	sqlist.data[7] = 80;
	sqlist.data[8] = 60;
	sqlist.data[9] = 20;

	Sort<int> sort(&sqlist);

	sort.MergeSort2();
}

//Õº≤‚ ‘
#include "Graph.h"
void GraphText()
{
	GraphAdjList G;
	Graph graph;
	graph.CreateALGraph(&G);
	graph.DFSTraverse(&G);
}



int main()
{

	//InsertSortText();
	GraphText();
    return 0;
}

