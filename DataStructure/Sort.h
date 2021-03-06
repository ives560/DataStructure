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
	void BubbleSort1();
	// 对顺序表L作改进冒泡算法
	void BubbleSort();
	// 对顺序表L作简单选择排序
	void SelectSort();
	// 对顺序表L作直接插入排序
	void InsertSort();
	// 对顺序表L作希尔排序
	void ShellSort();
	//
	void HeapAdjust(int s, int m);
	// 对顺序表L进行堆排序
	void HeapSort();
	// 对顺序表L作归并排序
	void MergeSort();
	//对顺序表L作归并非递归排序
	void MergeSort2();
	//将SR[]中相邻长度为s的子序列两两归并到TR[]
	void MergePass(int SR[], int TR[], int s, int n);
	//
	void MSort(int SR[], int TR1[], int s, int t);
	// 对顺序表L作快速排序	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// 对顺序表L作快速排序	
	void QuickSort();
	// 对顺序表L中的子序列L->data作快速排序
	void QSort(int low, int high);
	// 快速排序尾递归优化和小数组优化
	void QSort1(int low, int high);
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
				swap(i, j);//交换L->data[i]与L->data[j]的值
			}
		}
	}
}


// 对顺序表L作冒泡排序
template <typename T>
void Sort<T>::BubbleSort1()
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		//一趟排序
		for (j = L->length - 1; j >= i; j--)//j从后往前循环
		{
			if (L->data[j] > L->data[j + 1])//若前者大于后者
			{
				swap(j, j + 1);//交换L->data[j]与L->data[j+1]的值
			}
		}
	}
}

// 对顺序表L作冒泡排序
// 对顺序表L作改进冒泡算法时间复杂度为O(n*n)
template <typename T>
void Sort<T>::BubbleSort()
{
	int i, j;
	Status flag = TRUE;
	for (i = 1; i < L->length && flag; i++)//若flag为true则退出循环
	{
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)//j从后往前循环
		{
			if (L->data[j]>L->data[j + 1])//若前者大于后者
			{
				swap(j, j + 1);//交换L->data[j]与L->data[j+1]的值
				flag = TRUE;//如果有数据交换，则flag为true
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
/*4*/	for (i = 2; i <= L->length; i++)//假设L->data[i-1]已经放好位置
/*5*/	{
/*6*/		if (L->data[i-1] > L->data[i])//前面的数比后面的数L->data[i]大
/*7*/		{
/*8*/			L->data[0] = L->data[i];//设置哨兵,暂存后面较小的数L->data[i]

				//将大数循环后移
/*9*/			for (j = i - 1; L->data[j]>L->data[0]; j--)//前面的数大于L->data[0]
/*10*/				L->data[j + 1] = L->data[j];//前面的记录后移

/*11*/			L->data[j + 1] = L->data[0];//插入暂存较小的数
		}
	}
}


// 对顺序表L作希尔排序
//时间复杂度为O(n(3/2))
//不是稳定的排序算法
template <typename T>
void Sort<T>::ShellSort()
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;//增量序列,increment的计算是关键
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->data[i]<L->data[i - increment])//后数小于前数L->data[i]
			{//
				L->data[0] = L->data[i];//将小数L->data[i]暂存入L->data[0]

				for (j = i - increment; j>0 && L->data[0]<L->data[j]; j -= increment)//交换位置，将大数放后面
					L->data[j + increment] = L->data[j];//记录后移，查找插入位置

				L->data[j + increment] = L->data[0];//插入，将暂存的小数赋值到大数的位置

			}
		}
	} while (increment > 1);
}

//对顺序表L进行堆排序
//调整L->data[s]的关键字,使L->data[s..m]成为一个大顶堆
template <typename T>
void Sort<T>::HeapAdjust(int s, int m)
{
	int temp, j;
	temp = L->data[s];
	for (j = 2 * s; j <= m; j *= 2)//沿关键字较大的孩子结点向下筛选,结点序号是s，左孩子是2s，右孩子是2s+1
	{
		if (j < m && L->data[j] < L->data[j + 1])
			++j;//j为关键字中较大的记录的下标

		if (temp >= L->data[j])
			break;//rc应插入在位置s上

		L->data[s] = L->data[j];
		s = j;
	}
	L->data[s] = temp;//插入
}


// 对顺序表L进行堆排序
//时间复杂度为O(nlogn)
//是一种不稳定的排序方法
template <typename T>
void Sort<T>::HeapSort()
{
	int i;
	for (i = L->length / 2; i > 0; i--)//把L中的r构建成一个大顶堆,0~L->length / 2都是有孩子的结点
		HeapAdjust(i, L->length);

	for (i = L->length; i > 1; i--)
	{
		swap(1, i);//将堆顶记录和当前未经排序子序列的最后一个记录交换
		HeapAdjust(1, i - 1);//将L->data[1..i-1]重新调整为大顶堆
	}
}


// 对顺序表L作归并排序
template <typename T>
void Sort<T>::MergeSort()
{
	MSort(L->data, L->data, 1, L->length);
}


// 将SR[s..t]归并排序为TR1[s..t]
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


// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
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

//对顺序表L作归并非递归排序
template <typename T>
void Sort<T>::MergeSort2()
{
	int* TR = (int*)malloc(L->length*sizeof(int));//申请额外空间
	int k = 1;

	while (k<L->length)
	{
		MergePass(L->data,TR,k,L->length);
		k = 2 * k;//子序列长度加倍

		MergePass(TR,L->data, k, L->length);
		k = 2 * k;//子序列长度加倍
	}
}

//将SR[]中相邻长度为s的子序列两两归并到TR[]
template <typename T>
void Sort<T>::MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;

	while (i<=n-2*s+1)
	{
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);//两两归并
		i = i + 2 * s;
	}

	if (i < n - s + 1)//归并最后两个序列
	{
		Merge(SR, TR, i, i + s - 1, n);
	}
	else//若最后只剩下单个子序列
	{
		for ( j = i; j <=n; j++)
		{

			TR[j] = SR[j];
		}
	}
}


// 对顺序表L作快速排序
//在最优情况下，时间复杂度为O(nlogn)
//在最坏情况下，时间复杂度为O(n*n)
//在平均情况下，时间复杂度为O(nlogn)
//在平均情况下，空间复杂度为O(logn)
template <typename T>
void Sort<T>::QuickSort()
{
	QSort(1, L->length);
}

#define MAX_LENGTH_INSERT_SORT	7

// 对顺序表L中的子序列L->data作快速排序
template <typename T>
void Sort<T>::QSort(int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(low, high);//将L->data一分为二,算出“枢轴”值pivot

		QSort(low, pivot - 1);//对pivot左侧表递归排序
		QSort(pivot + 1, high);//对pivot右侧表递归排序
	}
}

// 快速排序尾递归优化和小数组优化
template <typename T>
void Sort<T>::QSort1(int low, int high)
{
	int pivot;
	if ((high - low)>MAX_LENGTH_INSERT_SORT)//当high-low大于常数时用快速排序
	{
		while (low<high)
		{
			pivot = Partition(low, high);//将L->data一分为二,算出“枢轴”值pivot

			QSort1(low, pivot - 1);//对低子表递归排序
			low = pivot + 1;//尾递归，效果等同QSort(pivot + 1, high);缩减堆栈深度
		}

	}
	else//当high-low小于等于常数时用直接插入排序
	{
		InsertSort();
	}
}


// 交换顺序表L中子表的记录
//左边的值都比“枢轴”小，右边的值都比“枢轴”大
template <typename T>
/*1*/int Sort<T>::Partition(int low, int high)
/**/{
/*3*/	int pivotkey;

		//获取“枢轴”记录
		//添加三数取中优化
		int m = low + (high - low) / 2;

		if (L->data[low] > L->data[high])
			swap(low, high);

		if (L->data[m] > L->data[high])
			swap(m, high);

		if (L->data[m] > L->data[low])
			swap(m, low);
		//结束三数取中优化
		pivotkey = L->data[low];//用子表的第一个记录作“枢轴”记录

		L->data[0] = pivotkey;

/*5*/	while (low<high)//从表的两端交替向中间扫描
		{
/*7*/		while ((low < high) && (L->data[high] >= pivotkey))//查找比“枢轴”小的记录
/*8*/			high--;

/*9*/		//swap(low, high);//将比枢轴记录小的记录交换到低端
			L->data[low] = L->data[high];//采用替换而不是交换的方式进行操作

/*10*/		while ((low < high) && (L->data[low] <= pivotkey))//查找比“枢轴”大的记录
/*11*/			low++;

/*12*/		//swap(low, high);//将比枢轴记录大的记录交换到高端
			L->data[high] = L->data[low];//采用替换而不是交换的方式进行操作
		}

		L->data[low] = L->data[0];//将枢轴值替换回L->data[low]

/*14*/	return low;//返回枢轴所在位置
	}

ZO_END_NAMESPACE