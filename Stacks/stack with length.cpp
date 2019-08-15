#if 1

#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
	int value;
	int length=0;
	node* next;
};

node* getNewNode(int value)
{
	node* temp = new node;
	temp->value = value;
	temp->length +=1;
	temp->next = nullptr;
//	cout << "(" << temp->length << ")";
	return temp;
}

void push(node* &head, int value, int size)
{

	if(head==nullptr)
		head = getNewNode(value);
	else
	{
		if(head->length >= size)
		{
			cout << "Queue is full\n";
			return;
		}
		node* temp = new node;
		temp = getNewNode(head,value);
		temp->next = head;
		temp->length = head->length + 1;
		head = temp;
	}

}

void pop(node* &head)
{
	if(head==nullptr)
		cout<<"Empty queue\n";
	else
	{
		cout << head->value << " is popped\n";
		head = head->next;
		head->length--;
	}
}

void display(node* head)	//and not *& since i don't want head to change
{
	int count=0;
	if(head==nullptr)
		cout <<"Empty list\n";
	else
	{
		while(head!=nullptr)
		{
			cout << head->value << " ";

			count++;
			if(head->next == NULL)
				cout << "length: " << count;

			head = head->next;
		}
	}
	cout<<endl;
	//free(head);
}


int main()
{
	int size=0;
	cout << "enter size of queue: " <<endl;
	cin >> size;
	node* head = nullptr;
	push(head,5,size);
	display(head);
	push(head,6,size);
	display(head);
	push(head,7,size);
	display(head);
	push(head,8,size);
	display(head);
	push(head,9,size);
	display(head);
	pop(head);
	display(head);

	return 0;
}
#endif
