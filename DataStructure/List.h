#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE
//
template <typename T>
struct SqList
{
	T data[MAX];//data[0]����
	int length;//���ȴ�1��ʼ��
};


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


template <typename T>
class List
{

private:
	SqList<T> L;

public:
	List();
	~List();

	int insert( int p, T e);
	// ����˳�����С����Ĳ���˳��
	int LocateElem(T e);
	int listDelete(int p, T& e);
	// ��ȡԪ��
	Status GetElem(int i, T* e);
	// ��ʼ����
	void InitList();


	Status GetElem(LinkList L, int i, ElemType& e);
	// ���������
	Status ListInsert(LinkList &L, int i, ElemType e);
	// ������ɾ���ڵ�
	Status ListDelete(LinkList &L, int i, ElemType& e);
	// ͷ�����봴���������Ա�
	void CreateListHead(LinkList &L, int n);
	void CreateListTail(LinkList *L, int n);
	// �������
	Status ClearList(LinkList &L);
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

template <typename T>
List<T>::List()
{
}

template <typename T>
List<T>::~List()
{
}

// ��ʼ����
template <typename T>
void List<T>::InitList()
{
	L.length = 0;
}

//�ڱ��е�p��λ�ò�����Ԫ��e
template <typename T>
int List<T>::insert(int i, T e)
{
	int k;

	if (L.length == MAX)
		return ERROR;

	if (i<1 || i>L.length + 1)
		return ERROR;

	if (i <= L.length)//��������λ�ò��ڱ�β
	{
		for (k = L.length; k >= i; k--)//����λ��Ԫ�غ���
		{
			L.data[k + 1] = L.data[k];
		}
	}

	L.data[i] = e;//������Ԫ��
	L.length++;

	return OK;
}

//ɾ�����е�p��λ�ã�����e������ֵ
template <typename T>
int List<T>::listDelete(int i, T& e)
{
	int k;

	if (L.length == 0)
		return ERROR;

	if (i<1 || i>L.length)
		return 0;

	e = L.data[i];

	for (k = i; k <= L.length; k++)
	{
		L.data[k] = L.data[k + 1];
	}

	L.length--;

	return OK;
}

//��ȡԪ��
template <typename T>
Status List<T>::GetElem(int i, T* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;

	*e = L.data[i - 1];
	return OK;
}


// ������e��ȵ�Ԫ�أ�����ɹ����ظ�Ԫ�ص�λ��
template <typename T>
int List<T>::LocateElem(T e)
{
	int i;
	for (i = 1; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i;
		}
	}
	return 0;
}

/*****************************************************/
//��ȡ������Ԫ��
template <typename T>
Status List<T>::GetElem(LinkList L, int i, ElemType& e)
{
	int j = 1;
	LNode* p = L.next;//pָ���һ���ڵ㣬�Ͳ���ɾ���ڵ�������

	while (p&&j<i)//���ҵ�i���ڵ�
	{
		p = p->next;
		++j;
	}

	if (!p || j>i)
		return ERROR;

	e = p->data;//ȡ��i��Ԫ������

	return OK;
}


// ���������
//
template <typename T>
Status List<T>::ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	LNode *s;
	int j = 1;


	while (p && j<i)//���ҵ�i���ڵ�ǰ�ڵ�p
	{
		p = p->next;
		++j;
	}

	if (!p || j>i)
		return ERROR;

	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}


// ������ɾ���ڵ�
template <typename T>
Status List<T>::ListDelete(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LNode* q;
	int j = 1;

	while (p->next&&j<i)//���ҵ�i���ڵ�ǰ�ڵ�p
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j>i)
		return ERROR;

	q = p->next;	//i�ڵ�q
	p->next = q->next;//ɾ��i�ڵ�q
	e = q->data;
	free(q);

	return OK;
}

#include <time.h>
// ͷ�����봴���������Ա�
template <typename T>
void List<T>::CreateListHead(LinkList& L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	L = (LinkList)malloc(sizeof(LNode));
	L.next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = rand() % 100 + 1;
		p->next = L.next;
		L.next = p;
	}
}

// β�����봴���������Ա�
template <typename T>
void List<T>::CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(LNode));
	r = *L;

	for (i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}


// �������
template <typename T>
Status List<T>::ClearList(LinkList& L)
{
	LinkList q;
	LNode* p = L.next;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	L.next = NULL;//ͷ�ڵ�ָ����Ϊ��

	return OK;
}

/*----------------------��̬����-----------------------------*/
// ��ʼ����̬����
template <typename T>
void List<T>::InitList(SLinkList space)
{
	int i;
	for (i = 0; i < MAX - 1; i++)
	{
		space[i].cur = i + 1;
	}

	space[MAX - 1].cur = 0;
}


// ����ڵ�
template <typename T>
int List<T>::Malloc_SLL(SLinkList space)
{
	int i = space[0].cur;//�±�Ϊ0��Ԫ��cur���δʹ�õ�����Ԫ�صĵ�һ���ڵ��±�

	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

// �ͷŽڵ�
template <typename T>
void List<T>::Free_SLL(SLinkList space, int k)
{
	space[k].cur = space[0].cur;//�±�Ϊ0��Ԫ��cur���δʹ�õ�����Ԫ�صĵ�һ���ڵ��±�
	space[0].cur = k;
}

// ��ȡ��̬�б���
template <typename T>
int List<T>::ListLength(SLinkList L)
{
	int j = 0;
	int i = L[MAX - 1].cur;//���һ��Ԫ�ص�cur��ŵ�һ������Ԫ�ص��±�

	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}


// ��̬�����������
template <typename T>
Status List<T>::ListInsert(SLinkList L, int i, ElemType e)
{
	int  j, k, l;
	k = MAX - 1;

	if (i < 1 || i>ListLength(L) + 1)
		return ERROR;

	j = Malloc_SLL(L);

	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i + 1; l++)//�ҵ���i��Ԫ��֮ǰ��λ��
			k = L[k].cur;

		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}

	return ERROR;
}


// ɾ����̬����Ԫ��
template <typename T>
Status List<T>::ListDelete(SLinkList L, int i)
{
	int j, k;

	if (i<1 || i>ListLength(L))
		return ERROR;

	k = MAX - 1;

	for (j = 0; j <= i - 1; j++)//�ҵ���i��Ԫ��֮ǰ��λ��
		k = L[k].cur;

	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);

	return OK;
}

ZO_END_NAMESPACE