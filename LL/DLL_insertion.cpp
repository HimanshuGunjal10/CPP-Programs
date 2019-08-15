#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

//utility function
Node* getNewNode(int val)
{
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	return newNode;
}

void insertAsLast(Node* head, int val)
{
	while(head->next != nullptr)
		head = head->next;
	Node* newNode = getNewNode(val);
	//manage pointers for both previous and new node
	newNode->prev = head;
	head->next = newNode;
}

void insertAfter(Node* head, int val, int k)
{
	Node* curr = head;
	if(curr == nullptr || k == 0)
		return;

	int count=1;	//count = 1 and not 0
	while(count<k && curr != nullptr)
	{
		curr = curr->next;
		count++;
	}

	if(curr == nullptr)
		return;

	Node* newNode = getNewNode(val);

	//link newNode with prev and next node all ways. (3 operations)
	//***Imp chain the existing nodes first before adding new node for correct chaining
	//Order is important
	Node* nextNode = curr->next;

	curr->next = newNode;
	nextNode->prev = newNode;
	newNode->next = nextNode;
	newNode->prev = curr;
}

void deleteNode(Node* head, int val)
{
	if(head == nullptr)
		return;
	Node* curr = head;
	Node* prev =head;
	while(curr != nullptr && curr->data != val)
	{
		prev = curr;
		curr = curr->next;
	}

	if(curr == nullptr)
		cout << "node not found\n";

	else if(curr->data == val)
	{
		curr->next->prev = prev;
		prev->next = curr->next;
		//free(curr);
		delete curr; //either or them works
		//Note: delete is a operator. It calls the destructor. Free is a function, hence free is slower
		//use delete for new and free for malloc(mode of creation)
		//both for HEAP and never for stack

	}
}

void push(Node** head_ref, int val)
{
	Node* newNode = getNewNode(val);

	if(*head_ref == nullptr)
		*head_ref = newNode;
	else
	{
		newNode->next = *head_ref;
		*head_ref = newNode;
	}
}


void print(Node* head)
{
	while(head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head;

	//insert at head
	push(&head, 9);
	push(&head, 7);
	push(&head, 5);
	push(&head, 3);
	push(&head, 1);

	print(head);

	insertAsLast(head, 11);
	print(head);

	//inserts @param2 after @param3 positions
	insertAfter(head, 6, 4);
	print(head);

	//delete a value
	deleteNode(head, 5);
	print(head);

	cout << "La Fin!";
	return 0;
}
