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


// ����pΪ���Ķ�������������������
void BinaryTree::R_Rotate(BiTree* p)
{
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
}


// ����pΪ���Ķ�������������������
void BinaryTree::L_Rotate(BiTree* p)
{
	BiTree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = (*p);
	*p = R;
}

#define LH	+1//���
#define EH	0//�ȸ�
#define RH	-1//�Ҹ�
// ����������ƽ����ת����
void BinaryTree::LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;//�����������

	switch (L->bf)//���T����������ƽ��ȣ�������Ӧƽ�⴦��
	{
		case LH://�½�������T�����ӵ��������ϣ�Ҫ������������
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH://�½�������T�����ӵ��������ϣ�Ҫ��˫������
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

// ����������ƽ����ת����
void BinaryTree::RightBalance(BiTree* T)
{
}


// ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽڵ㣬�����һ��
Status BinaryTree::InsertAVL(BiTree* T, int e, Status* taller)
{
	if (!*T)//�����½�㣬�����ߣ���tallerΪtrue
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data)//�����Ѵ��ں�e����ͬ�ؼ��ֵĽڵ����ٲ���
		{
			*taller = FALSE;
			return FALSE;
		}

		if (e < (*T)->data)//������T���������н�������
		{

			if (!InsertAVL(&(*T)->lchild, e, taller))//�ݹ���Ҳ���λ��
				return FALSE;

			//������ɽ���ƽ�⴦��
			if (taller)//�Ѳ��뵽���������������������ߡ�
			{
				switch ((*T)->bf)//���T��ƽ���
				{
					case LH://T���
						LeftBalance(T);
						*taller = FALSE;
						break;
					case EH://Tƽ��
						(*T)->bf = LH;
						*taller = TRUE;
						break;
					case RH://T�Ҹ�
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		else//������T���������н�������
		{

			if (!InsertAVL(&(*T)->rchild, e, taller))//�ݹ���Ҳ���λ��
				return FALSE;

			//������ɽ���ƽ�⴦��
			if (taller)//�Ѳ��뵽���������������������ߡ�
			{
				switch ((*T)->bf)//���T��ƽ���
				{
				case LH://T���
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH://Tƽ��
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				case RH://T�Ҹ�
					RightBalance(T);
					*taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

