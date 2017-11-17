#pragma once

#include "Comm.h"

typedef struct
{
	 int weight;//Ȩֵ 
	 int parent;//���ڵ����ţ�Ϊ-1���Ǹ��ڵ� 
	 int lchild, rchild;//���Һ��ӽڵ����ţ�Ϊ-1����Ҷ�ӽڵ�  
}HTNode, *HuffmanTree;//�����洢�շ������е����нڵ� 

typedef char** HuffmanCode;//�����洢ÿ��Ҷ�ӽڵ�ĺշ������� 

class Huffman
{
public:
	Huffman();
	~Huffman();
	// �շ��������㷨
	void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n);
	// ��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ-1���������ֱ�����ű�����min1��min2��
	void Select(HuffmanTree HT, int k, int& min1, int& min2);
	// ��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ-1��Ԫ�أ�������Ԫ�ص���ŷ���
	int min(HuffmanTree HT, int k);
};

