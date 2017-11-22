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

//堆排序测试
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

//并归排序测试
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

//图测试
#include "Graph.h"
void GraphText()
{
	GraphAdjList G;
	Graph graph;
	EdgeNode *e;

	graph.CreateALGraph(&G);

	graph.BFSTraverse(&G);
}

//构件图,测试最小生成树
void CreateMGraph(MGraph *G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 15;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

//测试最小生成树
void MiniSpanTree_PrimText()
{
	MGraph G;
	Graph graph;
	CreateMGraph(&G);
	graph.MiniSpanTree_Prim(G);
}



int main()
{

	//InsertSortText();
	MiniSpanTree_PrimText();
    return 0;
}

