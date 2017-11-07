#pragma once

#include"Comm.h"

//循环队列的顺序存储结构
typedef struct
{
	ElemType data[MAX];
	int front;
	int rear;
}SqQueue;

//队列的链式存储结构
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

	// 初始化空循环队列
	Status InitQueue(SqQueue& Q);
	// 返回循环队列Q的元素个数
	int QueueLength(SqQueue Q);
	// 进队
	int enQueue(SqQueue& qu, int x);
	// 出对
	int deQueue(SqQueue& qu, int& x);

	// 链队入队
	void enQueue(LiQueue& lqu, int x);
	// 链队出队
	int deQueue(LiQueue& lqu, int& x);

};

