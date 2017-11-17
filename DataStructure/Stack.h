#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

//����ջ
template <typename T>
struct SqStack
{
	T data[MAX];
	int top;
};


//��ջ�ڵ�
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
	// ��ջ
	Status Push(T e);
	// ��ջ
	Status Pop(T& e);

	// ��ջ
	Status Push(LNode& S, T e);
	// ��ջ
	Status Pop(LNode& S, T& e);
	// �Ƿ�Ϊ��ջ
	int StackEmpty(LNode& S);
	// ��ջ��ʼ��
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


// ��ջ
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


// ��ջ
template <typename T>
Status Stack<T>::Pop(T& e)
{
	if (S.top == -1)
		return ERROR;

	e = S.data[S.top];
	S.top--;

	return OK;
}

/*-------------------------��ջ--------------------------------*/
// ��ջ������ջͷ��ջ
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


// ��ջ������ջͷ��ջ
template <typename T>
Status Stack<T>::Pop(LNode& S, ElemType& e)
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
template <typename T>
int Stack<T>::StackEmpty(LNode& S)
{
	if (S.next == NULL)
	{
		return 1;
	}

	return 0;
}


// ��ջ��ʼ��
template <typename T>
void Stack<T>::InitStack(LNode* S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}

ZO_END_NAMESPACE