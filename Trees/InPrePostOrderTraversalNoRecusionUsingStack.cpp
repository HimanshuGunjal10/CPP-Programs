/*
 * Program to print a TREE by traversing in order
 * USING STACKS and no RECURSION
 */

#include <iostream>
#include <stack>
using namespace std;

class Node
{

public:
	int data;
	Node *left, *right;
	Node(int val)
	{
		this->data = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void inOrderTraversalRecusrion(Node* node)
{
	if(node == nullptr)
		return;
	inOrderTraversalRecusrion(node->left);
	cout << node->data;
	inOrderTraversalRecusrion(node->right);
}

void inOrderTraversal(Node* node)
{
	if(node == nullptr)
		return;

	stack<Node*> s;

//	//1. push root into stack
//	s.push(temp);
//	//2. traverse the left side and pull all left elements into stack
	Node* curr = node;

	while(curr || !s.empty())
	{
		while(curr)
		{
			s.push(curr);
			curr = curr->left;
		}
		//print the leftmost
		//store the node before removing from stack as we need the right subtree as well
		curr = s.top();
		cout << curr->data;
		//removes the node and we have printed it
		s.pop();
		//change current to point the right subtree of that parent
		curr = curr->right;
	}
}

int main()
{
	Node *node 			= 	new Node(5);
	node->left 			= 	new Node(3);
	node->left->left 	= 	new Node(1);
	node->left->right 	=	new Node(2);
	node->right			= 	new Node(6);
	node->right->right	=	new Node(8);
	node->right->left	=  	new Node(7);
	node->right->right->right=new Node(9);

	cout << "\ninOrderTraversal using recursion: ";
	inOrderTraversalRecusrion(node);

	cout << "\ninOrderTraversal using stack: ";
	inOrderTraversal(node);

	printf("\nLa fin");
	return 0;
}
