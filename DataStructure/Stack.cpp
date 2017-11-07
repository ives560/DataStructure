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


// ��ջ
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


// ��ջ
Status Stack::Pop(SqStack& S, ElemType& e)
{
	if (S.top == -1)
		return ERROR;

	e = S.data[S.top];
	S.top--;

	return OK;
}

/*----------------------��ջ����ռ�ṹ------------------------------*/
// ��ջ
Status Stack::Push(SqDoubleStack& S, ElemType e, int stackNumber)
{
	if (S.top1 + 1 == S.top2)//ջ��
		return ERROR;

	if (stackNumber == 1)
		S.data[++S.top1] = e;
	else if (stackNumber==2)
		S.data[--S.top2] = e;


	return OK;
}


// ��ջ
Status Stack::Pop(SqDoubleStack& S, ElemType& e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S.top1 == -1)//ջ1��ջ
			return ERROR;
		e = S.data[S.top1--];
	}
	else if (stackNumber==2)//
	{
		if (S.top2 == MAX)//ջ2��ջ
			return ERROR;
		e = S.data[S.top2++];
	}
	return OK;
}

/*-------------------------��ջ--------------------------------*/
// ��ջ������ջͷ��ջ
Status Stack::Push(LNode& S, ElemType e)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = NULL;
	s->data = e;

	s->next = S.next;
	S.next = s;

	return OK;
}


// ��ջ������ջͷ��ջ
Status Stack::Pop(LNode& S, ElemType& e)
{
	LNode* p;
	if (S.next==NULL)//ջ��
		return ERROR;

	e = S.next->data;
	p = S.next;
	S.next = S.next->next;
	free(p);

	return OK;
}


// �Ƿ�Ϊ��ջ,�շ���TRUE
int Stack::StackEmpty(LNode& S)
{
	if (S.next==NULL)
	{
		return 1;
	}

	return 0;
}


// ��ջ��ʼ��
void Stack::InitStack(LNode* S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}
