#pragma once

#include"Comm.h"

//线性栈
typedef struct
{
	ElemType data[MAX];
	int top;
}SqStack;

//两栈共享空间结构
typedef struct
{
	ElemType data[MAX];
	int top1;
	int top2;
}SqDoubleStack;


//链栈节点
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
	// 进栈
	Status Push(SqStack& S, ElemType e);
	// 出栈
	Status Pop(SqStack& S, ElemType& e);
	Status Push(SqDoubleStack& S, ElemType e, int stackNumber);
	// 出栈
	Status Pop(SqDoubleStack& S, ElemType& e, int stackNumber);
	// 入栈
	Status Push(LNode& S, ElemType e);
	// 出栈
	Status Pop(LNode& S, ElemType& e);
	// 是否为空栈
	int StackEmpty(LNode& S);
	// 链栈初始化
	void InitStack(LNode* S);
};


Stack::Stack()
{
}


Stack::~Stack()
{
}


// 进栈
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


// 出栈
Status Stack::Pop(SqStack& S, ElemType& e)
{
	if (S.top == -1)
		return ERROR;

	e = S.data[S.top];
	S.top--;

	return OK;
}

/*----------------------两栈共享空间结构------------------------------*/
// 进栈
Status Stack::Push(SqDoubleStack& S, ElemType e, int stackNumber)
{
	if (S.top1 + 1 == S.top2)//栈满
		return ERROR;

	if (stackNumber == 1)
		S.data[++S.top1] = e;
	else if (stackNumber == 2)
		S.data[--S.top2] = e;


	return OK;
}


// 出栈
Status Stack::Pop(SqDoubleStack& S, ElemType& e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S.top1 == -1)//栈1空栈
			return ERROR;
		e = S.data[S.top1--];
	}
	else if (stackNumber == 2)//
	{
		if (S.top2 == MAX)//栈2空栈
			return ERROR;
		e = S.data[S.top2++];
	}
	return OK;
}

/*-------------------------链栈--------------------------------*/
// 入栈，从链栈头入栈
Status Stack::Push(LNode& S, ElemType e)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = NULL;
	s->data = e;

	s->next = S.next;
	S.next = s;

	return OK;
}


// 出栈，从链栈头出栈
Status Stack::Pop(LNode& S, ElemType& e)
{
	LNode* p;
	if (S.next == NULL)//栈空
		return ERROR;

	e = S.next->data;
	p = S.next;
	S.next = S.next->next;
	free(p);

	return OK;
}


// 是否为空栈,空返回TRUE
int Stack::StackEmpty(LNode& S)
{
	if (S.next == NULL)
	{
		return 1;
	}

	return 0;
}


// 链栈初始化
void Stack::InitStack(LNode* S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}