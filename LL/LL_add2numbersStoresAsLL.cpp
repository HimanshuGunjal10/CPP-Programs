#include <iostream>
using namespace std;

/* Linked list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* Function to create a new node with given data */
Node *newNode(int data)
{
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = newNode(new_data);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

/* Adds contents of two linked lists and
return the head node of resultant list */
Node* addTwoLists (Node* first, Node* second)
{
	Node* res = nullptr;
	Node* res_head = nullptr;
	int sum, carry = 0;

	while(first || second)
	{
		sum = carry + (first? first->data : 0) + (second? second->data : 0);
		carry = sum/10;

		if(res == nullptr)
		{
			res = newNode(sum%10);
			res_head = res;
		}
		else
		{
			res->next = newNode(sum%10);
			res = res->next;
		}

		//iterate further in the list
		if(first)
			first = first->next;
		if(second)
			second = second->next;
	}
	if (carry)
		res->next = newNode(carry);
	return res_head;
}

// A utility function to print a linked list
void printList(Node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout<<endl;
}

/* Driver code */
int main(void)
{
	Node* res = NULL;
	Node* first = NULL;
	Node* second = NULL;

	// create first list 7->5->9->4->6
	push(&first, 9);
	push(&first, 9);
	push(&first, 9);
	push(&first, 5);
	push(&first, 7);
	printf("First List is ");
	printList(first);

	// create second list 8->4
	push(&second, 4);
	push(&second, 8);
	cout<<"Second List is ";
	printList(second);

	// Add the two lists and see result
	res = addTwoLists(first, second);
	cout<<"Resultant list is ";
	printList(res);

	cout << "La Fin";

return 0;
}

