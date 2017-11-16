#pragma once

#include"Comm.h"

//����ջ
typedef struct
{
	ElemType data[MAX];
	int top;
}SqStack;

//��ջ����ռ�ṹ
typedef struct
{
	ElemType data[MAX];
	int top1;
	int top2;
}SqDoubleStack;


//��ջ�ڵ�
typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode;

class Stack
{
public:
	Stack();
	~Stack();
	// ��ջ
	Status Push(SqStack& S, ElemType e);
	// ��ջ
	Status Pop(SqStack& S, ElemType& e);
	Status Push(SqDoubleStack& S, ElemType e, int stackNumber);
	// ��ջ
	Status Pop(SqDoubleStack& S, ElemType& e, int stackNumber);
	// ��ջ
	Status Push(LNode& S, ElemType e);
	// ��ջ
	Status Pop(LNode& S, ElemType& e);
	// �Ƿ�Ϊ��ջ
	int StackEmpty(LNode& S);
	// ��ջ��ʼ��
	void InitStack(LNode* S);
};


Stack::Stack()
{
}


Stack::~Stack()
{
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
	else if (stackNumber == 2)
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
	else if (stackNumber == 2)//
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
	if (S.next == NULL)//ջ��
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
	if (S.next == NULL)
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