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
*/

#include <iostream>
using namespace std;

struct node
{
	int value;
	node *next;
};

bool isEmpty(node *head)
{
	if(head == NULL)				//mistake of writing if(head->next ==NULL) : o/p terminated
		return true;
	else
		return false;
}

void insertAsFirstElement(node *&head, int number)
{
	node *temp = new node;
	temp->value = number;
	temp->next = NULL;
	head = temp;
	//cout << "head->next: " << head->next << endl;
}

void insert(node *&head, int number)
{
	if(isEmpty(head))					//1
		{
			insertAsFirstElement(head, number);	//and not (*head)	//2
		}
	else
	{
		node *temp = new node;
		node *prev = new node;
		node *curr = new node;

		curr = head;
		prev = NULL;

		while(curr != NULL)				//3
		{
			if(curr->value > number)	//4
			{
				break;
			}
			else
			{
				prev = curr;			//5
				curr = curr->next;
			}
		}
		if(curr==head)					//6
		{
			insertAsFirstElement(head,number);
		}
		else							//7
		{
			temp->value=number;
			temp->next = curr;
			prev->next = temp;
		}
	}
}

void showList(node *&head)
{
	if(isEmpty(head))
			cout << "Empty List" <<endl;
	else
		{
			node *current = new node;
			current = head;
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
			<< "3. Exit" << endl;
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
					insert(head,element);
					break;
			case 2: showList(head);
					break;
			case 3: cout <<"System exit!" << endl;
					break;
			default: cout << "Invalid input" << endl;
		}
	}while(choice!=3);

	return 0;
}
#endif


//OR

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
*/

#include <iostream>
using namespace std;

struct node
{
	int value;
	node *next;
};

node* getNewNode(node *head, int number)
{
	node *temp = new node;
	temp->value = number;
	temp->next = NULL;
	return temp;
}

node* insertAsFirstElement(node *head, int number)
{
	node *temp = new node;
	temp = getNewNode(head,number);
	return temp;
	//cout << "head->next: " << head->next << endl;
}

node* insert(node *head, int number)
{
	if(head == NULL)					//1
		head = insertAsFirstElement(head, number);	//and not (*head)	//2
	else
	{
		node *temp = new node;
		node *prev = new node;
		node *curr = new node;

		curr = head;
		prev = NULL;

		while(curr != NULL)				//3
		{
			if(curr->value >= number)	//4
				break;
			else
			{
				prev = curr;			//5
				curr = curr->next;
			}
		}
		if(curr==head)					//6
			insertAsFirstElement(head,number);
		else							//7
		{
			temp = getNewNode(head, number);
			temp->next = curr;
			prev->next = temp;
		}
	}
	return head;
}

void showList(node *head)
{
	if(head == NULL)
			cout << "Empty List" <<endl;
	else
		{
			node *current = new node;
			current = head;
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
			<< "3. Exit" << endl;
	int input;
	cin >> input;
	return input;
}

int main()
{
	node *head = new node;
	head = NULL;
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
					head = insert(head,element);
					break;
			case 2: showList(head);
					break;
			case 3: cout <<"System exit!" << endl;
					break;
			default: cout << "Invalid input" << endl;
		}
	}while(choice!=3);

	return 0;
}
#endif
