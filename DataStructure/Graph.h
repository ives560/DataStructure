#pragma once

#include"Comm.h"

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX	100
#define INFINITY	65535

//邻接矩阵
typedef struct
{
	VertexType vexs[MAXVEX];	//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵，可看作边表
	int numVertexes;//图中当前顶点数
	int numEdges;//图中当前边数
}MGraph;

//邻接表，链图
typedef struct EdgeNode//边表结点
{
	int adjvex;			//存储该顶点对应的下标
	EdgeType weight;	//存储边的权值
	struct EdgeNode *next;//指向下一个邻接点
}EdgeNode;

typedef struct VertexNode//顶点表结点
{
	VertexType data;	//存储顶点数据信息
	EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;


typedef int Boolean;
Boolean visited[MAX];//顶点表访问标志

class Graph
{
public:
	Graph();
	~Graph();
	// 建立图的邻接表结构
	void CreateALGraph(GraphAdjList* G);

	//邻接矩阵深度优先递归算法
	void DFS(MGraph G, int i);
	//邻接矩阵深度遍历
	void DFSTraverse(MGraph G);

	//邻接表深度优先递归算法
	void DFS(GraphAdjList GL, int i);

	//邻接表深度遍历
	void DFSTraverse(GraphAdjList GL);
};

