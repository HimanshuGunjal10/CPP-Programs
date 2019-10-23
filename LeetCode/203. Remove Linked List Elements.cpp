#include <iostream>
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

ListNode* removeElements(ListNode* head, int val)
{
	if(!head)
		return NULL;

	ListNode* curr = head;
	ListNode* runner = head->next;	//need to check if head was NULL

	while(runner)
	{
		if(runner->val == val)
		{
			while(runner && runner->val == val)
			{
				//delete here
				ListNode* temp = runner;
				runner = runner->next;
				delete(temp);
				temp = NULL;
			}
			if(runner == NULL)
				curr->next = NULL;
			else
			{
				curr->next = runner;
				curr = curr->next;
				//delete(runner);
				//need to check if current is now NULL or not(was last node)
				if(curr)
					runner = curr->next;
				else
					runner = NULL;
			}
		}
		else
		{
			curr = curr->next;
			runner = runner->next;
		}
	}
	//handle for only node as we started off checking with the second node
	if(head->val == val)
	{
		if(head->next)
			return head->next;
		else
			return NULL;
	}
	return head;
}

int main()
{
	int arr[] = {1,2,3,4,6,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	ListNode* head = NULL;
	createListFromArray(arr,size,head);
	printList(head);

	head = removeElements(head,6);
	printList(head);

	cout << endl << "La Fin!!";
}
