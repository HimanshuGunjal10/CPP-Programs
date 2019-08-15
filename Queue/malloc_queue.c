#include<stdio.h>

struct Queue
{
	int front, rear, size;
	unsigned int capacity;
	int *arr;
};

//function

struct Queue* createQueue(int capacity)
{
	struct Queue* myQueue = (struct Queue*) malloc(sizeof(struct Queue));	//imp
	myQueue->capacity = capacity;
	myQueue->front = 0;
	myQueue->rear = capacity-1;
	myQueue->size = 0;
	myQueue->arr = (int*) malloc(sizeof(int)*capacity);		//imp
	return myQueue;
}