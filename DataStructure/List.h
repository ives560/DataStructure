#pragma once

#include"Comm.h"

//
typedef struct
{
	ElemType data[MAX];
	int length;
}SqList;

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



class List
{
public:
	List();
	~List();

	SqList list;

	int insert(SqList &L, int p, ElemType e);
	// 查找顺序表有小到大的插入顺序
	int LocateElem(SqList L, ElemType e);
	int listDelete(SqList& L, int p, ElemType& e);
	// 获取元素
	Status GetElem(SqList L, int i, ElemType* e);
	// 初始化表
	void InitList(SqList& L);


	Status GetElem(LinkList L, int i, ElemType& e);
	// 单链表插入
	Status ListInsert(LinkList& L, int i, ElemType e);
	// 单链表删除节点
	Status ListDelete(LinkList& L, int i, ElemType& e);
	// 头部插入创建单链线性表
	void CreateListHead(LinkList& L, int n);
	void CreateListTail(LinkList* L, int n);
	// 清空链表
	Status ClearList(LinkList& L);
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

