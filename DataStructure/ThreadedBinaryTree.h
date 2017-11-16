#pragma once

#include "Comm.h"

//����������
class ThreadedBinaryTree
{

private:
	typedef enum PointerTag{ Link, Thread };

	typedef struct BiThrNode
	{
		ElemType data;
		BiThrNode *lchild;
		BiThrNode *rchild;
		PointerTag LTag;
		PointerTag RTag;
	}BiThrNode, *BiThrTree;

public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	// ������
	void InThreading(BiThrTree T);
	// �������
	void InOrder(BiThrTree T);

public:
	BiThrTree pre;//ʼ��ָ��ոշ��ʹ��Ľڵ�

};

