#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}

// ��ʼ����
void List::InitList(SqList& L)
{
	L.length = 0;
}

//�ڱ��е�p��λ�ò�����Ԫ��e
int List::insert(SqList &L, int i, ElemType e)
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
int List::listDelete(SqList& L, int i, ElemType& e)
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
Status List::GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;

	*e = L.data[i - 1];
	return OK;
}


// ������e��ȵ�Ԫ�أ�����ɹ����ظ�Ԫ�ص�λ��
int List::LocateElem(SqList L, ElemType e)
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
Status List::GetElem(LinkList L, int i, ElemType& e)
{
	int j = 1;
	LNode* p = L->next;//pָ���һ���ڵ㣬�Ͳ���ɾ���ڵ�������
	
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
Status List::ListInsert(LinkList& L, int i, ElemType e)
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
Status List::ListDelete(LinkList& L, int i, ElemType& e)
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
void List::CreateListHead(LinkList& L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = rand() % 100 + 1;
		p->next = L->next;
		L->next = p;
	}
}

// β�����봴���������Ա�
void List::CreateListTail(LinkList* L, int n)
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
Status List::ClearList(LinkList& L)
{
	LinkList q;
	LNode* p = L->next;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	L->next = NULL;//ͷ�ڵ�ָ����Ϊ��

	return OK;
}

/*----------------------��̬����-----------------------------*/
// ��ʼ����̬����
void List::InitList(SLinkList space)
{
	int i;
	for (i = 0; i < MAX-1; i++)
	{
		space[i].cur = i + 1;
	}

	space[MAX - 1].cur = 0;
}


// ����ڵ�
int List::Malloc_SLL(SLinkList space)
{
	int i = space[0].cur;//�±�Ϊ0��Ԫ��cur���δʹ�õ�����Ԫ�صĵ�һ���ڵ��±�

	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

// �ͷŽڵ�
void List::Free_SLL(SLinkList space,int k)
{
	space[k].cur = space[0].cur;//�±�Ϊ0��Ԫ��cur���δʹ�õ�����Ԫ�صĵ�һ���ڵ��±�
	space[0].cur = k;
}

// ��ȡ��̬�б���
int List::ListLength(SLinkList L)
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
Status List::ListInsert(SLinkList L, int i, ElemType e)
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
Status List::ListDelete(SLinkList L, int i)
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
