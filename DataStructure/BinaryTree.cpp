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


// 对以p为根的二叉排序树作右旋处理
void BinaryTree::R_Rotate(BiTree* p)
{
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}


// 对以p为根的二叉排序树作左旋处理
void BinaryTree::L_Rotate(BiTree* p)
{
	BiTree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}

#define LH	+1//左高
#define EH	0//等高
#define RH	-1//右高
// 二叉树作左平衡旋转处理
void BinaryTree::LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;//左子树根结点

	switch (L->bf)//检查T的左子树的平衡度，并作相应平衡处理
	{
		case LH://新结点插入在T的左孩子的左子树上，要作单右旋处理
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH://新结点插入在T的左孩子的右子树上，要作双旋处理
		{
			Lr = L->rchild;
			switch (Lr->bf)
			{
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
			break;
		}

	}
}

// 二叉树作右平衡旋转处理
void BinaryTree::RightBalance(BiTree* T)
{
}


// 平衡的二叉排序树T中不存在和e有相同关键字的节点，则插入一个
Status BinaryTree::InsertAVL(BiTree* T, int e, Status* taller)
{
	if (!*T)//插入新结点，树长高，置taller为true
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data)//树中已存在和e有相同关键字的节点则不再插入
		{
			*taller = FALSE;
			return FALSE;
		}

		if (e < (*T)->data)//继续在T的左子树中进行搜索
		{

			if (!InsertAVL(&(*T)->lchild, e, taller))//递归查找插入位置
				return FALSE;

			//插入完成进行平衡处理
			if (taller)//已插入到左子树中且左子树“长高”
			{
				switch ((*T)->bf)//检查T的平衡度
				{
					case LH://T左高
						LeftBalance(T);
						*taller = FALSE;
						break;
					case EH://T平衡
						(*T)->bf = LH;
						*taller = TRUE;
						break;
					case RH://T右高
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		else//继续在T的右子树中进行搜索
		{

			if (!InsertAVL(&(*T)->rchild, e, taller))//递归查找插入位置
				return FALSE;

			//插入完成进行平衡处理
			if (taller)//已插入到右子树中且右子树“长高”
			{
				switch ((*T)->bf)//检查T的平衡度
				{
				case LH://T左高
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH://T平衡
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				case RH://T右高
					RightBalance(T);
					*taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

