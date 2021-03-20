#define _CRT_SECURE_NO_WARNINGS 1
#include"Vertex.h"

int Locaedgd(Vertextype *head, Vertextype v,int vertexnum)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (head[i] == v)
		{
			return i;
		}
	}
	return -1;//Ã»ÕÒµ½
}