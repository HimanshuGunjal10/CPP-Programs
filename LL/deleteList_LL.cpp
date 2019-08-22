
class Node
{
public:
	int data;
	Node* next;
};

void delete_List (Node** head_ref)
{
	Node* current = *head_ref;
	Node* next;

	while(current!=NULL)
	{
		next = current->next;
		free (current);		//imp
		current = next;
	}
	//after all nodes are deleted, derefeence the head
	*head_ref = NULL;
}