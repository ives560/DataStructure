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
	// ����
	int enQueue(SqQueue& qu, int x);
	// ����
	int deQueue(SqQueue& qu, int& x);
	void enQueue(LiQueue& lqu, int x);
	// ���ӳ���
	int deQueue(LiQueue& lqu, int& x);
};

