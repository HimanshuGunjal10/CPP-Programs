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

int getHeight(Node* node)
{
	if(node == nullptr)
		return 0;

	Node* curr = node;
	int lheight, rheight;

	if(curr)
	{
		lheight = 1+ getHeight(curr->left);
		rheight = 1+ getHeight(curr->right);
	}
	return (lheight<rheight)? lheight : rheight;
}

int getWidth(Node* node, int i)
{
	if(node == nullptr)
		return 0;
	if(i == 1)
		return 1;
	else
		return getWidth(node->left, i-1) + getWidth(node->right,i-1);
}

int getMaxWidth(Node* node)
{
	if(node == nullptr)
		return 0;

	int height = getHeight(node);
	//cout << "height = " << height;

	int maxWidth = 0;
	int width = 0;
	for(int i=1; i<=height; i++)
	{
		width = getWidth(node, i);
		if(width>maxWidth)
			maxWidth = width;
	}

	return maxWidth;
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

	cout << "Width of the tree is: " << getMaxWidth(node);

	printf("\nLa fin");
	return 0;
}
