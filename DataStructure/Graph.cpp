#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
}

// ��������ͼ���ڽӾ���
void Graph::CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//���붥�����ͱ���

	printf("����%d��������Ϣ��\n", G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)
		scanf(&G->vexs[i]);

	//�ڽӾ����ʼ��
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	}

	//����G->numEdges���ߣ������ڽӾ���
	for (k = 0; k < G->numEdges; k++)
	{
		printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw��\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];//����ͼ������Գ�
	}
	
}


// ����ͼ���ڽӱ�ṹ
void Graph::CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);

	printf("����%d��������Ϣ��\n", G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)//���붥����Ϣ�����������
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++)//�����߱�
	{
		printf("�����(vi,vj)�ϵĶ�����ţ�\n");
		scanf("%d,%d",&i,&j);

		//�򶥵�j����߽ڵ�
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;				//�ڽ����Ϊj
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		//�򶥵�i����߽ڵ�
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;				//�ڽ����Ϊi
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}

}

//�ڽӾ���������ȵݹ��㷨
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

//�ڽӾ�����ȱ���
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

//�ڽӱ�������ȵݹ��㷨
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

//�ڽӱ���ȱ���
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
//�ڽӾ���Ĺ�ȱ����㷨
void Graph::BFSTraverse(MGraph G)
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

//Prim�㷨������ͨ����С������
void Graph::MiniSpanTree_Prim(MGraph G)
{
	int min, i, j;
	int k;//��СȨֵ�����±�
	int adjvex[MAXVEX];//���涥���±�
	int lowcost[MAXVEX];//���涥���ߵ�Ȩֵ

	lowcost[0] = 0;
	adjvex[0] = 0;

	//��ʼ��v0���㣬lowcost��adjvex
	for (i = 1; i < G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];//��v0������֮�бߵ�Ȩֵ��������
		adjvex[i] = 0;//��ʼ����Ϊv0���±�

	}

	//
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;
		j = 1; 
		k = 0;

		//ѭ��ȫ�����㣬����lowcost�е���СȨֵ
		while (j<G.numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//��ǰȨֵΪ��Сֵ
				k = j;			//��СȨֵ�±����k
			}
			j++;
		}

		printf("(%d,%d)", adjvex[k], k);//��ӡ��ǰ�������Ȩֵ��С��
		lowcost[k] = 0;//����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������

		//��ʼ��k���㣬lowcost��adjvex
		for (j = 1; j < G.numVertexes; j++)//ѭ��ȫ���ڵ�
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];//��k������֮�бߵ�Ȩֵ��������
				adjvex[j] = k;//��ʼ��Ϊk���±�
			}
		}
	}
}

#define MAXEDGE	15
#define MAXVEX	9

//�߼�����
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

// Kruskal�㷨������С������
void Graph::MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];//�߼�����Ȩ��С��������
	int parent[MAXVEX];//�����жϱ�����Ƿ��γɻ�·

	//�˴�ʡ�Խ��ڽӾ���Gת��Ϊ�߼�����edges����Ȩ��С��������Ĵ���

	//��ʼ��Ϊ0
	for (i = 0; i < G.numVertexes; i++)
		parent[i] = 0;

	//ѭ��ÿ����
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);

		if (n != m)//n������m���˱�û���������������γɻ�·
		{
			parent[n] = m;//���˱ߵ�β����m�����±�Ϊ���n��parent��
			printf("(%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}


// �������߶����β���±�
int Graph::Find(int* parent, int f)
{
	while (parent[f]>0)
	{
		f = parent[f];
	}
	return f;
}

#define MAXVEX	9

// ������G��v���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
void Graph::ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx* P, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1��ʾ��ö���v0��vw�����·��

	//��ʼ������
	for (v = 0; v < G.numVertexes; v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;
	}

	(*D)[v0] = 0;
	final[v0] = 1;

	//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
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

		//������ǰ���·��������
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
