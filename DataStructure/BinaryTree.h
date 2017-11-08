#pragma once
#include "Comm.h"

//二叉链表结点结构
typedef struct BiTNode
{
	char data;	//结点数据
	int bf;		//结点的平衡因子
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

	// 递归查找二叉排序树T是否存在key
	Status SearchBST(BiTree T, int key, BiTree f, BiTree* p);
	// 当二叉排序树T中不存在关键字等于key的数据元素时插入key
	Status InsertBST(BiTree* T, int key);
	// 从二叉树中删除节点p，并重接它的左或右子树
	Status Delete(BiTree* p);
	// 二叉排序树T中存在关键字等于key的元素时，则删除该数据元素结点
	Status DeleteBST(BiTree* T, int key);
};

