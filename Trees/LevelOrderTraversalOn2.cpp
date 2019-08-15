/*
 * Program to print a TREE by traversing in LEVEL order
 * Time complexity O(n^2).
 * So, better option is using queues, (not implemented here)
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

//height is calculated in O(n) where n is #nodess
int height(Node* node)
{
	if(node == nullptr)
		return 0;
	int lheight = height(node->left);
	int rheight = height(node->right);

	//compare left and right for getting the max height
	if(lheight >= rheight)
		return lheight+1;
	else
		return rheight+1;

}

void printThisLevel(Node* node, int k)
{
	if(node == NULL)
		return;
	//recursion
	if(k == 1)
		cout << node->data << " ";
	printThisLevel(node->left,k-1);
	printThisLevel(node->right,k-1);
}

void levelOrderTraversal(Node* node)
{
	if(node == NULL)
		return;
	int ht = height(node);
	//recursion
	for(int i=1; i<ht; i++)			//note: i=1
		printThisLevel(node,i);
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


	cout << "Height: " << height(node) << endl;
	cout << "levelOrderTraversal: ";
	levelOrderTraversal(node);

	printf("\nLa fin");
	return 0;
}
