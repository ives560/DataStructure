#pragma once

#include"Comm.h"

typedef struct
{
	ElemType data[MAX];
	int top;
}SqStack;

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
};

