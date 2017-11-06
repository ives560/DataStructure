#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
}

void sumsort(char exp[],int n)
{
	char stack[MAX];
	int top = -1;

	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '(')
		{
			stack[top] = exp[i];
			top++;
		}	

		if (exp[i] == ')')
		{
			if (top == -1)
				return;
			else
				top--;
		}

	}

	if (top != -1)
		return;
}
