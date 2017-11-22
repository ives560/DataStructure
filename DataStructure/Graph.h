#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX	100
#define INFINITY	65535

//�ڽӾ���
typedef struct
{
	VertexType vexs[MAXVEX];	//�����
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ��󣬿ɿ����߱�
	int numVertexes;//ͼ�е�ǰ������
	int numEdges;//ͼ�е�ǰ����
}MGraph;

//�ڽӱ���ͼ
typedef struct EdgeNode//�߱���
{
	int adjvex;			//�洢�ö����Ӧ���±�
	EdgeType weight;	//�洢�ߵ�Ȩֵ
	struct EdgeNode *next;//ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode//�������
{
	int in;				/* ������� */
	VertexType data;	//�洢����������Ϣ
	EdgeNode *firstedge;//�߱�ͷָ��
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;


//
typedef int Pathmatirx[MAXVEX];//�洢���·���±������
typedef int ShortPathTable[MAXVEX];//�洢���������·����Ȩֵ��

class Graph
{

private:
	typedef int Boolean;
	Boolean visited[MAX];//�������ʱ�־

public:
	Graph();
	~Graph();
	// ��������ͼ���ڽӾ���
	void CreateMGraph(MGraph* G);
	// ����ͼ���ڽӱ�ṹ
	void CreateALGraph(GraphAdjList* G);

	//�ڽӾ���������ȵݹ��㷨
	void DFS(MGraph G, int i);
	//�ڽӾ�����ȱ���
	void DFSTraverse(MGraph G);
	//�ڽӾ���Ĺ�ȱ����㷨
	void BFSTraverse(MGraph G);
	//�ڽӱ�������ȵݹ��㷨
	void DFS(GraphAdjList* GL, int i);
	//�ڽӱ���ȱ���
	void DFSTraverse(GraphAdjList* GL);
	/* �ڽӱ�Ĺ�ȱ����㷨 */
	void BFSTraverse(GraphAdjList* GL);

	//Prim�㷨������ͨ����С������
	void MiniSpanTree_Prim(MGraph G);
	// Kruskal�㷨������С������
	void MiniSpanTree_Kruskal(MGraph G);
	// �������߶����β���±�
	int Find(int* parent, int f);
	// ������G��v���㵽���ඥ��v���·��P[v]����Ȩ����D[v]
	void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx* P, ShortPathTable* D);

	// ����������GL�޻�·������������������в�����1�����л�·����0��
	Status TopologicalSort(GraphAdjList* GL);
};

ZO_END_NAMESPACE