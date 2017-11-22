#pragma once

#include"Comm.h"

ZO_BEGIN_MAMESPACE

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
	int in;				/* 顶点入度 */
	VertexType data;	//存储顶点数据信息
	EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;


//
typedef int Pathmatirx[MAXVEX];//存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];//存储到各点最短路径的权值和

class Graph
{

private:
	typedef int Boolean;
	Boolean visited[MAX];//顶点表访问标志

public:
	Graph();
	~Graph();
	// 建立无相图的邻接矩阵
	void CreateMGraph(MGraph* G);
	// 建立图的邻接表结构
	void CreateALGraph(GraphAdjList* G);

	//邻接矩阵深度优先递归算法
	void DFS(MGraph G, int i);
	//邻接矩阵深度遍历
	void DFSTraverse(MGraph G);
	//邻接矩阵的广度遍历算法
	void BFSTraverse(MGraph G);
	//邻接表深度优先递归算法
	void DFS(GraphAdjList* GL, int i);
	//邻接表深度遍历
	void DFSTraverse(GraphAdjList* GL);
	/* 邻接表的广度遍历算法 */
	void BFSTraverse(GraphAdjList* GL);

	//Prim算法生成连通网最小生成树
	void MiniSpanTree_Prim(MGraph G);
	// Kruskal算法生成最小生成树
	void MiniSpanTree_Kruskal(MGraph G);
	// 查找连线顶点的尾部下标
	int Find(int* parent, int f);
	// 有向网G的v顶点到其余顶点v最短路径P[v]及带权长度D[v]
	void ShortestPath_Dijkstra(MGraph G, int v0, Pathmatirx* P, ShortPathTable* D);

	// 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。
	Status TopologicalSort(GraphAdjList* GL);
};

ZO_END_NAMESPACE