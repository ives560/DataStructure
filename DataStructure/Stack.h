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

