#if 1

/*
https://www.youtube.com/watch?v=ktjKKcgdh1I
Steps:
1. empty list
2. insert head
3. while(curr!=0)
4. if >/< // find location
5. else prev pointer
6. if(curr==head)
7.else after head

Note: No need to pass head to each function.
Use the "this" pointer and make calls head->isEmpty(), head->insert(int num) etc
*/

#include <iostream>
using namespace std;

class node
{
public:
	bool isEmpty(node *head);
	node* get_node(int number);
	void push(node *&head, int number);
	int pop(node *&head);
	void showList();

private:
	int value;
	node *next;
};

bool node::isEmpty(node *head)
{
	if(head == NULL)				//mistake of writing if(head->next ==NULL) : o/p terminated
		return true;
	else
		return false;
}

node* node::get_node(int number)
{
	node *temp = new node;
	temp->value = number;
	temp->next = NULL;
	return temp;
	//cout << "head->next: " << head->next << endl;
}

void node::push(node *&head, int number)
{
	if(isEmpty(head))
		{
			head = get_node(number);
		}
	else
	{
		node *curr = head;
		while(curr->next != NULL)	//while(curr!=NULL) ...terminates
		{
			curr = curr->next;
		}

		node *temp = get_node(number);
		curr->next = temp;
	}
}

int node::pop(node *&head)
{
	if(head == nullptr)
	{
		cout << "Empty list" << endl;
		return INT_MIN;
	}
	int pop_value = head->value;
	//to delete node
	node* temp = head;	//now temp points to where head points to now
	head = head->next;
	delete temp;
	temp = nullptr;

	return pop_value;
}


//previous implementation
//void node::showList(node *&head) ... does not use this pointer
void node::showList()
{
	if(isEmpty(this))		//	if(isEmpty(head))
			cout << "Empty List" <<endl;
	else
		{
			node *current = new node;
			current = this;	//	current = head;
			cout << "List: \t ";
			while(current != NULL)
			{
				cout << current->value << "\t";
				//cout << "current->next" << current->next <<endl;
				current = current->next;
			}
			cout << endl;
		}
}

int menu()
{
	cout << "1. Add an element" << endl
			<< "2. Display List" << endl
			<< "3. Pop" << endl
			<< "4. Exit" << endl;
	int input;
	cin >> input;
	return input;
}

int main()
{
	node *head = nullptr;
	int choice = 0;
	int element = 0;
	do
	{
		cout << "Make a selection: " << endl;
		choice = menu();
		switch (choice)
		{
			case 1:	cout << "Insert an element" << endl;
					cin >> element;
					head->push(head,element);
					break;
			case 2: head->showList();
					break;
			case 3: cout << "Pop: " << head->pop(head) << endl;
					break;
			case 4: cout <<"System exit!" << endl;
					break;
			default: cout << "Invalid input" << endl;
		}
	}while(choice!=4);

	return 0;
}
#endif
