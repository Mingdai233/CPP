#pragma once

#include"Vertex.h"

//�ڽӾ�����
class AMGraph
{
	Vertextype *head;
	bool *visited;//��������
	int ** Matrix;//�ڽӾ���
	int vertexnum, edgenum;
	int dflag, wflag;//����������(����)��������(0)Ĭ������,����Ȩֵ
public:
	AMGraph(int vertexnum, int edgenum, int wflag=0, int dflag = 0);
	int Locaedv(Vertextype v);//�ҵ������±�
	int TDnum(Vertextype v);
	void DFSearch(Vertextype v);
	~AMGraph();
};

