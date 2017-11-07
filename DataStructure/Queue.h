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

