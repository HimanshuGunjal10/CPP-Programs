/*
 * Program to implement a queue using LL implementation in C
 */

#include <stdio.h>
#include <stdlib.h>	//removes warning while declaring malloc:
					//incompatible implicit declaration of built-in function ‘malloc’

struct QNode
{
	int data;
	struct QNode* next;
};

struct Queue
{
	struct QNode *front, *rear;		//since LL it can expand so no need of capacity,size
};

//utility function
struct QNode* newNode(int val)
{
	//allocate memory for node
	struct QNode *temp = (struct QNode*) malloc (sizeof(struct QNode));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

//utility function
struct Queue* createQueue()
{
	//allocate memory for queue
	struct Queue *queue = (struct Queue* ) malloc (sizeof(struct Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

//enQueue
void enQueue(struct Queue* q, int val)
{
	//1. create a node
	struct QNode* temp = newNode(val);

	//check if Queue is empty by checking rear, then this will be first node
	if(q->rear == NULL)
	{
		q->front = temp;
		q->rear  = temp;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
	}
}

//deQueue (returns the node as well)
struct QNode* deQueue(struct Queue* q)
{
	if(q->front == NULL)
	{
		printf("Empty queue\n");
		return NULL;
	}

	struct QNode* temp = q->front;
	q->front = q->front->next;

	//Note: handle a case here that there was just one node.
	if(q->front == NULL)
		q->rear = NULL;
	return temp;

}

//print
void print(struct Queue* q)
{
	if(q->front == NULL)
	{
		printf("Empty queue\n");
		return;
	}
	//iterator
	struct QNode* it = q->front;
	while(it != q->rear)
	{
		printf("%d ",it->data);
		it = it->next;
	}
	printf("%d ",q->rear->data);		//don't forget the rear
	printf("\n");


}

int main()
{
	// MISTAKE: struct Queue *q = NULL;
	struct Queue *q = createQueue();
	enQueue(q,1);
	enQueue(q,3);
	enQueue(q,5);
	enQueue(q,7);
	enQueue(q,9);

	print(q);

	struct QNode* temp = deQueue(q);
	printf("deQueued: %d \n", temp->data);

	print(q);

	printf("La fin");
	return 0;
}
