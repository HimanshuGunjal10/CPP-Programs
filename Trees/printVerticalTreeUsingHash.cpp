/*
 * TREE + HASH Table
 * print a tree vertically
 *
 */

#include <iostream>
#include<map>
#include<vector>
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

void getVertical(Node* root, map<int,vector<int>> &mymap, int count)	//Note: pass mymap as & else no output
{
	//base case
	if(root == nullptr)
		return;

	mymap[count].push_back(root->data);

	getVertical(root->left, mymap,count-1);
	getVertical(root->right,mymap,count+1);
}

/*
	pre-order traversal to store in a hash map and print vertically
	not a recursive function
	create the map and counter and then pass it to a recursive in order traversal function to do the insertion
	 return here and print the map's contents to get the tree in a vertical order
*/
void printVertical(Node* root)
{
	if(root == nullptr)
		return;

	map<int,vector<int>> mymap;
	int count = 0;

	getVertical(root,mymap,count);	//push the nodes' data into the hash map

	//print it
	map<int,vector<int>> :: iterator it;

	for(it = mymap.begin(); it!= mymap.end(); it++)
	{
		for(unsigned int i=0; i<it->second.size(); i++)
			cout << it->second[i] << " ";
		cout << endl;
	}
}

int main()
{

    Node* root 		  = newNode(6);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(3);
    root->left->right = newNode(1);
    root->right->right = newNode(12);
    root->right->left = newNode(7);

    //inorder will print ascending order
	printInOrder(root);
	cout << endl;

	printVertical(root);


	printf("\nLa fin");
	return 0;
}
