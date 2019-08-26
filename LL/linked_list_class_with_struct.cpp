#include<iostream>
using namespace std;

class node_class
{
public:
	node_class();
	node_class(int num);
	void append(int value);
	void print();


private:
	struct node
	{
		int value;
		node* next;
	};

	node* head;
	node* tail;
};

node_class::node_class()
{
	head = NULL;
	tail = NULL;
}

node_class::node_class(int num)
{
	node* temp = new node;
	temp->value = num;
	temp->next = NULL;
	head = temp;
	tail = temp;

}

void node_class::append(int num)
{
	node* temp = new node;
	temp->value = num;
	temp->next = NULL;

	if(head == NULL)
	{
		head = temp;
		tail = temp;
		return;
	}

//No need for following code if maintaining tail
/*	node* curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = temp;*/
	tail->next = temp;
	tail = temp;
}

void node_class::print()
{
	if(head == NULL)
	{
		cout << "List is empty!" << endl;
		return;
	}

	node* curr = head;
	//node* curr = new node;	//no need for these
	//curr = head;
	while (curr!=NULL)
	{
		cout << curr->value << " ";
		curr = curr->next;
	}
	cout << endl;
}


int main()
{

	node_class myNodeObj(6);
	myNodeObj.append(5);
	myNodeObj.append(4);
	myNodeObj.append(1);

	myNodeObj.print();

	cout << "Fin";
	return 0;
}
