#include "Graph.h"
#include "Queue.h"

ZO_BEGIN_MAMESPACE

Graph::Graph()
{
}


Graph::~Graph()
{
}

// 建立无向图的邻接矩阵
void Graph::CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("输入顶点数和边数：");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//输入顶点数和边数

	printf("输入%d个顶点信息：", G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)
		scanf(&G->vexs[i]);

	//邻接矩阵初始化
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	}

	//读入G->numEdges条边，建立邻接矩阵
	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边(vi,vj)上的下标i,下标j和权w：");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//无向图，矩阵对称
	}
	
}


// 建立无向图的邻接表结构
void Graph::CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);

	printf("输入%d个顶点信息：\n", G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)//读入顶点信息，建立顶点表
	{
		scanf("%d",&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++)//建立边表
	{
		printf("输入边(vi,vj)上的顶点序号：");
		scanf("%d,%d",&i,&j);

		//向顶点i插入边节点j
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;				//邻接序号为j
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		//向顶点j插入边节点i
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;				//邻接序号为i
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}

}

//邻接矩阵深度优先递归算法
void Graph::DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%d ", G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);
	}
}

//邻接矩阵深度遍历
void Graph::DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;

	printf("邻接矩阵深度遍历:\n");

	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}

//邻接表深度优先递归算法
void Graph::DFS(GraphAdjList* GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%d ", GL->adjList[i].data);//打印顶点,也可以其它操作
	p = GL->adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])//对为访问的邻接顶点递归调用
		{
			DFS(GL, p->adjvex);
		}
			
		p = p->next;
	}
}

//邻接表深度遍历
void Graph::DFSTraverse(GraphAdjList* GL)
{
	int i;
	for (i = 0; i < GL->numVertexes; i++)//初始所有顶点状态都是未访问过状态
		visited[i] = FALSE;

	printf("邻接表深度遍历:\n");

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!visited[i])//对未访问过的顶点调用DFS,若是连通图,只会执行一次
			DFS(GL, i);
	}
}

//邻接矩阵的广度遍历算法
void Graph::BFSTraverse(MGraph G)
{
	int i, j;
	Queue<int> queue;
	queue.InitQueue();

	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;

	printf("邻接矩阵广度遍历:\n");

	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%d ", G.vexs[i]);
			queue.enQueue(i);
			
			while (!queue.QueueEmpty())
			{
				queue.deQueue(i);
				for (j = 0; j < G.numVertexes; j++)
				{
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%d ", G.vexs[j]);
						queue.enQueue(j);
					}
				}
			}
		}
	}
}

/* 邻接表的广度遍历算法 */
void Graph::BFSTraverse(GraphAdjList* GL)
{
	int i;
	EdgeNode *p;
	Queue<int> queue;
	queue.InitQueue();

	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = FALSE;

	printf("邻接表广度遍历:\n");

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%d ", GL->adjList[i].data);/* 打印顶点,也可以其它操作 */
			queue.enQueue(i);
			while (!queue.QueueEmpty())
			{
				queue.deQueue(i);
				p = GL->adjList[i].firstedge;	/* 找到当前顶点的边表链表头指针 */
				while (p)
				{
					if (!visited[p->adjvex])	/* 若此顶点未被访问 */
					{
						visited[p->adjvex] = TRUE;
						printf("%d ", GL->adjList[p->adjvex].data);
						queue.enQueue(p->adjvex);	/* 将此顶点入队列 */
					}
					p = p->next;	/* 指针指向下一个邻接点 */
				}
			}
		}
	}
}



//Prim算法生成连通网最小生成树
void Graph::MiniSpanTree_Prim(MGraph G)
{
	int min, i, j;
	int k;//最小权值顶点下标
	int adjvex[MAXVEX];//保存顶点下标
	int lowcost[MAXVEX];//保存顶点间边的权值

	lowcost[0] = 0;
	adjvex[0] = 0;

	//初始化v0顶点，lowcost，adjvex
	for (i = 1; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];//将v0顶点与之有边的权值存入数组
		adjvex[i] = 0;//初始化都为v0的下标

	}

	//
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;//初始化最小权值为∞，通常设置为不可能的大数字如32767、65535等
		j = 1; 
		k = 0;

		//循环全部顶点，查找lowcost中的最小权值
		while (j<G.numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//当前权值为最小值
				k = j;			//最小权值下标存入k
			}
			j++;
		}

		printf("(%d,%d)", adjvex[k], k);//打印当前顶点边中权值最小边
		lowcost[k] = 0;//将当前顶点的权值设置为0，表示此顶点已经完成任务

		//初始化k顶点，lowcost，adjvex
		for (j = 1; j < G.numVertexes; j++)//循环全部节点
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];//将k顶点与之有边的权值存入数组
				adjvex[j] = k;//初始化为k的下标
			}
		}
	}
}

#define MAXEDGE	15
#define MAXVEX	9

//边集数组
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

// Kruskal算法生成最小生成树
void Graph::MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];//边集并按权由小到大排序
	int parent[MAXVEX];//用来判断边与边是否形成环路

	//此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码

	//初始化为0
	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;

	//循环每条边
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);

		if (n != m)//n不等于m，此边没有与现有生成树形成环路
		{
			parent[n] = m;//将此边的尾顶点m存入下标为起点n的parent中
			printf("(%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}


// 查找连线顶点的尾部下标
int Graph::Find(int* parent, int f)
{
	while (parent[f]>0)
	{
		f = parent[f];
	}
	return f;
}

#define MAXVEX	9

// 有向网G的v顶点到其余顶点v最短路径P[v]及带权长度D[v]
void Graph::ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx* P, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1表示求得顶点v0至vw的最短路径

	//初始化数据
	for (v = 0; v < G.numVertexes; v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;
	}

	(*D)[v0] = 0;
	final[v0] = 1;

	//开始主循环，每次求得v0到某个v顶点的最短路径
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}

		final[k] = 1;

		//修正当前最短路径及距离
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}

}

// 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。
Status Graph::TopologicalSort(GraphAdjList* GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;  /* 用于栈指针下标  */
	int count = 0;/* 用于统计输出顶点的个数  */
	int *stack;	/* 建栈将入度为0的顶点入栈  */
	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i<GL->numVertexes; i++)
	if (0 == GL->adjList[i].in) /* 将入度为0的顶点入栈 */
		stack[++top] = i;
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++;        /* 输出i号顶点，并计数 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))  /* 将i号顶点的邻接点的入度减1，如果减1后为0，则入栈 */
				stack[++top] = k;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}

ZO_END_NAMESPACE