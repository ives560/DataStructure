#pragma once

#include"Comm.h"

class Search
{
public:
	Search();
	~Search();
	// ˳�����
	int Sequential_Search(int* a, int n, int key);
	// �۰����
	int Binary_Search(int* a, int n, int key);
	// 쳲���������
	int Fibonacci_Search(int* a, int n, int key);
};

