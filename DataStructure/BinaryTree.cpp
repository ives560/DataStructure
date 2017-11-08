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



// �ݹ���Ҷ���������T�Ƿ����key
//T��Ҫ���ҵ���
//key��Ҫ���ҵ�ֵ
//f��T��˫�ף���ʼ��ΪNULL
//p�����ҵ��Ľڵ��ַ
Status BinaryTree::SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key==T->data)
	{
		*p = T;//���ҳɹ���pָ�������Ԫ�ؽڵ�
		return TRUE;
	}
	else if (key<T->data)
	{
		return SearchBST(T->lchild, key, T, p);//����������������
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);//����������������
	}
	return Status();
}


// ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ����key
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


// �Ӷ�������ɾ���ڵ�p�����ؽ��������������
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


// ����������T�д��ڹؼ��ֵ���key��Ԫ��ʱ����ɾ��������Ԫ�ؽ��
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
