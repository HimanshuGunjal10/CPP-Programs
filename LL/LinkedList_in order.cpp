#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
};

node* insertAsFirstElement(node* head, int value)
{
	node* temp = new node;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void insert(node* &head, int value)
{
	if(head == NULL)
		head = insertAsFirstElement(head, value);
	else
	{
		node* temp = new node;
		temp->value = value;
		temp->next = NULL;

		node* curr = new node;
		node *prev = new node;
		curr = head;
//		while(curr->next!=NULL)
//			curr = curr->next;
//		curr->next = temp;
		///
		while(curr->value < value && curr->next!= NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		if(curr == head)
			curr->next = temp;
		else if (curr->next == NULL)
		{
			if(curr->value < value)
				curr->next = temp;
			else
			{
				prev->next = temp;
				temp->next = curr;
			}
		}
		else
		{
			temp->next = curr;
			prev->next = temp;

		}
	}
}

void remove(node* head, int value)
{
	if(head==NULL)
	{
		cout << "Empty list";
		return;
	}
	else
	{
		node* curr = new node;
		node *prev = new node;			// try malloc
		curr = head;
		while(curr->value != value && curr->next!= NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		if(curr->next == NULL)
		{
			if(curr->value != value)
			{
				cout << "Element not found\n";
				return;
			}
			else
			{
				prev->next = NULL;
				//delete curr;			//this gives issues.
			}
		}
		prev->next = curr->next;
		//delete curr;
	}
	return;
}

void display_list(node* head)
{
	if(head == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	node* curr = new node;
	curr = head;
	while(curr != NULL)
	{
		cout << curr->value << " ";
		curr = curr->next;
	}
}

int menu()
{
	int in;
	cout << "\n-------\n"
			"Enter a selection: \n"
			"1. Insert in order \n"
			"2. Remove \n"
			"3. Display \n"
			"4. Exit \n";
	cin >> in;
	return in;
}

int main()
{
	node* head = new node;
	head = NULL;
	int selection;
	int element;
	do
	{
		selection = menu();
		switch(selection)
		{
		case 1:
			cout << "Insert an element: ";
			cin >> element;
			insert(head, element);
			break;
		case 2:
			cout << "Remove which element?: ";
			cin >> element;
			remove(head, element);
			break;
		case 3:
			display_list(head);
			break;
		case 4:
			cout << "System Exit \n";
			break;
		default:
			cout<< "Enter a valid selection\n";
		}
	}while(selection!=4);

	return 0;
}
