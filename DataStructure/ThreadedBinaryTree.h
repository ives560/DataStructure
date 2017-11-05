#pragma once

typedef enum PointerTag{Link,Thread};

typedef struct BiThrNode
{
	char data;
	BiThrNode *lchild;
	BiThrNode *rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

//线索二叉树
class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	// 线索化
	void InThreading(BiThrTree T);
	// 中序遍历
	void InOrder(BiThrTree T);

public:
	BiThrTree pre;//始终指向刚刚访问过的节点

};

