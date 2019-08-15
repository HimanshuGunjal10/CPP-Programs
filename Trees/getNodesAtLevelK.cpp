/*
 * Program to get the max width of a Binary Tree
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

void getNodes(Node* node, int level)
{
	if(node == nullptr)
		return;

	if(level==0)
		cout << node->data;

	getNodes(node->left,level-1);
	getNodes(node->right,level-1);
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

	int level = 2;
	cout << "Printing nodes at level " << level << ": ";
	getNodes(node, level);

	printf("\nLa fin");
	return 0;
}
