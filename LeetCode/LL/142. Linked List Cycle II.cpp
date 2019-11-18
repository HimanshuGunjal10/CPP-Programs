#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void create_List(ListNode* head)
{
	if(head == NULL)
		return;
}

ListNode *detectCycle(ListNode *head)
{
	if(head == NULL)
		return NULL;
	//the following will take care of a corner case
	//as wont enter while and fast == slow == head so issue
	if(head->next == NULL)
		return NULL;
	//step 1: detect a loop
	ListNode *slow = head;
	ListNode *fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
			break;
	}
	if(fast != slow)	//loop detected
	{
		cout << "No" << endl;
		return NULL;
	}
	else
	{
		cout << "Loop detected!!" << endl;
		//find the node
		slow = head;
		while(slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}


	return NULL;
}

void print_list(ListNode* head)
{
	ListNode* curr = head;
	while(curr)
	{
		cout << curr->val << "-";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* curr = head;
	int val = 2;
	ListNode* loop_Node = new ListNode(0);
	while(val<9)
	{
		curr->next = new ListNode(val++);
		curr = curr->next;
		if(val == 5)
			loop_Node = curr;
	}
	curr->next = loop_Node;
	//print_list(head);	//dont print as Loop made.

	ListNode* dummy = detectCycle(head);
	cout << dummy->val;


	cout << endl << "La Fin!!";
}

