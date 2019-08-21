/*
 * Binary Search Tree (BST)
 * 1. insert
 * 2. search
 * 3. delete
 * 4. print
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

Node* insert(Node* head, int val)
{
	//base case
	if(head == nullptr)
	{
		Node* temp = newNode(val);
		return temp;
	}

	//recursion until we find a leaf
	if(val < head->data)
		head->left = insert(head->left, val);
	else
		head->right = insert(head->right, val);
	//no use of next line, only to remove warning
	return head;
}

bool search(Node* head, int val)
{
	if(head == nullptr)
		return false;

	if(head->data == val)
		return true;

	if(val < head->data)
		return search(head->left,val);
	else
		return search(head->right,val);
}

Node* findMinInRightBranch(Node* head)
{
	while(head->left != nullptr)
		head = head->left;
	return head;
}

Node* deleteNode(Node* head, int val)
{
	if(head == nullptr)
		return head;

	//find the node
	if(val < head->data)
		head->left = deleteNode(head->left, val);
	else if (val > head->data)
		head->right = deleteNode(head->right, val);
	else if(val == head->data)	//found
	{
		//case1: no child
		if(head->left == nullptr && head->right == nullptr)
		{
			delete head;
			head = nullptr;
			return head;
		}

		//case3: 1 child (either left or right is null
		else if(head->left == nullptr || head->right == nullptr)
		{
			if(head->left == nullptr)
			{
				//make the node's right as the node itself
				Node* temp = head;
				head = head->right;
				delete temp;
				temp = nullptr;
				return head;
			}
			else if(head->right == nullptr)
			{
				//make the node's right as the node itself
				Node* temp = head;
				head = head->left;
				delete temp;
				temp = nullptr;
				return head;
			}
		}

		//case3: node to be deleted has both children
		//so find either min in right branch or max in left branch

		else
		{
			Node* temp = findMinInRightBranch(head->right);
			head->data = temp->data;
			deleteNode(head->right,temp->data);
		}
	}
	return head;	//to remove warning
}

void printInOrder(Node* head)
{
	if(head == nullptr)
		return;

	printInOrder(head->left);
	cout << head->data << " ";
	printInOrder(head->right);
}

int main()
{
	Node* head = newNode(5);
	insert(head,3);
	insert(head,7);
    insert(head, 2);
    insert(head, 4);
    insert(head, 1);
    insert(head, 6);
    insert(head, 8);

    //inorder will print ascending order
	printInOrder(head);

	if(search(head,6))
		cout << "\nFound" << endl;
	else
		cout << "\nNot found" << endl;

	deleteNode(head,6);
	printInOrder(head);

	printf("\nLa fin");
	return 0;
}
