#pragma once

#include"Comm.h"

//
typedef struct
{
	ElemType data[MAX];
	int length;
}SqList;

//����
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//��̬����
typedef struct
{
	ElemType data;
	int cur;
}Component,SLinkList[MAX];

//˫������
typedef struct DLNode
{
	ElemType data;
	struct DLNode *prior;
	struct DLNode *next;
}DLNode;



class List
{
public:
	List();
	~List();

	SqList list;

	int insert(SqList &L, int p, ElemType e);
	// ����˳�����С����Ĳ���˳��
	int LocateElem(SqList L, ElemType e);
	int listDelete(SqList& L, int p, ElemType& e);
	// ��ȡԪ��
	Status GetElem(SqList L, int i, ElemType* e);
	// ��ʼ����
	void InitList(SqList& L);


	Status GetElem(LinkList L, int i, ElemType& e);
	// ���������
	Status ListInsert(LinkList& L, int i, ElemType e);
	// ������ɾ���ڵ�
	Status ListDelete(LinkList& L, int i, ElemType& e);
	// ͷ�����봴���������Ա�
	void CreateListHead(LinkList& L, int n);
	void CreateListTail(LinkList* L, int n);
	// �������
	Status ClearList(LinkList& L);
	// ��ʼ����̬����
	void InitList(SLinkList space);
	// ����ڵ�
	int Malloc_SLL(SLinkList space);
	// ��̬�����������
	Status ListInsert(SLinkList L, int i, ElemType e);
	// ��ȡ��̬�б���
	int ListLength(SLinkList L);
	// �ͷŽڵ�
	void Free_SLL(SLinkList space, int k);
	// ɾ����̬����Ԫ��
	Status ListDelete(SLinkList L, int i);
};

