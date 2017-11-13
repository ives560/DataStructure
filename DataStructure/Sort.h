#pragma once
#include "Comm.h"
#include "List.h"

class Sort
{
public:
	Sort();
	~Sort();
	// ����L������r���±�Ϊi��j��ֵ
	void swap(SqList* L, int i, int j);
	// ��˳���L����������ð����������棩
	void BubbleSort0(SqList* L);
	// ��˳���L��ð������
	void BubbleSort(SqList* L);
	// ��˳���L���Ľ�ð���㷨
	void BubbleSort2(SqList* L);
	// ��˳���L����ѡ������
	void SelectSort(SqList* L);
	// ��˳���L��ֱ�Ӳ�������
	void InsertSort(SqList* L);
	// ��˳���L��ϣ������
	void ShellSort(SqList* L);
	void HeapAdjust(SqList* L, int s, int m);
	// ��˳���L���ж�����
	void HeapSort(SqList* L);
	// ��˳���L���鲢����
	void MergeSort(SqList* L);
	void MSort(int SR[], int TR1[], int s, int t);
	// ��˳���L����������	
	void Merge(int SR[], int TR[], int i, int m, int n);
	// ��˳���L����������	
	void QuickSort(SqList* L);
	// ��˳���L�е�������L->data����������
	void QSort(SqList* L, int low, int high);
	// ����˳���L���ӱ�ļ�¼
	int Partition(SqList* L, int low, int high);
};

