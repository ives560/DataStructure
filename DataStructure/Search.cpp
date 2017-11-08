#include "Search.h"


Search::Search()
{
}


Search::~Search()
{
}


// ÕÛ°ë²éÕÒ
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


// ì³²¨ÄÇÆõ²éÕÒ
int Search::Fibonacci_Search(int* a, int n, int key)
{
	return 0;
}
