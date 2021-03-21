#include "AMGraph.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

//定点个数，边/弧条数，是否有权值（默认0无权值），是否有方向（默认0无方向）
AMGraph::AMGraph(int vertexnum, int edgenum, int wflag, int dflag)
{
	this->wflag = wflag;
	this->dflag = dflag;
	this->vertexnum = vertexnum;
	this->edgenum = edgenum;
	visited = new bool[vertexnum];//建立遍历数组
	head = new Vertextype[vertexnum];
	if (!head)
	{
		perror("内存不足!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < vertexnum; i++)
	{
		printf("请输入第%d个顶点:", i + 1);
		cin >> head[i];
		visited[i] = false;//初始化遍历数组
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
			cout << "请输入第" << n + 1 << "条边的两个顶点" << endl;
			cin >> v1 >> v2;
		}
		else
		{
			cout << "请输入第" << n + 1 << "条边的两个顶点" << "和其权值" << endl;
			cin >> v1 >> v2 >> weight;
		}
		int i = Locaedv(v1);
		int j = Locaedv(v2);
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

//求某一顶点的度
int AMGraph::TDnum(Vertextype v)
{
	int count = 0;
	int n = Locaedv(v);
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

//找到顶点下标
int AMGraph::Locaedv(Vertextype v)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (head[i] == v)
		{
			return i;
		}
	}
	return -1;//没找到
}

//深度遍历(起点)
void AMGraph::DFSearch(Vertextype v)
{
	cout.put(v);
	int n = Locaedv(v);
	visited[n]=true;
	for (int i = 0; i < vertexnum; i++)
	{
		if (Matrix[n][i] != 0 && Matrix[n][i] != MAXNUM)
		{
			if (visited[i] != true)
				DFSearch(head[i]);
		}
	}
}

AMGraph::~AMGraph()
{
	delete[]head;
	for (int i = 0; i < vertexnum; i++)
	{
		delete[]Matrix[i];
	}
}
