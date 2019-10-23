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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode* A = headA;
	ListNode* B = headB;
	ListNode* A_last = NULL;
	ListNode* B_last = NULL;
	ListNode* A_prev = NULL;
	ListNode* B_prev = NULL;
	bool flagA = true;
	bool flagB = true;

	if(!A || !B)
		return NULL;

	while(1)
	{
		if(A == B)
		{
			if(A_last == B_last)
				return A;
		}
		A_prev = A;
		B_prev = B;
		A = A->next;
		B = B->next;

		if(A == NULL)
		{
			if(flagA)
			{
				A_last = A_prev;
				A = headB;
				flagA = false;
			}
			else	//here the second time
			{
				return NULL;
			}
		}
		if(B == NULL)
		{
			if(flagB)
			{
				B_last = B_prev;
				B = headA;
				flagB = false;
			}
			else	//here the second time
			{
				return NULL;
			}
		}

	}
}

int main()
{
	int arr1[] = {1};
	int arr2[] = {2};

	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);

	ListNode* head1 = NULL;
	createListFromArray(arr1,size1,head1);
	printList(head1);

	ListNode* head2 = NULL;
	createListFromArray(arr2,size2,head2);
	printList(head2);

	ListNode* res = getIntersectionNode(head1,head2);
	if(res != NULL)
		cout << res->val;
	else
		cout << "Nope!" << endl;

	cout << endl << "La Fin!!";
}
