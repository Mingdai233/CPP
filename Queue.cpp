#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"
#include<stdlib.h>
//入队
void EnterQueue(Queue &Q, Vertextype T)
{
	//判断是否满队
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		perror("满队!");
		return;
	}
	Q.data[Q.rear] = T;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}

//出队
void OutQueue(Queue &Q, Vertextype &e)
{
	//判断队空
	if (Q.front == Q.rear)
	{
		perror("队空!");
		return;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
}

//判断队空
bool Queueempty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}