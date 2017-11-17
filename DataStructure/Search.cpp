#include "Search.h"


Search::Search()
{
}


Search::~Search()
{
}


// À≥–Ú≤È’“
int Search::Sequential_Search(int* a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i]!=key)
	{
		i--;
	}
	return i;
}


// ’€∞Î≤È’“
int Search::Binary_Search(int* a, int n, int key)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high = mid - 1;
		else if (key>a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}


// Ï≥≤®ƒ«∆ı≤È’“
int Search::Fibonacci_Search(int* a, int n, int key)
{

	int F[MAX];
	//ÃÌº”≥ı ºªØF

	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;

	while (n>F[k]-1)
	{
		k++;
	}

	for (i = n; i < F[k] - 1; i++)
		a[i] = a[n];

	while (low<=high)
	{
		mid = low + F[k - 1] - 1;

		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key>a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;
			else
				return n;
		}
	}
	return 0;
}
