/*
 * Binary Search Tree (BST)
 * Check if the tree is BST or not
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

bool isBinaryUtil(Node* root, Node* &prev)	//note &* prev
{
	//base case
	if(root == nullptr)
		return true;

	if (!isBinaryUtil(root->left,prev)) //recurse till last node on left (In order)
		return false;

	if(prev!= nullptr && root->data <= prev->data)
		return false;
	prev = root;
	return isBinaryUtil(root->right, prev);

}

bool isBinary(Node* root)
{
	Node* prev = nullptr;
	return isBinaryUtil(root,prev);
}

int main()
{

    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(6);

    //inorder will print ascending order
	printInOrder(root);

	if(isBinary(root))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	printf("\nLa fin");
	return 0;
}
