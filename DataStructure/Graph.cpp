#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
}


// 建立图的邻接表结构
void Graph::CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);

	for (i = 0; i < G->numVertexes; i++)//读入顶点信息，建立顶点表
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++)//建立边表
	{
		printf("输入边(vi,vj)上的顶点序号：\n");
		scanf("%d,%d",&i,&j);

		//向顶点j插入边节点
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;				//邻接序号为j
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		//向顶点i插入边节点
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;				//邻接序号为i
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}

}

//深度优先递归算法
void Graph::DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vexs[i]);
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

	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}

//邻接表深度优先递归算法
void Graph::DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c", GL.adjList[i].data);
	p = GL.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(GL, p->adjvex);
		p = p->next;
	}
}

//邻接表深度遍历
void Graph::DFSTraverse(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL.numVertexes; i++)
		visited[i] = FALSE;
	for (i = 0; i < GL.numVertexes; i++)
	{
		if (!visited[i])
			DFS(GL, i);
	}
}

#include "Queue.h"
//邻接矩阵的广度遍历算法
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue queue;
	SqQueue Q;

	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;

	queue.InitQueue(Q);

	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c", G.vexs[i]);
			queue.enQueue(Q, i);
			
			while (!queue.QueueEmpty(Q))
			{
				queue.deQueue(Q, i);
				for (j = 0; j < G.numVertexes; j++)
				{
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c", G.vexs[j]);
						queue.enQueue(Q, j);
					}
				}
			}
		}
	}
}

//Prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//保存顶点下标
	int lowcost[MAXVEX];//保存顶点间边的权值

	lowcost[0] = 0;
	adjvex[0] = 0;

	for (i = 1; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;

	}

	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;

		while (j<G.numVertexes)//循环全部顶点
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//当前权值为最小值
				k = j;			//最小值下标存入k
			}
			j++;
		}
		printf("(%d,%d)", adjvex[k], k);
		lowcost[k] = 0;
		for (j = 1; j < G.numVertexes; j++)//循环全部节点
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
