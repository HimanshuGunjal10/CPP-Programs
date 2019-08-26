#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
};

node* get_node(int value)
{
	node* temp = new node;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void insert(node* &head, int value)
{
	if(head == NULL)
	{
		head = get_node(value);
		return;
	}

	node* temp = get_node(value);

	node* curr = head;
	node *prev = head;

	while(curr!=nullptr && curr->value < value)
	{
		prev = curr;
		curr = curr->next;
	}

	//case1: new element is smaller than head

	if(curr == head)
	{
		temp->next = curr;
		head = temp;
	}

	//case2: new element is last element
	else if(curr == nullptr)
	{
		prev->next = temp;
	}

	//case3: anywhere in between head and last element
	else
	{
		prev->next = temp;
		temp->next = curr;
	}

}

void remove(node* &head, int value)
{
	if(head==NULL)
	{
		cout << "Empty list";
		return;
	}
	else
	{
		node* curr = head;
		node *prev = head;

		while(curr->value != value && curr!= NULL)
		{
			prev = curr;
			curr = curr->next;
		}

		//case 1: removing head
		if(curr == head)
		{
			head = curr->next;
			//delete curr;
			//curr = nullptr;
		}

		//case 2: Node not found
		else if(curr == nullptr)
		{
			cout << "Node not found!" << endl;
		}

		//case 3: removing any other node
		else
		{
			prev->next = curr->next;
			//delete curr;
			//curr = nullptr;
		}
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
