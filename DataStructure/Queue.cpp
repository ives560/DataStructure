#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}


// ����
int Queue::enQueue(SqQueue& qu, int x)
{
	if ((qu.rear + 1)%MAX == qu.front)
		return 0;

	qu.data[qu.rear] = x;
	qu.rear = (qu.rear + 1)%MAX;
	
	return 1;
}


// ����
int Queue::deQueue(SqQueue& qu, int& x)
{
	if (qu.front == qu.rear)
		return 0;

	x = qu.data[qu.front];
	qu.front = (qu.front + 1)%MAX;
	
	return 1;
}

// �������
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


// ���ӳ���
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
