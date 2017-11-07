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


// ½øÕ»
Status Stack::Push(SqStack& S, ElemType e)
{
	if (S.top == MAX - 1)
	{
		return ERROR;
	}

	S.top++;
	S.data[S.top] = e;

	return OK;
}


// ³öÕ»
Status Stack::Pop(SqStack& S, ElemType& e)
{
	if (S.top == -1)
		return ERROR;

	e = S.data[S.top];
	S.top--;

	return OK;
}

/*----------------------Á½Õ»¹²Ïí¿Õ¼ä½á¹¹------------------------------*/
// ½øÕ»
Status Stack::Push(SqDoubleStack& S, ElemType e, int stackNumber)
{
	if (S.top1 + 1 == S.top2)//Õ»Âú
		return ERROR;

	if (stackNumber == 1)
		S.data[++S.top1] = e;
	else if (stackNumber==2)
		S.data[--S.top2] = e;


	return OK;
}


// ³öÕ»
Status Stack::Pop(SqDoubleStack& S, ElemType& e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S.top1 == -1)//Õ»1¿ÕÕ»
			return ERROR;
		e = S.data[S.top1--];
	}
	else if (stackNumber==2)//
	{
		if (S.top2 == MAX)//Õ»2¿ÕÕ»
			return ERROR;
		e = S.data[S.top2++];
	}
	return OK;
}

/*-------------------------Á´Õ»--------------------------------*/
// ÈëÕ»£¬´ÓÁ´Õ»Í·ÈëÕ»
Status Stack::Push(LNode& S, ElemType e)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = NULL;
	s->data = e;

	s->next = S.next;
	S.next = s;

	return OK;
}


// ³öÕ»£¬´ÓÁ´Õ»Í·³öÕ»
Status Stack::Pop(LNode& S, ElemType& e)
{
	LNode* p;
	if (S.next==NULL)//Õ»¿Õ
		return ERROR;

	e = S.next->data;
	p = S.next;
	S.next = S.next->next;
	free(p);

	return OK;
}


// ÊÇ·ñÎª¿ÕÕ»,¿Õ·µ»ØTRUE
int Stack::StackEmpty(LNode& S)
{
	if (S.next==NULL)
	{
		return 1;
	}

	return 0;
}


// Á´Õ»³õÊ¼»¯
void Stack::InitStack(LNode* S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}
