#pragma once
#include "Comm.h"
#include "List.h"

ZO_BEGIN_MAMESPACE

//排序类
template <typename T>
class Sort
{

private:
	SqList<T> *L;

public:
	Sort(SqList<T> *list);
	~Sort();
	// 交换L中数组r的下标为i和j的值
	void swap(int i, int j);
	// 对顺序表L作交换排序（冒泡排序初级版）
	void BubbleSort0();
	// 对顺序表L作冒泡排序
	void BubbleSort();
	// 对顺序表L作改进冒泡算法
	void BubbleSort2();
	// 对顺序表L作简单选择排序
	void SelectSort();
	// 对顺序表L作直接插入排序
	void InsertSort();
	// 对顺序表L作希尔排序
	void ShellSort();
	void HeapAdjust(int s, int m);
	// 对顺序表L进行堆排序
	void HeapSort();
	// 对顺序表L作归并排序
	void MergeSort();
	void MSort(int SR[], int TR1[], int s, int t);
	// 对顺序表L作快速排序	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// 对顺序表L作快速排序	
	void QuickSort();
	// 对顺序表L中的子序列L->data作快速排序
	void QSort(int low, int high);
	// 交换顺序表L中子表的记录
	int Partition(int low, int high);

};

template <typename T>
Sort<T>::Sort(SqList<T> *list)
{
	L = list;
}

template <typename T>
Sort<T>::~Sort()
{
}


// 交换L中数组r的下标为i和j的值
template <typename T>
void Sort<T>::swap(int i, int j)
{
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}


// 对顺序表L作交换排序（冒泡排序初级版）
template <typename T>
void Sort<T>::BubbleSort0()
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->data[i]>L->data[j])
			{
				swap( i, j);//交换L->data[i]与L->data[j]的值
			}
		}
	}
}


// 对顺序表L作冒泡排序
template <typename T>
void Sort<T>::BubbleSort()
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->data[j]>L->data[j + 1])
			{
				swap(L, j, j + 1);
			}
		}
	}
}


// 对顺序表L作改进冒泡算法
template <typename T>
void Sort<T>::BubbleSort2()
{
	int i, j;
	Status flag = TRUE;
	for (i = 1; i < L->length && flag; i++)
	{
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->data[j]>L->data[j + 1])
			{
				swap(L, j, j + 1);
				flag = TRUE;
			}
		}
	}
}


// 对顺序表L作简单选择排序
template <typename T>
void Sort<T>::SelectSort()
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->data[min]>L->data[j])
				min = j;
		}

		if (i != min)
			swap(L, i, min);
	}
}


// 对顺序表L作直接插入排序
template <typename T>
void Sort<T>::InsertSort()
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->data[i] < L->data[i - 1])
		{
			L->data[0] = L->data[i];//设置哨兵
			for (j = i - 1; L->data[j]>L->data[0]; j--)
				L->data[j + 1] = L->data[j];//记录后移

			L->data[j + 1] = L->data[0];
		}
	}
}


// 对顺序表L作希尔排序
template <typename T>
void Sort<T>::ShellSort()
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;//增量序列
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->data[i]<L->data[i - increment])
			{//
				L->data[0] = L->data[i];
				for (j = i - increment; j>0 && L->data[0]<L->data[j]; j -= increment)
					L->data[j + increment] = L->data[j];//记录后移，查找插入位置

				L->data[j + increment] = L->data[0];//插入
			}
		}
	} while (increment > 1);
}

//
template <typename T>
void Sort<T>::HeapAdjust(int s, int m)
{
	int temp, j;
	temp = L->data[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && L->data[j] < L->data[j + 1])
			++j;

		if (temp >= L->data[j])
			break;

		L->data[s] = L->data[j];
		s = j;
	}
	L->data[s] = temp;//插入
}


// 对顺序表L进行堆排序
template <typename T>
void Sort<T>::HeapSort()
{
	int i;
	for (i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);

	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}


// 对顺序表L作归并排序
template <typename T>
void Sort<T>::MergeSort()
{
	MSort(L->data, L->data, 1, L->length);
}


// 将SR归并排序为TR1
template <typename T>
void Sort<T>::MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAX + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}


// 将有序的SR和SR归并为有序的TR
template <typename T>
void Sort<T>::Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m&&j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}

	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];
	}

	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];
	}
}


// 对顺序表L作快速排序
template <typename T>
void Sort<T>::QuickSort()
{
	QSort(L, 1, L->length);
}




// 对顺序表L中的子序列L->data作快速排序
template <typename T>
void Sort<T>::QSort(int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);//将L->data一分为二

		QSort(L, low, pivot - 1);//对低子表递归排序
		QSort(L, pivot + 1, high);//对高子表递归排序
	}
}


// 交换顺序表L中子表的记录
template <typename T>
int Sort<T>::Partition(int low, int high)
{
	int pivotkey;
	pivotkey = L->data[low];//用子表的第一个记录作枢轴记录
	while (low<high)//从表的两端交替向中间扫描
	{
		while ((low < high) && (L->data[high] >= pivotkey))
			high--;

		swap(L, low, high);//将比枢轴记录小的记录交换到低端

		while ((low < high) && (L->data[low] <= pivotkey))
			low++;

		swap(L, low, high);//将比枢轴记录大的记录交换到高端
	}
	return low;//返回枢轴所在位置
}

ZO_END_NAMESPACE