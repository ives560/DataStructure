#pragma once
#include "Comm.h"

//����������ṹ
typedef struct BiTNode
{
	char data;	//�������
	int bf;		//����ƽ������
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;

//������
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	// �������������ʾ�Ķ�����
	int CreateBiTree(BiTree& T);
	// ǰ�����
	void PreOrder(BiTree T);
	// �������
	void InOrder(BiTree T);
	// �������
	void PostOrder(BiTree T);
	// �������
	void LevelOrder(BiTree T);

	// �ݹ���Ҷ���������T�Ƿ����key
	Status SearchBST(BiTree T, int key, BiTree f, BiTree* p);
	// ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ����key
	Status InsertBST(BiTree* T, int key);
	// �Ӷ�������ɾ���ڵ�p�����ؽ��������������
	Status Delete(BiTree* p);
	// ����������T�д��ڹؼ��ֵ���key��Ԫ��ʱ����ɾ��������Ԫ�ؽ��
	Status DeleteBST(BiTree* T, int key);
	// ����pΪ���Ķ�������������������
	void R_Rotate(BiTree* p);
	// ����pΪ���Ķ�������������������
	void L_Rotate(BiTree* p);
	// ����������ƽ����ת����
	void LeftBalance(BiTree* T);
	// ����������ƽ����ת����
	void RightBalance(BiTree* T);
	// ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽڵ㣬�����һ��
	Status InsertAVL(BiTree* T, int e, Status* taller);

};

