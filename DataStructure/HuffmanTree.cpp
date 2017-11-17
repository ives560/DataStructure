#include "HuffmanTree.h"


Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}


// 赫夫曼编码算法
//赫夫曼树具有如下特性：
//对于同一组权值，所能得到的赫夫曼树不一定是唯一的。
//赫夫曼树的左右子树可以互换，因为这并不影响树的带权路径长度。
//带权值的节点都是叶子节点，不带权值的节点都是某棵子二叉树的根节点。
//权值越大的节点越靠近赫夫曼树的根节点，权值越小的节点越远离赫夫曼树的根节点。
//赫夫曼树中只有叶子节点和度为2的节点，没有度为1的节点。
//一棵有n个叶子节点的赫夫曼树共有2n - 1个节点。
//参考：http://blog.csdn.net/ns_code/article/details/19174553
//HT:构造赫夫曼树
//HC:n个字符的赫夫曼编码
//w:n个字符的权值（均>0）
//n:字符长度
void Huffman::HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n)
{
	if (n <= 1)
		return;

	int total = 2 * n - 1;//一棵有n个叶子节点的赫夫曼树共有2n-1个节点  
	int i;
	HuffmanTree p;

	HT = (HuffmanTree)malloc((total + 1)*sizeof(HTNode));

	//HT[0],HT[1]...HT[n-1]中存放需要编码的n个叶子节点
	for (p = HT,i = 1; i <= n; ++i, ++p, ++w)
	{
		*p = {*w,0,0,0};
	}

	//HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点 
	for (; i <= total; ++i, ++p)
	{
		*p = {0,0,0,0};
	}

	//每一轮比较后选择出min1和min2构成一课二叉树,最后构成一棵赫夫曼树
	for (i = n + 1; i <= total; ++i)//建赫夫曼树
	{
		int min1, min2;//用来保存每一轮选出的两个weight最小且parent为0的节点
		Select(HT, i - 1, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		//这里左孩子和右孩子可以反过来，构成的也是一棵赫夫曼树，只是所得的编码不同 
		HT[i].lchild = min1;
		HT[i].rchild = min2;

		HT[i].weight = HT[min1].weight + HT[min2].weight;

	}

	//从叶子节点到根节点逆向求赫夫曼树HT中n个叶子节点的赫夫曼编码，并保存在HC中 

	//从叶子到根逆向求每个字符的赫夫曼编码
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char*));//分配n个字符编码的头指针向量

	//临时空间，用来保存每次求得的赫夫曼编码串  
	//对于有n个叶子节点的赫夫曼树，各叶子节点的编码长度最长不超过n-1  
	//外加一个'\0'结束符，因此分配的数组长度最长为n即可
	char* code = (char*)malloc(n*sizeof(char));//分配求编码的工作空间


	code[n - 1] = '\0';//编码结束符

	for (i = 1; i <= n; ++i)//逐个字符求赫夫曼编码
	{
		int start = n - 1;//编码结束符位置
		int current;//定义当前访问的节点 
		int father;//当前节点的父节点

		//从叶子到根逆向求编码
		for (current = i, father = HT[i].parent; father != 0; current = father, father = HT[father].parent)
		{
			if (HT[father].lchild == current)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start)*sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i], &code[start]);
	}
	free(code);
}


// 从HT数组的前k个元素中选出weight最小且parent为-1的两个，分别将其序号保存在min1和min2中
void Huffman::Select(HuffmanTree HT, int k, int& min1, int& min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}


// 从HT数组的前k个元素中选出weight最小且parent为-1的元素，并将该元素的序号返回
int Huffman::min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //用来存放weight最小且parent为-1的元素的序号  
	int min_weight; //用来存放weight最小且parent为-1的元素的weight值  

	//先将第一个parent为-1的元素的weight值赋给min_weight,留作以后比较用。  
	//注意，这里不能按照一般的做法，先直接将HT[0].weight赋给min_weight，  
	//因为如果HT[0].weight的值比较小，那么在第一次构造二叉树时就会被选走，  
	//而后续的每一轮选择最小权值构造二叉树的比较还是先用HT[0].weight的值来进行判断，  
	//这样又会再次将其选走，从而产生逻辑上的错误。  
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//选出weight最小且parent为-1的元素，并将其序号赋给min  
	for (; i<k; i++)
	{
		if (HT[i].weight<min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}

	//选出weight最小的元素后，将其parent置1，使得下一次比较时将其排除在外。  
	HT[min].parent = 1;

	return min;
}
