#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
}


// ����ͼ���ڽӱ�ṹ
void Graph::CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);

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

//������ȵݹ��㷨
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

//Prim�㷨������С������
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//���涥���±�
	int lowcost[MAXVEX];//���涥���ߵ�Ȩֵ

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

		while (j<G.numVertexes)//ѭ��ȫ������
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];//��ǰȨֵΪ��Сֵ
				k = j;			//��Сֵ�±����k
			}
			j++;
		}
		printf("(%d,%d)", adjvex[k], k);
		lowcost[k] = 0;
		for (j = 1; j < G.numVertexes; j++)//ѭ��ȫ���ڵ�
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
