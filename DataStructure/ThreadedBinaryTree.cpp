#include "ThreadedBinaryTree.h"



ThreadedBinaryTree::ThreadedBinaryTree()
{
}


ThreadedBinaryTree::~ThreadedBinaryTree()
{
}

// ������
void ThreadedBinaryTree::InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);//�ݹ�������������
		if (!T->lchild)//û������
		{
			T->LTag = Thread;
			T->lchild = pre;
		}

		if (!pre->rchild)//ǰ��û���Һ���
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;//����preָ��T��ǰ��
		InThreading(T->rchild);//�ݹ�������������
	}
}

// �������
void ThreadedBinaryTree::InOrder(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while (p!=T)
	{
		while (p->LTag==Link)
		{
			p = p->lchild;
		}
		p->data;//����������Ϊ�յĽڵ�
		while (p->RTag==Thread&&p->rchild!=T)
		{
			p = p->rchild;
			p->data;//���ʺ�̽ڵ�
		}

		p = p->rchild;
	}
}

