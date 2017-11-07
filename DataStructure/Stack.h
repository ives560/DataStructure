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

