#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

//循环队列的顺序存储结构
template <typename T>
struct SqQueue
{
	ElemType data[MAX];
	int front;
	int rear;
};

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

template <typename T>
class Queue
{

private:
	SqQueue<T> Q;

public:
	Queue();
	~Queue();

	// 初始化空循环队列
	Status InitQueue();
	// 队列为空，返回true
	Status QueueEmpty();
	// 返回循环队列Q的元素个数
	int QueueLength();
	// 进队
	int enQueue(int x);
	// 出对
	int deQueue(int& x);

	// 链队入队
	void enQueue(LiQueue& lqu, int x);
	// 链队出队
	int deQueue(LiQueue& lqu, int& x);

};

template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
Queue<T>::~Queue()
{
}

// 初始化空循环队列
template <typename T>
Status Queue<T>::InitQueue()
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

// 队列为空，返回true
template <typename T>
Status Queue<T>::QueueEmpty()
{
	if (Q.front == NULL)
		return TRUE;

	return FALSE;
}


// 返回循环队列Q的元素个数
template <typename T>
int Queue<T>::QueueLength()
{
	return (Q.rear - Q.front + MAX) % MAX;
}


// 循环队列进队
template <typename T>
int Queue<T>::enQueue(int x)
{
	if ((Q.rear + 1) % MAX == Q.front)//队满
		return 0;

	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAX;

	return 1;
}


// 循环队列出对
template <typename T>
int Queue<T>::deQueue(int& x)
{
	if (Q.front == Q.rear)//队空
		return 0;

	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAX;

	return 1;
}

/*--------------------链队----------------------------*/
// 链队入队
template <typename T>
void Queue<T>::enQueue(LiQueue& lqu, int x)
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
template <typename T>
int Queue<T>::deQueue(LiQueue& lqu, int& x)
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

ZO_END_NAMESPACE