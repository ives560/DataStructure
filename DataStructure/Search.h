#pragma once

#include"Comm.h"

class Search
{
public:
	Search();
	~Search();
	// Ë³Ğò²éÕÒ
	int Sequential_Search(int* a, int n, int key);
	// ÕÛ°ë²éÕÒ
	int Binary_Search(int* a, int n, int key);
	// ì³²¨ÄÇÆõ²éÕÒ
	int Fibonacci_Search(int* a, int n, int key);
};

