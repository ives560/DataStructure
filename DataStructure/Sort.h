#pragma once
#include "Comm.h"
#include "List.h"

ZO_BEGIN_MAMESPACE

//������
template <typename T>
class Sort
{

private:
	SqList<T> *L;

public:
	Sort(SqList<T> *list);
	~Sort();
	// ����L������r���±�Ϊi��j��ֵ
	void swap(int i, int j);
	// ��˳���L����������ð����������棩
	void BubbleSort0();
	// ��˳���L��ð������
	void BubbleSort();
	// ��˳���L���Ľ�ð���㷨
	void BubbleSort2();
	// ��˳���L����ѡ������
	void SelectSort();
	// ��˳���L��ֱ�Ӳ�������
	void InsertSort();
	// ��˳���L��ϣ������
	void ShellSort();
	void HeapAdjust(int s, int m);
	// ��˳���L���ж�����
	void HeapSort();
	// ��˳���L���鲢����
	void MergeSort();
	void MSort(int SR[], int TR1[], int s, int t);
	// ��˳���L����������	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// ��˳���L����������	
	void QuickSort();
	// ��˳���L�е�������L->data����������
	void QSort(int low, int high);
	// ����˳���L���ӱ�ļ�¼
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


// ����L������r���±�Ϊi��j��ֵ
template <typename T>
void Sort<T>::swap(int i, int j)
{
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}


// ��˳���L����������ð����������棩
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
				swap( i, j);//����L->data[i]��L->data[j]��ֵ
			}
		}
	}
}


// ��˳���L��ð������
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


// ��˳���L���Ľ�ð���㷨
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


// ��˳���L����ѡ������
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


// ��˳���L��ֱ�Ӳ�������
template <typename T>
void Sort<T>::InsertSort()
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->data[i] < L->data[i - 1])
		{
			L->data[0] = L->data[i];//�����ڱ�
			for (j = i - 1; L->data[j]>L->data[0]; j--)
				L->data[j + 1] = L->data[j];//��¼����

			L->data[j + 1] = L->data[0];
		}
	}
}


// ��˳���L��ϣ������
template <typename T>
void Sort<T>::ShellSort()
{
	int i, j;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;//��������
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->data[i]<L->data[i - increment])
			{//
				L->data[0] = L->data[i];
				for (j = i - increment; j>0 && L->data[0]<L->data[j]; j -= increment)
					L->data[j + increment] = L->data[j];//��¼���ƣ����Ҳ���λ��

				L->data[j + increment] = L->data[0];//����
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
	L->data[s] = temp;//����
}


// ��˳���L���ж�����
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


// ��˳���L���鲢����
template <typename T>
void Sort<T>::MergeSort()
{
	MSort(L->data, L->data, 1, L->length);
}


// ��SR�鲢����ΪTR1
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


// �������SR��SR�鲢Ϊ�����TR
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


// ��˳���L����������
template <typename T>
void Sort<T>::QuickSort()
{
	QSort(L, 1, L->length);
}




// ��˳���L�е�������L->data����������
template <typename T>
void Sort<T>::QSort(int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);//��L->dataһ��Ϊ��

		QSort(L, low, pivot - 1);//�Ե��ӱ�ݹ�����
		QSort(L, pivot + 1, high);//�Ը��ӱ�ݹ�����
	}
}


// ����˳���L���ӱ�ļ�¼
template <typename T>
int Sort<T>::Partition(int low, int high)
{
	int pivotkey;
	pivotkey = L->data[low];//���ӱ�ĵ�һ����¼�������¼
	while (low<high)//�ӱ�����˽������м�ɨ��
	{
		while ((low < high) && (L->data[high] >= pivotkey))
			high--;

		swap(L, low, high);//���������¼С�ļ�¼�������Ͷ�

		while ((low < high) && (L->data[low] <= pivotkey))
			low++;

		swap(L, low, high);//���������¼��ļ�¼�������߶�
	}
	return low;//������������λ��
}

ZO_END_NAMESPACE