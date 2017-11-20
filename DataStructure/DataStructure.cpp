// DataStructure.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌĞòµÄÈë¿Úµã¡£
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

//ºóĞøËãÊı±í´ïÊ½ÔËËã
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

/*******************ÁĞ±í²âÊÔ**************************/
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

//Ã°ÅİÅÅĞò²âÊÔ
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

//²åÈëÅÅĞò²âÊÔ
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

//¿ìËÙÅÅĞò²âÊÔ
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
//»ô·òÂü±àÂë²âÊÔ
void HuffmanCodingText()
{
	
	HuffmanCode code;
	Huffman hfm;
	int wight[5] = {5,4,3,2,1};
	HuffmanTree tree = hfm.create_HuffmanTree(wight, 5);
	hfm.HuffmanCoding(tree, code, 5);
}

//Ï£¶ûÅÅĞò²âÊÔ
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

//¶ÑÅÅĞò²âÊÔ
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



int main()
{

	//InsertSortText();
	HeapSortText();
    return 0;
}

