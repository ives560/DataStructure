#pragma once
//�ַ���ģʽƥ���㷨
//�ο���http://blog.csdn.net/v_july_v/article/details/7041827
//�ο���http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

#include "Comm.h"

class ZoKMP
{
private:
	int next[MAX];

public:
	ZoKMP();
	~ZoKMP();

	void GetNextval(char* p, int next[]);
	int KmpSearch(char* s, char* p);
};

