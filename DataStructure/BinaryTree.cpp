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



// 递归查找二叉排序树T是否存在key
//T：要查找的树
//key：要查找的值
//f：T的双亲，初始化为NULL
//p：查找到的节点地址
Status BinaryTree::SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key==T->data)
	{
		*p = T;//查找成功，p指向该数据元素节点
		return TRUE;
	}
	else if (key<T->data)
	{
		return SearchBST(T->lchild, key, T, p);//在左子树继续查找
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);//在右子树继续查找
	}
	return Status();
}


// 当二叉排序树T中不存在关键字等于key的数据元素时插入key
Status BinaryTree::InsertBST(BiTree* T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	return FALSE;
}


// 从二叉树中删除节点p，并重接它的左或右子树
Status BinaryTree::Delete(BiTree* p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}


// 二叉排序树T中存在关键字等于key的元素时，则删除该数据元素结点
Status BinaryTree::DeleteBST(BiTree* T, int key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)//
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}
