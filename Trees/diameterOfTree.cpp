/*
 * Program to calculate diameter of a Tree
 * O(n^2)
 */

#include <iostream>
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

int height(Node* node)
{
	if(node == nullptr)
		return 0;
	int lheight = 0;
	int rheight = 0;

	if(node->left)
		lheight = height(node->left) + 1;

	if(node->right)
		rheight = height(node->right) + 1;

	return ((lheight > rheight)? lheight : rheight);
}

int calculate_diameter(Node* root)
{
	if(root == NULL)
		return 0;

	int lheight = 0;
	int rheight = 0;

	if(root->left)
		lheight = height(root->left);
	else
		lheight = -1;

	if(root->right)
		rheight = height(root->right);
	else
		rheight = -1;
	cout << "l-r: " << lheight << "-" << rheight << endl;
	int diam = lheight + rheight + 2;	//2 is for root node. Hence the -1 so theat it negates if there is not left or right subtree from the root itself
	return diam;

}

int main()
{
	Node *node 				= 	newNode(5);
	node->left 				= 	newNode(3);
	node->left->left 		= 	newNode(1);
	node->left->right 		=	newNode(2);
	node->right				= 	newNode(6);
	node->right->right		=	newNode(8);
	node->right->left		=  	newNode(7);
	node->right->left->right= newNode(9);

	cout << "diameter: " << calculate_diameter(node);

	printf("\nLa fin");
	return 0;
}
