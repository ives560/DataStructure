#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

// 构建二叉链表表示的二叉树
int BinaryTree::CreateBiTree(BiTree& T)
{
	char ch;
	scanf(&ch);//获取输入字符
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


// 前序遍历
void BinaryTree::PreOrder(BiTree T)
{
	if (T == NULL)
		return;
	T->data;//访问节点
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}


// 中序遍历
void BinaryTree::InOrder(BiTree T)
{
	if (T == NULL)
		return;
	
	PreOrder(T->lchild);
	T->data;//访问节点
	PreOrder(T->rchild);
}


// 后序遍历
void BinaryTree::PostOrder(BiTree T)
{
	if (T == NULL)
		return;
	
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	T->data;//访问节点
}


// 层序遍历
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
			//visit(q);//访问节点
			if (q->lchild != NULL)//左子树不空，则左子树入队
			{
				rear = (rear + 1) % MAX;
				que[rear] = T;
			}

			if (q->rchild != NULL)//右子树不空，则左子树入队
			{
				rear = (rear + 1) % MAX;
				que[rear] = T;
			}

		}
	}
}

