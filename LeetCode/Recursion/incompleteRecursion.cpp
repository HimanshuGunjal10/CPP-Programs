#include <iostream>
using namespace std;

class BST
{
public:
	int data;
	BST* left;
	BST* right;
	BST(int val) : data(val), left(nullptr), right(nullptr) {}
};

BST* insert(BST *head, int val)
{
	if(head == nullptr)
	{
		return new BST(val);
	}

	if(val <= head->data)
		head->left = insert(head->left,val);
	else
		head->right = insert(head->right,val);
	return head;

}

void printInOrder(BST *head)
{
	if(head == nullptr)
		return;
	printInOrder(head->left);
	cout << head->data << " ";
	printInOrder(head->right);
}

int findSum(BST* root, int L, int R, int sum)
{
	if(root == nullptr)
		return 0;
	findSum(root->left,L,R,sum);
	if(root &&root->data >= L && root->data <= R)
		return findSum(root,L,R,sum);
	findSum(root->right,L,R,sum);
}

int rangeSumBST(BST* root, int L, int R)
{
	return findSum(root,L,R,0);
}

int main()
{
	BST *head = new BST(5);
	insert(head,4);
	insert(head,2);
	insert(head,1);
	insert(head,7);
	insert(head,9);
	insert(head,3);

	printInOrder(head);
	cout << endl;

	cout << "Sum: " << rangeSumBST(head, 3,6) << endl;


	cout << endl << "La Fin!!";
}

