#pragma once

#include"Vertex.h"

//邻接矩阵类
class AMGraph
{
	Vertextype *head;
	int ** Matrix;//邻接矩阵
	int vertexnum, edgenum;
	int dflag, wflag;//区分是有向(其他)还是无向(0)默认无向,有无权值
public:
	AMGraph(int vertexnum, int edgenum, int wflag=0, int dflag = 0);
	int TDnum(Vertextype v);
	~AMGraph();
};

