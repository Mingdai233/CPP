#include "AMGraph.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

//�����������/���������Ƿ���Ȩֵ��Ĭ��0��Ȩֵ�����Ƿ��з���Ĭ��0�޷���
AMGraph::AMGraph(int vertexnum, int edgenum, int wflag, int dflag)
{
	this->wflag = wflag;
	this->dflag = dflag;
	this->vertexnum = vertexnum;
	this->edgenum = edgenum;
	head = new Vertextype[vertexnum];
	if (!head)
	{
		perror("�ڴ治��!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < vertexnum; i++)
	{
		printf("�������%d������:", i + 1);
		cin >> head[i];
	}
	Matrix = new int*[vertexnum];
	for (int i = 0; i < vertexnum; i++)
	{
		Matrix[i] = new int[vertexnum];
	}
		for (int i = 0; i < vertexnum; i++)
		{
			for (int j = 0; j < vertexnum; j++)
			{
				if (this->dflag == 0)
					Matrix[i][j] = 0;
				else
					Matrix[i][j] = MAXNUM;
			}
		}
	for (int n = 0; n < edgenum; n++)
	{
		Vertextype v1, v2;
		int weight=1;
		if (wflag == 0)
		{
			cout << "�������" << n + 1 << "���ߵ���������" << endl;
			cin >> v1 >> v2;
		}
		else
		{
			cout << "�������" << n + 1 << "���ߵ���������" << "����Ȩֵ" << endl;
			cin >> v1 >> v2 >> weight;
		}
		int i = Locaedgd(head, v1, vertexnum);
		int j = Locaedgd(head, v2, vertexnum);
		if (this->dflag == 0)
		{
			Matrix[i][j] = weight;
			Matrix[j][i] = weight;
		}
		else
		{
			Matrix[i][j] = weight;
		}
	}
}

int AMGraph::TDnum(Vertextype v)
{
	int count = 0;
	int n = Locaedgd(head, v, vertexnum);
	if (dflag == 0)
	{
		for (int i = 0; i < vertexnum; i++)
		{
			if (Matrix[n][i] != 0)
				count++;
		}
	}
	else
	{
		for (int i = 0; i < vertexnum; i++)
		{
			if (Matrix[n][i] != MAXNUM)
				count++;
		}
		for (int i = 0; i < vertexnum; i++)
		{
			if (Matrix[i][n] != MAXNUM)
				count++;
		}
	}
	return count;
}

AMGraph::~AMGraph()
{
	delete[]head;
	for (int i = 0; i < vertexnum; i++)
	{
		delete[]Matrix[i];
	}
}
