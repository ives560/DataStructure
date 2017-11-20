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
//n:�ַ�����
void Huffman::HuffmanCoding(HuffmanTree HT, HuffmanCode& HC, int n)
{
	//��������ָ��ÿ���շ������봮��ָ��  
	HC = (HuffmanCode)malloc(n*sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}

	//��ʱ�ռ䣬��������ÿ����õĺշ������봮  
	//������n��Ҷ�ӽڵ�ĺշ���������Ҷ�ӽڵ�ı��볤���������n-1  
	//���һ��'\0'����������˷�������鳤���Ϊn����  
	char *code = (char *)malloc(n*sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	code[n - 1] = '\0';  //����������������ַ�����Ľ�����־  
	//��ÿ���ַ��ĺշ�������  
	int i;
	for (i = 0; i<n; i++)
	{
		int current = i;           //���嵱ǰ���ʵĽڵ�  
		int father = HT[i].parent; //��ǰ�ڵ�ĸ��ڵ�  
		int start = n - 1;           //ÿ�α����λ�ã���ʼΪ�����������λ��  
		//��Ҷ�ӽڵ�����շ�����ֱ�����ڵ�  
		while (father != -1)
		{
			if (HT[father].lchild == current)   //��������ӣ������Ϊ0  
				code[--start] = '0';
			else                              //������Һ��ӣ������Ϊ1         
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		//Ϊ��i���ַ��ı��봮����洢�ռ�  
		HC[i] = (char *)malloc((n - start)*sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		//�����봮��code���Ƶ�HC  
		strcpy(HC[i], code + start);
	}

	free(code); //�ͷű�����봮����ʱ�ռ�  
}

// ���ݸ�����n��Ȩֵ����һ�úշ�����,wet�д��n��Ȩֵ
HuffmanTree Huffman::create_HuffmanTree(int* wet, int n)
{
	//һ����n��Ҷ�ӽڵ�ĺշ���������2n-1���ڵ�  
	int total = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;

	//���³�ʼ�����ȫ����-1��ʾ��  
	//�����ڱ��뺯���н���ѭ���ж�parent��lchild��rchild�����ʱ��  
	//������HT�����е��κ�һ���±����  

	//HT[0],HT[1]...HT[n-1]�д����Ҫ�����n��Ҷ�ӽڵ�  
	for (i = 0; i<n; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *wet;
		wet++;
	}

	//HT[n],HT[n+1]...HT[2n-2]�д�ŵ����м乹�����ÿ�ö������ĸ��ڵ�  
	for (; i<total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}

	int min1, min2; //��������ÿһ��ѡ��������weight��С��parentΪ0�Ľڵ�  
	//ÿһ�ֱȽϺ�ѡ���min1��min2����һ�ζ�����,��󹹳�һ�úշ�����  
	for (i = n; i<total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		//�������Ӻ��Һ��ӿ��Է����������ɵ�Ҳ��һ�úշ�������ֻ�����õı��벻ͬ  
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}


// ��HT�����ǰk��Ԫ����ѡ��weight��С��parentΪ-1���������ֱ�����ű�����min1��min2��
void Huffman::select_minium(HuffmanTree HT, int k, int& min1, int& min2)
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
	while (HT[i].parent != -1)//ѡ����һ��parentΪ-1��Ԫ��
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

