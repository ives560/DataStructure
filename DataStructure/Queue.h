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
	// 队列为空，返回true
	Status QueueEmpty(SqQueue Q);
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

Queue::Queue()
{
}


Queue::~Queue()
{
}

// 初始化空循环队列
Status Queue::InitQueue(SqQueue& Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

// 队列为空，返回true
Status Queue::QueueEmpty(SqQueue Q)
{
	if (Q.front == NULL)
		return TRUE;

	return FALSE;
}


// 返回循环队列Q的元素个数
int Queue::QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX) % MAX;
}


// 循环队列进队
int Queue::enQueue(SqQueue& qu, int x)
{
	if ((qu.rear + 1) % MAX == qu.front)//队满
		return 0;

	qu.data[qu.rear] = x;
	qu.rear = (qu.rear + 1) % MAX;

	return 1;
}


// 循环队列出对
int Queue::deQueue(SqQueue& qu, int& x)
{
	if (qu.front == qu.rear)//队空
		return 0;

	x = qu.data[qu.front];
	qu.front = (qu.front + 1) % MAX;

	return 1;
}

/*--------------------链队----------------------------*/
// 链队入队
void Queue::enQueue(LiQueue& lqu, int x)
{
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (lqu.rear == NULL)
		lqu.front = lqu.rear = p;
	else
	{
		lqu.rear->next = p;
		lqu.rear = p;
	}
}


// 链队出队
int Queue::deQueue(LiQueue& lqu, int& x)
{
	QNode *p;
	if (lqu.rear == NULL)
		return 0;

	p = lqu.front;
	if (lqu.front == lqu.rear)
		lqu.front = lqu.rear = NULL;
	else
		lqu.front = lqu.front->next;
	x = p->data;
	free(p);
	return 1;
}

