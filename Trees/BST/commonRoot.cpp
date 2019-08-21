/*
 * Binary Search Tree (BST)
 * Find common root
 */

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int n)
{
	Node* temp = new Node;
	temp->data = n;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

Node* insert(Node* root, int val)
{
	//base case
	if(root == nullptr)
	{
		Node* temp = newNode(val);
		return temp;
	}

	//recursion until we find a leaf
	if(val < root->data)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	//no use of next line, only to remove warning
	return root;
}

void printInOrder(Node* root)
{
	if(root == nullptr)
		return;

	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

Node* commonRoot(Node* root, int n1, int n2)
{
	if(root == nullptr)
		return nullptr;

	while(root)
	{
		if(n1 < root->data && n2 < root->data)
			root = root->left;

		else if(n1 > root->data && n2 > root->data)
			root = root->right;

		else
			break;	//i found a root where n1 and n2 are on either side
	}
	return root;
}

int main()
{

    Node* root 				 = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    //inorder will print ascending order
	printInOrder(root);
	cout << endl;


	int n1 = 10;
	int n2 = 4;

	Node* cR = commonRoot(root, n1, n2);

	cout << "common root: " << cR->data << endl;

	printf("\nLa fin");
	return 0;
}
