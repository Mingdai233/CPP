#pragma once

#include"Vertex.h"

//�ڽӾ�����
class AMGraph
{
	Vertextype *head;
	int ** Matrix;//�ڽӾ���
	int vertexnum, edgenum;
	int dflag, wflag;//����������(����)��������(0)Ĭ������,����Ȩֵ
public:
	AMGraph(int vertexnum, int edgenum, int wflag=0, int dflag = 0);
	int TDnum(Vertextype v);
	~AMGraph();
};

