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

	// ��˳���L���Ľ�ð���㷨
	void BubbleSort();
	// ��˳���L����ѡ������
	void SelectSort();
	// ��˳���L��ֱ�Ӳ�������
	void InsertSort();
	// ��˳���L��ֱ�Ӳ�������
	void InsertSort(int low,int high);
	// ��˳���L��ϣ������
	void ShellSort();
	//
	void HeapAdjust(int s, int m);
	// ��˳���L���ж�����
	void HeapSort();
	// ��˳���L���鲢����
	void MergeSort();
	//
	void MSort(int SR[], int TR1[], int s, int t);
	// ��˳���L����������	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// ��˳���L����������	
	void QuickSort();
	// ��˳���L�е�������L->data����������
	// ��������β�ݹ��Ż���С�����Ż�
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

// ��˳���L��ð������
//�������ʱ�临�Ӷ�ΪO(n)
// ��˳���L���Ľ�ð���㷨ʱ�临�Ӷ�ΪO(n*n)
template <typename T>
void Sort<T>::BubbleSort()
{
	int i, j;
	Status flag = TRUE;
	for (i = 1; i < L->length && flag; i++)//��flagΪtrue���˳�ѭ��
	{
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)//j�Ӻ���ǰѭ��
		{
			if (L->data[j]>L->data[j + 1])//��ǰ�ߴ��ں���
			{
				swap(j, j + 1);//����L->data[j]��L->data[j+1]��ֵ
				flag = TRUE;//��������ݽ�������flagΪtrue
			}
		}
	}
}


// ��˳���L����ѡ������
//���������һ��
//ʱ�临�Ӷ�ΪO(n*n)
//����������ð������
template <typename T>
void Sort<T>::SelectSort()
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;//����ǰ�±궨��Ϊ��Сֵ�±�
		for (j = i + 1; j <= L->length; j++)//ѭ��֮�������
		{
			if (L->data[min]>L->data[j])//�����С�ڵ�ǰ��Сֵ�Ĺؼ���
				min = j;//���˹ؼ��ֵ��±긳ֵ��min
		}

		if (i != min)//��min������i��˵���ҵ���Сֵ������
			swap(i, min);
	}
}


// ��˳���L��ֱ�Ӳ�������
//������ʱ�临�Ӷ�ΪO(n)
//ʱ�临�Ӷ�ΪO(n*n)
//���ܱ�ð�ݺͼ�ѡ�������һЩ
template <typename T>
void Sort<T>::InsertSort()
{
	int i, j;
/*4*/	for (i = 2; i <= L->length; i++)//����L->data[i-1]�Ѿ��ź�λ��
/*5*/	{
/*6*/		if (L->data[i-1] > L->data[i])//ǰ������Ⱥ������L->data[i]��
/*7*/		{
/*8*/			L->data[0] = L->data[i];//�����ڱ�,�ݴ�����С����L->data[i]

				//������ѭ������
/*9*/			for (j = i - 1; L->data[j]>L->data[0]; j--)//ǰ���������L->data[0]
/*10*/				L->data[j + 1] = L->data[j];//ǰ��ļ�¼����

/*11*/			L->data[j + 1] = L->data[0];//�����ݴ��С����
		}
	}
}

// ��˳���L��ֱ�Ӳ�������
template <typename T>
void Sort<T>::InsertSort(int low,int high)
{
	int i, j;
	for (i = low+1; i <= high; i++)//����L->data[i-1]�Ѿ��ź�λ��
	{
		if (L->data[i - 1] > L->data[i])//ǰ������Ⱥ������L->data[i]��
		{
			L->data[0] = L->data[i];//�����ڱ�,�ݴ�����С����L->data[i]

			//������ѭ������
			for (j = i - 1; L->data[j]>L->data[0]; j--)//ǰ���������L->data[0]
				L->data[j + 1] = L->data[j];//ǰ��ļ�¼����

			L->data[j + 1] = L->data[0];//�����ݴ��С����
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
		swap(1, i);
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
//����������£�ʱ�临�Ӷ�ΪO(nlogn)
//�������£�ʱ�临�Ӷ�ΪO(n*n)
//��ƽ������£�ʱ�临�Ӷ�ΪO(nlogn)
//��ƽ������£��ռ临�Ӷ�ΪO(logn)
template <typename T>
void Sort<T>::QuickSort()
{
	QSort(1, L->length);
}

#define MAX_LENGTH_INSERT_SORT	7


// ��������β�ݹ��Ż���С�����Ż�
template <typename T>
void Sort<T>::QSort(int low, int high)
{
	int pivot;
	if ((high - low)>MAX_LENGTH_INSERT_SORT)//��high-low���ڳ���ʱ�ÿ�������
	{
		while (low<high)
		{
			pivot = Partition(low, high);//��L->dataһ��Ϊ��,��������ᡱֵpivot

			QSort(low, pivot - 1);//�Ե��ӱ�ݹ�����
			low = pivot + 1;//β�ݹ飬Ч����ͬQSort(pivot + 1, high);������ջ���
		}

	}
	else//��high-lowС�ڵ��ڳ���ʱ��ֱ�Ӳ�������
	{
		InsertSort(low,high);
	}
}


// ����˳���L���ӱ�ļ�¼
//��ߵ�ֵ���ȡ����ᡱС���ұߵ�ֵ���ȡ����ᡱ��
template <typename T>
/*1*/int Sort<T>::Partition(int low, int high)
/**/{
/*3*/	int pivotkey;

		//��ȡ�����ᡱ��¼
		//�������ȡ���Ż�
		int m = low + (high - low) / 2;

		if (L->data[low] > L->data[high])
			swap(low, high);

		if (L->data[m] > L->data[high])
			swap(m, high);

		if (L->data[m] > L->data[low])
			swap(m, low);
		//��������ȡ���Ż�
		pivotkey = L->data[low];//���ӱ�ĵ�һ����¼�������ᡱ��¼

		L->data[0] = pivotkey;

/*5*/	while (low<high)//�ӱ�����˽������м�ɨ��
		{
/*7*/		while ((low < high) && (L->data[high] >= pivotkey))//���ұȡ����ᡱС�ļ�¼
/*8*/			high--;

/*9*/		//swap(low, high);//���������¼С�ļ�¼�������Ͷ�
			L->data[low] = L->data[high];//�����滻�����ǽ����ķ�ʽ���в���

/*10*/		while ((low < high) && (L->data[low] <= pivotkey))//���ұȡ����ᡱ��ļ�¼
/*11*/			low++;

/*12*/		//swap(low, high);//���������¼��ļ�¼�������߶�
			L->data[high] = L->data[low];//�����滻�����ǽ����ķ�ʽ���в���
		}

		L->data[low] = L->data[0];//������ֵ�滻��L->data[low]

/*14*/	return low;//������������λ��
	}

ZO_END_NAMESPACE