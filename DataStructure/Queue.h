#pragma once

#include"Comm.h"

//ѭ�����е�˳��洢�ṹ
typedef struct
{
	ElemType data[MAX];
	int front;
	int rear;
}SqQueue;

//���е���ʽ�洢�ṹ
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

	// ��ʼ����ѭ������
	Status InitQueue(SqQueue& Q);
	// ����Ϊ�գ�����true
	Status QueueEmpty(SqQueue Q);
	// ����ѭ������Q��Ԫ�ظ���
	int QueueLength(SqQueue Q);
	// ����
	int enQueue(SqQueue& qu, int x);
	// ����
	int deQueue(SqQueue& qu, int& x);

	// �������
	void enQueue(LiQueue& lqu, int x);
	// ���ӳ���
	int deQueue(LiQueue& lqu, int& x);

};

Queue::Queue()
{
}


Queue::~Queue()
{
}

// ��ʼ����ѭ������
Status Queue::InitQueue(SqQueue& Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

// ����Ϊ�գ�����true
Status Queue::QueueEmpty(SqQueue Q)
{
	if (Q.front == NULL)
		return TRUE;

	return FALSE;
}


// ����ѭ������Q��Ԫ�ظ���
int Queue::QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX) % MAX;
}


// ѭ�����н���
int Queue::enQueue(SqQueue& qu, int x)
{
	if ((qu.rear + 1) % MAX == qu.front)//����
		return 0;

	qu.data[qu.rear] = x;
	qu.rear = (qu.rear + 1) % MAX;

	return 1;
}


// ѭ�����г���
int Queue::deQueue(SqQueue& qu, int& x)
{
	if (qu.front == qu.rear)//�ӿ�
		return 0;

	x = qu.data[qu.front];
	qu.front = (qu.front + 1) % MAX;

	return 1;
}

/*--------------------����----------------------------*/
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

