#pragma once

#include "Comm.h"

typedef struct
{
	 int weight;//权值 
	 int parent;//父节点的序号，为-1的是根节点 
	 int lchild, rchild;//左右孩子节点的序号，为-1的是叶子节点  
}HTNode, *HuffmanTree;//用来存储赫夫曼树中的所有节点 

typedef char** HuffmanCode;//用来存储每个叶子节点的赫夫曼编码 

class Huffman
{
public:
	Huffman();
	~Huffman();
	// 赫夫曼编码算法
	void HuffmanCoding(HuffmanTree HT, HuffmanCode& HC, int n);
	// 从HT数组的前k个元素中选出weight最小且parent为-1的两个，分别将其序号保存在min1和min2中
	void select_minium(HuffmanTree HT, int k, int& min1, int& min2);
	// 从HT数组的前k个元素中选出weight最小且parent为-1的元素，并将该元素的序号返回
	int min(HuffmanTree HT, int k);
	// 根据给定的n个权值构造一棵赫夫曼树,wet中存放n个权值
	HuffmanTree create_HuffmanTree(int* wet, int n);
};

