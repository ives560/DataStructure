#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

//线性栈
template <typename T>
struct SqStack
{
	T data[MAX];
	int top;
};


//链栈节点
typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode;

template <typename T>
class Stack
{

private:
	SqStack S;

public:
	Stack();
	~Stack();
	// 进栈
	Status Push(T e);
	// 出栈
	Status Pop(T& e);

	// 入栈
	Status Push(LNode& S, T e);
	// 出栈
	Status Pop(LNode& S, T& e);
	// 是否为空栈
	int StackEmpty(LNode& S);
	// 链栈初始化
	void InitStack(LNode* S);
};

template <typename T>
Stack<T>::Stack()
{
	S.top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
}


// 进栈
template <typename T>
Status Stack<T>::Push(T e)
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
template <typename T>
Status Stack<T>::Pop(T& e)
{
	if (S.top == -1)
		return ERROR;

	e = S.data[S.top];
	S.top--;

	return OK;
}

/*-------------------------链栈--------------------------------*/
// 入栈，从链栈头入栈
template <typename T>
Status Stack<T>::Push(LNode& S, ElemType e)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = NULL;
	s->data = e;

	s->next = S.next;
	S.next = s;

	return OK;
}


// 出栈，从链栈头出栈
template <typename T>
Status Stack<T>::Pop(LNode& S, ElemType& e)
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
template <typename T>
int Stack<T>::StackEmpty(LNode& S)
{
	if (S.next == NULL)
	{
		return 1;
	}

	return 0;
}


// 链栈初始化
template <typename T>
void Stack<T>::InitStack(LNode* S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}

ZO_END_NAMESPACE