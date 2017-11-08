#pragma once

#include"Comm.h"

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
	VertexType data;	//�洢����������Ϣ
	EdgeNode *firstedge;//�߱�ͷָ��
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;


typedef int Boolean;
Boolean visited[MAX];//�������ʱ�־

class Graph
{
public:
	Graph();
	~Graph();
	// ����ͼ���ڽӱ�ṹ
	void CreateALGraph(GraphAdjList* G);

	//�ڽӾ���������ȵݹ��㷨
	void DFS(MGraph G, int i);
	//�ڽӾ�����ȱ���
	void DFSTraverse(MGraph G);

	//�ڽӱ�������ȵݹ��㷨
	void DFS(GraphAdjList GL, int i);

	//�ڽӱ���ȱ���
	void DFSTraverse(GraphAdjList GL);
};

