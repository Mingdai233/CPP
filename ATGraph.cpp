#include "ATGraph.h"
#include"Queue.h"

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
ATGraph::ATGraph(int vertexnum, int edgenum, int wflag, int dflag)
{
	this->vertexnum = vertexnum;
	this->edgenum = edgenum;
	visited = new bool[vertexnum];
	this->dflag = dflag;
	this->wflag = wflag;
	head = new Vertexnode[vertexnum];
	if (!head)
	{
		perror("内存不足!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < vertexnum; i++)
	{
		cout << "请输入第" << i + 1 << "个顶点" << endl;
		cin >> head[i].data;
		head[i].firstedge = NULL;
		visited[i] = false;//初始化遍历表
	}
	for (int n = 0; n < edgenum; n++)
	{
		Vertextype v1, v2;
		int weight;
		weight = 1;
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
		int i, j;//定位输入定点的坐标
		for (int k = 0; k < vertexnum; k++)
		{
			if (v1 == head[k].data)
				i = k;
			else if (v2 == head[k].data)
				j = k;
		}
		if (dflag == 0)
		{
			ATGnode* Newnode = new ATGnode;
			Newnode->vertexindex = j;
			Newnode->nol = weight;
			Newnode->nextedge = head[i].firstedge;
			head[i].firstedge = Newnode;
			Newnode = new ATGnode;
			Newnode->vertexindex = i;
			Newnode->nol = weight;
			Newnode->nextedge = head[j].firstedge;
			head[j].firstedge = Newnode;
		}
		else
		{
			ATGnode* Newnode = new ATGnode;
			Newnode->vertexindex = j;
			Newnode->nol = weight;
			Newnode->nextedge = head[i].firstedge;
			head[i].firstedge = Newnode;
		}
	}
}

//顶点的度或出度
int ATGraph::TDorODnum(Vertextype v)
{
	int count = 0;
	int n = Locatedv(v);
	ATGnode* p = head[n].firstedge;
	while (p)
	{
		count++;
		p = p->nextedge;
	}
	return count;	
}

//广度优先遍历(利用队列)
void ATGraph::BFSearch(Vertextype v)
{
	Queue Q;
	EnterQueue(Q, v);
	visited[Locatedv(v)] = true;
	while (!Queueempty(Q))
	{
		OutQueue(Q, v);
		ATGnode* p = head[Locatedv(v)].firstedge;
		cout.put(v);
		while (p)
		{
			if (visited[p->vertexindex] == false)
			{
				EnterQueue(Q, head[p->vertexindex].data);
				visited[Locatedv(head[p->vertexindex].data)] = true;
			}
			p = p->nextedge;
		}
	}
}


//找顶点在列表坐标
int ATGraph::Locatedv(Vertextype v)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (head[i].data == v)
		{
			return i;
		}
	}
	return -1;//没有找到
}



ATGraph::~ATGraph()
{
	for (int i = 0; i < vertexnum; i++)
	{
		ATGnode *p = NULL;
		p = head[i].firstedge;
		while (p)
		{
			head[i].firstedge = p->nextedge;
			delete p;
			p = head[i].firstedge;
		}
	}
	delete[]head;
}
