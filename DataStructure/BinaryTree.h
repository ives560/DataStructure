#pragma once
#include "Comm.h"

typedef struct BiTNode
{
	char data;
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

};

