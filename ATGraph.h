#pragma once

#include"Vertex.h"

typedef struct ATGnode
{
	int vertexindex;
	int nol;//Ȩֵ
	struct ATGnode* nextedge;
}ATGnode;

typedef struct Vertexnode
{
	Vertextype data;
	ATGnode * firstedge;
}VTnode;
//�ڽӱ���
class ATGraph
{
	VTnode *head;
	int vertexnum, edgenum;
	int dflag, wflag;//�����־��Ȩֵ��־
public:
	ATGraph(int vertexnum,int edgenum,int wflag=0,int dflag=0);
	~ATGraph();
};

