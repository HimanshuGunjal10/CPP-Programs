/*
 * Program to check if S is a subtree of T
 * Time complexity : O(mn)
 */

#include <iostream>
using namespace std;

class Node
{

public:
	int data;
	Node *left, *right;
	void newNode(int val);
};

Node* newNode(int val)
{
	Node* newnode = new Node;
	newnode->data = val;
	newnode->left = nullptr;
	newnode->right = nullptr;
	return newnode;
}

bool areIdentical(Node* T, Node* S)
{
	//base case: both null at the same time only then true
	if(T == nullptr && S == nullptr)
		return true;

	//if either of them goes null alone; false
	if(T == nullptr || S == nullptr)
		return false;

	//keep returning ony if the data are going on matching
	return ((T->data == S->data) && areIdentical(T->left,S->left) && areIdentical(T->right,S->right));
}

bool isSubtree(Node* T, Node* S)
{
	if(!T || !S)
		return false;

	//base case
	if(T->data == S->data)
	{
		return areIdentical(T,S);
	}
	return (isSubtree(T->left,S)|| isSubtree(T->right,S));


}

int main()
{
    Node *T = newNode(26);
    T->right         = newNode(3);
    T->right->right = newNode(3);
    T->left         = newNode(10);
    T->left->left     = newNode(4);
    T->left->left->right = newNode(30);
    T->left->right     = newNode(6);

    Node *S = newNode(10);
    S->right     = newNode(6);
    S->left     = newNode(4);
    S->left->right = newNode(30);

	cout << "Is binary tree a subtree or not!" << endl;
	if(isSubtree(T,S))
		cout << "Yes, a subtree" << endl;
	else
		cout << "Not a subtree!" << endl;

	printf("\nLa fin");
	return 0;
}
