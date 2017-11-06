#pragma once
#include "Comm.h"

typedef struct BiTNode
{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;

//二叉树
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	// 构建二叉链表表示的二叉树
	int CreateBiTree(BiTree& T);
	// 前序遍历
	void PreOrder(BiTree T);
	// 中序遍历
	void InOrder(BiTree T);
	// 后序遍历
	void PostOrder(BiTree T);
	// 层序遍历
	void LevelOrder(BiTree T);

};

