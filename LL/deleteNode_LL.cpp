// Implementation in C

#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};


void deleteNode (struct Node** head_ref, int position)
{
	if(*head_ref == NULL)
	{
		printf("Empty list\n");
		return;
	}
	//store head node
	struct Node* temp = *head_ref;

	//if head needs to be removed
	if(position == 0)
	{
		*head_ref = temp->next;
		free(temp);					//free old head
		return;
	}

	//Find previous node to be deleted
	for(int i=0; temp!=NULL && i< position-1; i++)
		temp = temp->next;

	//If position is more than number of nodes
	if(temp == NULL || temp->next == NULL)
	{
		printf("Position out of bound\n");
		return;
	}

	//Node temp->next is the node to be deleted
	struct Node* next_one = temp->next->next;	//so that you don't loose the node
	
	free(temp->next);	//first free that node
	temp->next = next_one;	//then assign the next node to create back the link
}


int main()
{

	return 0;
}