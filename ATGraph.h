#pragma once

#include"Vertex.h"

typedef struct ATGnode
{
	int vertexindex;
	int nol;//权值
	struct ATGnode* nextedge;
}ATGnode;

typedef struct Vertexnode
{
	Vertextype data;
	ATGnode * firstedge;
}VTnode;
//邻接表类
class ATGraph
{
	VTnode *head;
	bool *visited;//遍历表
	int vertexnum, edgenum;
	int dflag, wflag;//方向标志，权值标志
public:
	ATGraph(int vertexnum,int edgenum,int wflag=0,int dflag=0);
	int TDorODnum(Vertextype v);
	int Locatedv(Vertextype v);
	void BFSearch(Vertextype v);
	~ATGraph();
};

