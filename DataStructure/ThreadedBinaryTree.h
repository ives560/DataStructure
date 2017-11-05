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

//����������
class ThreadedBinaryTree
{
public:
	ThreadedBinaryTree();
	~ThreadedBinaryTree();
	// ������
	void InThreading(BiThrTree T);
	// �������
	void InOrder(BiThrTree T);

public:
	BiThrTree pre;//ʼ��ָ��ոշ��ʹ��Ľڵ�

};

