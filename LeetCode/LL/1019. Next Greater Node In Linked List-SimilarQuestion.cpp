#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void createListFromArray(int arr[], int size, ListNode* &head)
{
	for(int i=0; i<size; i++)
	{
		if(head==NULL)
			head = new ListNode(arr[i]);
		else
		{
			ListNode* curr = head;
			while(curr->next)
				curr = curr->next;
			curr->next = new ListNode(arr[i]);
		}
	}
}

void printList(ListNode* head)
{
	while(head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

vector<int> nextLargerNodes(ListNode* head)
{
	if(!head)
		return {0};
	if(head->next == NULL)
		return {head->val};

	ListNode* head_ref = head;

	vector<int> vec;

	deque<int> dq;
	dq.push_front(head->val);
	head = head->next;

	while(head)
	{
		if(head->val > dq.front())
		{
			dq.pop_front();
			dq.push_front(head->val);
		}
		else	//<= both taken here so best
		{
			while(dq.back() < head->val)
				dq.pop_back();
			dq.push_back(head->val);	//will push if equal
		}
		head = head->next;
	}
	//step2 filling the vector
	head = head_ref;
	while(head)
	{
		if(dq.empty())
			vec.push_back(0);
		else
		{
			if(head->val == dq.front())
			{
				vec.push_back(0);
				dq.pop_front();
			}
			else
				vec.push_back(dq.front());
		}
		head = head->next;
	}
	return vec;
}

int main()
{
	int arr[] = {1,3,7,5,4,9};
	int size = sizeof(arr)/sizeof(arr[0]);

	ListNode* head = NULL;
	createListFromArray(arr,size,head);
	printList(head);

	vector<int> vec = nextLargerNodes(head);

	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;


	cout << endl << "La Fin!!";
}
