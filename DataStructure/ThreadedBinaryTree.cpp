#include "ThreadedBinaryTree.h"



ThreadedBinaryTree::ThreadedBinaryTree()
{
}


ThreadedBinaryTree::~ThreadedBinaryTree()
{
}

// 线索化
void ThreadedBinaryTree::InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);//递归左子树线索化
		if (!T->lchild)//没有左孩子
		{
			T->LTag = Thread;
			T->lchild = pre;
		}

		if (!pre->rchild)//前驱没有右孩子
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;//保持pre指向T的前驱
		InThreading(T->rchild);//递归右子树线索化
	}
}

// 中序遍历
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
		p->data;//访问左子树为空的节点
		while (p->RTag==Thread&&p->rchild!=T)
		{
			p = p->rchild;
			p->data;//访问后继节点
		}

		p = p->rchild;
	}
}

