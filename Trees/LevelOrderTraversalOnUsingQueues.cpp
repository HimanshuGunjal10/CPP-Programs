/*
 * Program to print a TREE by traversing in LEVEL order
 * Time complexity O(n) using Queues.
 */

#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
	int data;
	Node *left, *right;
};

Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

void levelOrderTraversal(Node* root)
{
	if(root == NULL)
		return;

	queue<Node*> Q;		//queue is of type Node* and not int
	Q.push(root);

	//Queue to be used as:
	//1. display from front and then pop
	//2. push children at back

	while(!Q.empty())
	{
		Node* node = Q.front();
		cout << node->data << " ";
		Q.pop();					//pop the front node. not needed since printed
		//check if that node had left and right nodes. Note: thats why we save it into node
		if(node->left)
			Q.push(node->left);
		if(node->right)
			Q.push(node->right);

	}
}

int main()
{
	Node *node 			= 	newNode(5);
	node->left 			= 	newNode(3);
	node->left->left 	= 	newNode(1);
	node->left->right 	=	newNode(2);
	node->right			= 	newNode(6);
	node->right->right	=	newNode(8);
	node->right->left	=  	newNode(7);
	node->right->left->right= newNode(9);

	cout << "levelOrderTraversal: ";
	levelOrderTraversal(node);

	printf("\nLa fin");
	return 0;
}
