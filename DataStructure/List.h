#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE
//
template <typename T>
struct SqList
{
	T data[MAX];//data[0]不用
	int length;//长度从1开始算
};


//链表
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//静态链表
typedef struct
{
	ElemType data;
	int cur;
}Component,SLinkList[MAX];

//双向链表
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
	// 查找顺序表有小到大的插入顺序
	int LocateElem(T e);
	int listDelete(int p, T& e);
	// 获取元素
	Status GetElem(int i, T* e);
	// 初始化表
	void InitList();


	Status GetElem(LinkList L, int i, ElemType& e);
	// 单链表插入
	Status ListInsert(LinkList &L, int i, ElemType e);
	// 单链表删除节点
	Status ListDelete(LinkList &L, int i, ElemType& e);
	// 头部插入创建单链线性表
	void CreateListHead(LinkList &L, int n);
	void CreateListTail(LinkList *L, int n);
	// 清空链表
	Status ClearList(LinkList &L);
	// 初始化静态链表
	void InitList(SLinkList space);
	// 分配节点
	int Malloc_SLL(SLinkList space);
	// 静态链表插入数据
	Status ListInsert(SLinkList L, int i, ElemType e);
	// 获取静态列表长度
	int ListLength(SLinkList L);
	// 释放节点
	void Free_SLL(SLinkList space, int k);
	// 删除静态链表元素
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

// 初始化表
template <typename T>
void List<T>::InitList()
{
	L.length = 0;
}

//在表中第p个位置插入新元素e
template <typename T>
int List<T>::insert(int i, T e)
{
	int k;

	if (L.length == MAX)
		return ERROR;

	if (i<1 || i>L.length + 1)
		return ERROR;

	if (i <= L.length)//插入数据位置不在表尾
	{
		for (k = L.length; k >= i; k--)//插入位置元素后移
		{
			L.data[k + 1] = L.data[k];
		}
	}

	L.data[i] = e;//插入新元素
	L.length++;

	return OK;
}

//删除表中第p个位置，并用e返回其值
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

//获取元素
template <typename T>
Status List<T>::GetElem(int i, T* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;

	*e = L.data[i - 1];
	return OK;
}


// 查找与e相等的元素，如果成功返回该元素的位置
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
//获取单链表元素
template <typename T>
Status List<T>::GetElem(LinkList L, int i, ElemType& e)
{
	int j = 1;
	LNode* p = L.next;//p指向第一个节点，和插入删除节点有区别

	while (p&&j<i)//查找第i个节点
	{
		p = p->next;
		++j;
	}

	if (!p || j>i)
		return ERROR;

	e = p->data;//取第i个元素数据

	return OK;
}


// 单链表插入
//
template <typename T>
Status List<T>::ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	LNode *s;
	int j = 1;


	while (p && j<i)//查找第i个节点前节点p
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


// 单链表删除节点
template <typename T>
Status List<T>::ListDelete(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	LNode* q;
	int j = 1;

	while (p->next&&j<i)//查找第i个节点前节点p
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j>i)
		return ERROR;

	q = p->next;	//i节点q
	p->next = q->next;//删除i节点q
	e = q->data;
	free(q);

	return OK;
}

#include <time.h>
// 头部插入创建单链线性表
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

// 尾部插入创建单链线性表
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


// 清空链表
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

	L.next = NULL;//头节点指针域为空

	return OK;
}

/*----------------------静态链表-----------------------------*/
// 初始化静态链表
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


// 分配节点
template <typename T>
int List<T>::Malloc_SLL(SLinkList space)
{
	int i = space[0].cur;//下标为0的元素cur存放未使用的数组元素的第一个节点下标

	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

// 释放节点
template <typename T>
void List<T>::Free_SLL(SLinkList space, int k)
{
	space[k].cur = space[0].cur;//下标为0的元素cur存放未使用的数组元素的第一个节点下标
	space[0].cur = k;
}

// 获取静态列表长度
template <typename T>
int List<T>::ListLength(SLinkList L)
{
	int j = 0;
	int i = L[MAX - 1].cur;//最后一个元素的cur存放第一个插入元素的下标

	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}


// 静态链表插入数据
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
		for (l = 1; l <= i + 1; l++)//找到第i个元素之前的位置
			k = L[k].cur;

		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}

	return ERROR;
}


// 删除静态链表元素
template <typename T>
Status List<T>::ListDelete(SLinkList L, int i)
{
	int j, k;

	if (i<1 || i>ListLength(L))
		return ERROR;

	k = MAX - 1;

	for (j = 0; j <= i - 1; j++)//找到第i个元素之前的位置
		k = L[k].cur;

	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);

	return OK;
}

ZO_END_NAMESPACE