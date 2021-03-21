#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"
#include<stdlib.h>
//���
void EnterQueue(Queue &Q, Vertextype T)
{
	//�ж��Ƿ�����
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		perror("����!");
		return;
	}
	Q.data[Q.rear] = T;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}

//����
void OutQueue(Queue &Q, Vertextype &e)
{
	//�ж϶ӿ�
	if (Q.front == Q.rear)
	{
		perror("�ӿ�!");
		return;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
}

//�ж϶ӿ�
bool Queueempty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}