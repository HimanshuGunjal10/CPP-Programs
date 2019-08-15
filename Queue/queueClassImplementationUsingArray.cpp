/*
 * Program to implement a queue using array implementation
 */

#include <iostream>
using namespace std;

class Queue
{
	int *arr;
	int front, rear, size;
	unsigned int capacity;
public:
	Queue(int cap);
	bool isEmpty();
	bool isFull();
	void enqueue(int item);
	void dequeue();
	int getFront();
	int getRear();
	void print();
};

//constructor
Queue::Queue(int cap)
{
	//Queue* queue = new Queue;
	front = 0;
	rear = cap-1;
	capacity = cap;
	size = 0;
	arr = new int[(cap * sizeof(int))];	//imp
}

//utility functions
bool Queue::isEmpty()
{
	if(size==0)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if(size==(int)capacity)	//to remove warning
		return true;
	else
		return false;
}

void Queue::enqueue(int item)
{
	if(isFull())
		return;
	rear = (rear+1)%capacity;	//imp
	arr[rear] = item;
	size++;
}

void Queue::dequeue()
{
	if(isEmpty())
		return;
	front = (front+1)%capacity;
	size--;
}

int Queue::getFront()
{
	if(isEmpty())
		return INT_MIN;		//imp
	return arr[front];
}

int Queue::getRear()
{
	if(isEmpty())
		return INT_MIN;		//imp
	return arr[rear];
}

void Queue::print()
{
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	Queue queue(10);
	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(9);

	queue.print();
	cout << "front: " << queue.getFront() << endl;
	cout << "rear: "  << queue.getRear() << endl;

	cout << "Deque\n";
	queue.dequeue();

	queue.print();
	cout << "front: " << queue.getFront() << endl;
	cout << "rear: "  << queue.getRear() << endl;


	cout << "La fin";
	return 0;
}
