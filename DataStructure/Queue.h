#pragma once

#include"Comm.h"

typedef struct
{
	ElemType data[MAX];
	int front;
	int rear;
}SqQueue;

typedef struct QNode
{
	ElemType data;
	QNode *next;
}QNode;

typedef struct
{
	QNode *front;
	QNode *rear;
}LiQueue;

class Queue
{
public:
	Queue();
	~Queue();
	// 进队
	int enQueue(SqQueue& qu, int x);
	// 出对
	int deQueue(SqQueue& qu, int& x);
	void enQueue(LiQueue& lqu, int x);
	// 链队出队
	int deQueue(LiQueue& lqu, int& x);
};

