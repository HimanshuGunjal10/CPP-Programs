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

ListNode* oddEvenList(ListNode* head)
{

	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;

	ListNode *odd = head, *even=head->next, *evenHead=even;

	while(even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;


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
	while(val<9)
	{
		curr->next = new ListNode(val++);
		curr = curr->next;
	}

	print_list(head);

	head = oddEvenList(head);
	print_list(head);

	cout << endl << "La Fin!!";
}

