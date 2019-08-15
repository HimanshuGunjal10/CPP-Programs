
#include<stdio.h>
#include<stdlib.h>
//using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int value)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;

	if(*head_ref == NULL)
	{
		*head_ref = temp;
		return;
	}
	struct Node* curr = (*head_ref);
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = temp;
}

void print(struct Node* head_ref)
{
	if(head_ref == NULL)
	{
		printf("Empty list\n");
		return;
	}
	while (head_ref != NULL)
	{
		printf("%d ",head_ref->data);
		head_ref = head_ref->next;
	}
	printf("\n");
}

void swap(struct Node** head_ref, int x, int y)
{
	//case 0:
	if (x==y)
		return;

	//case1: if list is empty
	if(*head_ref == NULL)
	{
		printf("Empty list\n");
		return;
	}

	//run through to find x while storing prev pointer
	struct Node* prevX = NULL;
	struct Node* currX = *head_ref;
	while(currX->data != x && currX != NULL)
	{
		prevX = currX;
		currX = currX->next;
	}

	//run through to find y while storing prev pointer
	struct Node* prevY = NULL;
	struct Node* currY = *head_ref;
	while(currY->data != y && currY != NULL)
	{
		prevY = currY;
		currY = currY->next;
	}

	//case2: check if either of x or y dont exist, then exit
	if(currX == NULL || currY == NULL)
	{
		printf("Either of x or y not found\n");
		return;
	}

	//check if either x or y is head node before changing the pointers
	if(prevX == NULL)
		*head_ref = currY;
	else
		prevX->next = currY;

	if(prevY == NULL)
		*head_ref = currX;
	else
		prevY->next = currX;

	//swap x and y
	struct Node* temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
}

int main()
{
	struct Node* head = NULL;
	push(&head,5);
	push(&head,7);
	push(&head,9);
	push(&head,11);

	print(head);

	swap(&head,7,9);

	print(head);

	printf("La Fin");

	return 0;
}
