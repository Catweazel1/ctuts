#include <stdio.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

typedef void(*callback)(node *number);

node *head = NULL;

node *create(int number, node *next);
node *prepend(node *head, int number);
void traverse(node *head, callback f);
node *append(node *head, int number);
node *insert_after(node *head, int number, node *prev);
node *insert_before(node *head, int number, node *nxt);

int main(void)
{

}

node *create(int number, node *next)
{
	node *new_node = malloc(sizeof(node));
	if(new_node == NULL)
	{
		printf("Error creating a new node.\n");
		return 1;
	}
	new_node->number = number;
	new_node->next = next;

	return new_node;
}

node *prepend(node *head, int number)
{
	node *new_node = create(number, head);
	head = new_node;
	return head;
}

void traverse(node *head, callback f)
{
	node *cursor = head;
	while(cursor != NULL)
	{
		f(cursor);
		cursor = cursor->next;
	}
}

node *append(node *head, int number)
{
	// go to the last node
	node *cursor = head;
	while(cursor->next != NULL)
	{
		cursor->next;
	}

	// create a new node
	node *new_node = create(number, NULL);
	cursor->next = new_node;

	return head;
}

node *insert_after(node *head, int number, node *prev)
{
	// find the prev node, starting from the first node
	node *cursor = head;
	while(cursor != prev)
	{
		cursor = cursor->;
	}

	if(cursor != NULL)
	{
		node *new_node = create(number, cursor->next);
		cursor->next = new_node;
		return head;
	}
	else
	{
		return NULL;
	}
}

node *insert_before(node *head, int number, node *nxt)
{
	if(nxt == NULL || head == NULL)
	{
		return NULL;
	}

	if(head == nxt)
	{
		head = prepend(head, number);
		return head;
	}

	// find the prev node, starting from the first node
	node *cursor = head;
	while( cursor != NULL)
}