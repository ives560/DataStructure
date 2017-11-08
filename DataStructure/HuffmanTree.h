#pragma once

typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode;

typedef char** HuffmanCode;

class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();
};

