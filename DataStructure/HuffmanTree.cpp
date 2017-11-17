#include "HuffmanTree.h"


Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}


// �շ��������㷨
//�շ����������������ԣ�
//����ͬһ��Ȩֵ�����ܵõ��ĺշ�������һ����Ψһ�ġ�
//�շ������������������Ի�������Ϊ�Ⲣ��Ӱ�����Ĵ�Ȩ·�����ȡ�
//��Ȩֵ�Ľڵ㶼��Ҷ�ӽڵ㣬����Ȩֵ�Ľڵ㶼��ĳ���Ӷ������ĸ��ڵ㡣
//ȨֵԽ��Ľڵ�Խ�����շ������ĸ��ڵ㣬ȨֵԽС�Ľڵ�ԽԶ��շ������ĸ��ڵ㡣
//�շ�������ֻ��Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ㣬û�ж�Ϊ1�Ľڵ㡣
//һ����n��Ҷ�ӽڵ�ĺշ���������2n - 1���ڵ㡣
//�ο���http://blog.csdn.net/ns_code/article/details/19174553
//HT:����շ�����
//HC:n���ַ��ĺշ�������
//w:n���ַ���Ȩֵ����>0��
//n:�ַ�����
void Huffman::HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n)
{
	if (n <= 1)
		return;

	int total = 2 * n - 1;//һ����n��Ҷ�ӽڵ�ĺշ���������2n-1���ڵ�  
	int i;
	HuffmanTree p;

	HT = (HuffmanTree)malloc((total + 1)*sizeof(HTNode));

	//HT[0],HT[1]...HT[n-1]�д����Ҫ�����n��Ҷ�ӽڵ�
	for (p = HT,i = 1; i <= n; ++i, ++p, ++w)
	{
		*p = {*w,0,0,0};
	}

	//HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ� 
	for (; i <= total; ++i, ++p)
	{
		*p = {0,0,0,0};
	}

	//ÿһ�ֱȽϺ�ѡ���min1��min2����һ�ζ�����,��󹹳�һ�úշ�����
	for (i = n + 1; i <= total; ++i)//���շ�����
	{
		int min1, min2;//��������ÿһ��ѡ��������weight��С��parentΪ0�Ľڵ�
		Select(HT, i - 1, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		//�������Ӻ��Һ��ӿ��Է����������ɵ�Ҳ��һ�úշ�������ֻ�����õı��벻ͬ 
		HT[i].lchild = min1;
		HT[i].rchild = min2;

		HT[i].weight = HT[min1].weight + HT[min2].weight;

	}

	//��Ҷ�ӽڵ㵽���ڵ�������շ�����HT��n��Ҷ�ӽڵ�ĺշ������룬��������HC�� 

	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char*));//����n���ַ������ͷָ������

	//��ʱ�ռ䣬��������ÿ����õĺշ������봮  
	//������n��Ҷ�ӽڵ�ĺշ���������Ҷ�ӽڵ�ı��볤���������n-1  
	//���һ��'\0'����������˷�������鳤���Ϊn����
	char* code = (char*)malloc(n*sizeof(char));//���������Ĺ����ռ�


	code[n - 1] = '\0';//���������

	for (i = 1; i <= n; ++i)//����ַ���շ�������
	{
		int start = n - 1;//���������λ��
		int current;//���嵱ǰ���ʵĽڵ� 
		int father;//��ǰ�ڵ�ĸ��ڵ�

		//��Ҷ�ӵ������������
		for (current = i, father = HT[i].parent; father != 0; current = father, father = HT[father].parent)
		{
			if (HT[father].lchild == current)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start)*sizeof(char));//Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &code[start]);
	}
	free(code);
}


// ��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ-1���������ֱ�����ű�����min1��min2��
void Huffman::Select(HuffmanTree HT, int k, int& min1, int& min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}


// ��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ-1��Ԫ�أ�������Ԫ�ص���ŷ���
int Huffman::min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //�������weight��С��parentΪ-1��Ԫ�ص����  
	int min_weight; //�������weight��С��parentΪ-1��Ԫ�ص�weightֵ  

	//�Ƚ���һ��parentΪ-1��Ԫ�ص�weightֵ����min_weight,�����Ժ�Ƚ��á�  
	//ע�⣬���ﲻ�ܰ���һ�����������ֱ�ӽ�HT[0].weight����min_weight��  
	//��Ϊ���HT[0].weight��ֵ�Ƚ�С����ô�ڵ�һ�ι��������ʱ�ͻᱻѡ�ߣ�  
	//��������ÿһ��ѡ����СȨֵ����������ıȽϻ�������HT[0].weight��ֵ�������жϣ�  
	//�����ֻ��ٴν���ѡ�ߣ��Ӷ������߼��ϵĴ���  
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//ѡ��weight��С��parentΪ-1��Ԫ�أ���������Ÿ���min  
	for (; i<k; i++)
	{
		if (HT[i].weight<min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}

	//ѡ��weight��С��Ԫ�غ󣬽���parent��1��ʹ����һ�αȽ�ʱ�����ų����⡣  
	HT[min].parent = 1;

	return min;
}
