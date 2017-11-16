#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

//ѭ�����е�˳��洢�ṹ
template <typename T>
struct SqQueue
{
	ElemType data[MAX];
	int front;
	int rear;
};

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

template <typename T>
class Queue
{

private:
	SqQueue<T> Q;

public:
	Queue();
	~Queue();

	// ��ʼ����ѭ������
	Status InitQueue();
	// ����Ϊ�գ�����true
	Status QueueEmpty();
	// ����ѭ������Q��Ԫ�ظ���
	int QueueLength();
	// ����
	int enQueue(int x);
	// ����
	int deQueue(int& x);

	// �������
	void enQueue(LiQueue& lqu, int x);
	// ���ӳ���
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

// ��ʼ����ѭ������
template <typename T>
Status Queue<T>::InitQueue()
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

// ����Ϊ�գ�����true
template <typename T>
Status Queue<T>::QueueEmpty()
{
	if (Q.front == NULL)
		return TRUE;

	return FALSE;
}


// ����ѭ������Q��Ԫ�ظ���
template <typename T>
int Queue<T>::QueueLength()
{
	return (Q.rear - Q.front + MAX) % MAX;
}


// ѭ�����н���
template <typename T>
int Queue<T>::enQueue(int x)
{
	if ((Q.rear + 1) % MAX == Q.front)//����
		return 0;

	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAX;

	return 1;
}


// ѭ�����г���
template <typename T>
int Queue<T>::deQueue(int& x)
{
	if (Q.front == Q.rear)//�ӿ�
		return 0;

	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAX;

	return 1;
}

/*--------------------����----------------------------*/
// �������
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


// ���ӳ���
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