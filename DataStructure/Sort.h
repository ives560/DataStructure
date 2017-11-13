#pragma once
#include "Comm.h"
#include "List.h"

class Sort
{
public:
	Sort();
	~Sort();
	// 交换L中数组r的下标为i和j的值
	void swap(SqList* L, int i, int j);
	// 对顺序表L作交换排序（冒泡排序初级版）
	void BubbleSort0(SqList* L);
	// 对顺序表L作冒泡排序
	void BubbleSort(SqList* L);
	// 对顺序表L作改进冒泡算法
	void BubbleSort2(SqList* L);
	// 对顺序表L作简单选择排序
	void SelectSort(SqList* L);
	// 对顺序表L作直接插入排序
	void InsertSort(SqList* L);
	// 对顺序表L作希尔排序
	void ShellSort(SqList* L);
	void HeapAdjust(SqList* L, int s, int m);
	// 对顺序表L进行堆排序
	void HeapSort(SqList* L);
	// 对顺序表L作归并排序
	void MergeSort(SqList* L);
	void MSort(int SR[], int TR1[], int s, int t);
	// 对顺序表L作快速排序	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// 对顺序表L作快速排序	
	void QuickSort(SqList* L);
	// 对顺序表L中的子序列L->data作快速排序
	void QSort(SqList* L, int low, int high);
	// 交换顺序表L中子表的记录
	int Partition(SqList* L, int low, int high);
};

