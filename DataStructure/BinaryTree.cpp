#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

// �������������ʾ�Ķ�����
int BinaryTree::CreateBiTree(BiTree& T)
{
	char ch;
	scanf(&ch);//��ȡ�����ַ�
	if (ch == ' ')
	{
		T = NULL;
	}
	else
	{
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
			return 0;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

	return 1;
}


// ǰ�����
void BinaryTree::PreOrder(BiTree T)
{
	if (T == NULL)
		return;
	T->data;//���ʽڵ�
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}


// �������
void BinaryTree::InOrder(BiTree T)
{
	if (T == NULL)
		return;
	
	PreOrder(T->lchild);
	T->data;//���ʽڵ�
	PreOrder(T->rchild);
}


// �������
void BinaryTree::PostOrder(BiTree T)
{
	if (T == NULL)
		return;
	
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	T->data;//���ʽڵ�
}


// �������
void BinaryTree::LevelOrder(BiTree T)
{
	int front, rear;
	BiTNode *que[MAX];
	front = rear = 0;
	BiTNode *q;

	if(T != NULL)
	{
		rear = (rear + 1) % MAX;
		que[rear] = T;

		while (front!=rear)
		{
			front = (front + 1) % MAX;
			q = que[front];
			//visit(q);//���ʽڵ�
			if (q->lchild != NULL)//���������գ������������
			{
				rear = (rear + 1) % MAX;
				que[rear] = T;
			}

			if (q->rchild != NULL)//���������գ������������
			{
				rear = (rear + 1) % MAX;
				que[rear] = T;
			}

		}
	}
}

