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
	void insertAsFirstElement(node *&head, int number);
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

void node::insertAsFirstElement(node *&head, int number)
{
	node *temp = new node;
	temp->value = number;
	temp->next = NULL;
	head = temp;
	//cout << "head->next: " << head->next << endl;
}

void node::push(node *&head, int number)
{
	if(isEmpty(head))
		{
			insertAsFirstElement(head, number);	//and not (*head)
		}
	else
	{
		node *curr = new node;
		curr = head;
		while(curr->next != NULL)	//while(curr!=NULL) ...terminates
		{
			curr = curr->next;
		}
		if(curr == head)
		{
			node *temp = new node;
			temp->value = number;
			temp->next = NULL;
			head->next = temp;
		}
		else
		{
			node *temp = new node;
			temp->value = number;
			temp->next = NULL;
			curr->next = temp;
		}

	}
}

int node::pop(node *&head)
{
	//if(isEmpty(head))
	node *curr = new node;
	node *prev = new node;
	int pop_value;
	curr = head;
	while(curr->next!=NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if(curr == head)
	{
		cout << "List got empty!! " ;
		pop_value = curr->value;
		head = NULL;
	}
	else
	{
		pop_value = curr->value;
		delete curr;
		prev->next = NULL;
	}
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
