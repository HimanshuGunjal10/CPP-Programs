/*
 * Implementation of stack using LL
 */

#include <iostream>
using namespace std;

class StackNode
{
public:				//use public if not accessing using objects
	int data;
	StackNode* next;
};

bool isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int val)
{
	StackNode* new_top = new StackNode;
	new_top->data = val;
	new_top->next = *root;
	*root = new_top;
}

void pop(StackNode** root)
{
	if(isEmpty(*root))
	{
		cout<< "Empty queue" << endl;
		return;
	}
	StackNode* temp = *root;
	*root = (*root)->next;
	free(temp);
}

void print(StackNode* root)
{
	if(isEmpty(root))
		return;
	StackNode* curr = root;
	while(curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int peek(StackNode* root)
{
	return root->data;
}

int main()
{
	StackNode* root = nullptr;
	//pop(&root);
	push(&root, 5);
	push(&root, 7);
	push(&root, 3);
	cout << "Peeking: " << peek(root) << endl;
	push(&root, 1);
	print(root);
	pop(&root);
	print(root);

	cout << "La fin";
	return 0;
}
