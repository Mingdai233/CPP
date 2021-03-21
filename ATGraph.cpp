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
		perror("�ڴ治��!");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < vertexnum; i++)
	{
		cout << "�������" << i + 1 << "������" << endl;
		cin >> head[i].data;
		head[i].firstedge = NULL;
		visited[i] = false;//��ʼ��������
	}
	for (int n = 0; n < edgenum; n++)
	{
		Vertextype v1, v2;
		int weight;
		weight = 1;
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
		int i, j;//��λ���붨�������
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

//����ĶȻ����
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

//������ȱ���(���ö���)
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


//�Ҷ������б�����
int ATGraph::Locatedv(Vertextype v)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (head[i].data == v)
		{
			return i;
		}
	}
	return -1;//û���ҵ�
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
