
#ifndef  _QUEUE_H_
#define  _QUEUE_H_
#define MAXSIZE 100

#include"Vertex.h"

typedef struct queue
{
	int front = 0;
	int rear = 0;
	Vertextype data[MAXSIZE];
}Queue;


void EnterQueue(Queue &Q, Vertextype T);
void OutQueue(Queue &Q, Vertextype &e);
bool Queueempty(Queue Q);


#endif // ! _QUEUE_H_