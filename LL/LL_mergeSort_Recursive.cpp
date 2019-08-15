#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void FrontBackSplit(Node* head, Node** left, Node** right)
{
	Node* slow;
	Node* fast;

	slow = head;
	fast = head->next;

	while(fast != nullptr)
	{
		fast = fast->next;
		if(fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*left = head;
	*right = slow->next;
	slow->next = nullptr;
}


Node* sortedMerge(Node* a, Node* b)
{
	Node* result = nullptr;

	//base case
	if(a == nullptr)
		return b;
	else if(b == nullptr)
		return a;

	//select a or b to merge in next
	if(a->data <= b->data)
	{
		result = a;
		result->next = sortedMerge(a->next,b);	//missed result->next = here
	}
	else if (b->data < a->data)
	{
		result = b;
		result->next = sortedMerge(a,b->next);
	}

	return result;

}

void mergeSort(Node** headRef)
{
	Node* head = *headRef;

	//base case
	if(head == nullptr || head->next == nullptr)
		return;

	//step: Divide by recursion
	Node* a;
	Node* b;
	FrontBackSplit(head,&a,&b);

	//sort the lists starting from base case. sort left first then right
	mergeSort(&a);
	mergeSort(&b);

	*headRef = sortedMerge(a,b);	//missed *headRef

}

void push(Node** head_ref, int val)
{
	Node* new_node = new Node;
	new_node->data = val;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print(Node* head_ref)
{
	if(head_ref == nullptr)
	{
		cout << "Empty List\n";
		return;
	}

	while(head_ref != nullptr)
	{
		cout << head_ref->data << " ";
		head_ref = head_ref->next;
	}
	cout << endl;

}

int main()
{
	Node* mylist = nullptr;

	push(&mylist,5);
	push(&mylist,7);
	push(&mylist,3);
	push(&mylist,1);
	push(&mylist,9);
	push(&mylist,6);

	print(mylist);

	mergeSort(&mylist);

	print(mylist);

	cout << "La Fin";
	return 0;
}
