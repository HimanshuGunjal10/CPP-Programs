/*
 * Program to print a TREE by traversing in pre post and in order
 */

#include <iostream>
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

void inOrderTraversal(Node* node)
{
	if(node == NULL)
		return;
	//recursion
	inOrderTraversal(node->left);
	cout << node->data << " ";
	inOrderTraversal(node->right);
}

void preOrderTraversal(Node* node)
{
	if(node == NULL)
		return;
	//recursion
	cout << node->data << " ";
	preOrderTraversal(node->left);
	preOrderTraversal(node->right);
}

void postOrderTraversal(Node* node)
{
	if(node == NULL)
		return;
	//recursion
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	cout << node->data << " ";
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

	cout << "preOrderTraversal: ";
	preOrderTraversal(node);
	cout << "\ninOrderTraversal: ";
	inOrderTraversal(node);
	cout << "\npostOrderTraversal: ";
	postOrderTraversal(node);

	printf("\nLa fin");
	return 0;
}
