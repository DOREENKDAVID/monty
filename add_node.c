#include "monty.h"


/**
* add_node_beg - func adds node at the beginning of the list
* @head: double pointer to the nodes in the list
* @n: data to fill into new node
i*
* Return: new node added
*/

stack_t *add_node_beg(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL || head == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}
/**
* add_node_end - func adds new node at end of linked list
* @head: double pointer to nodes in the list
* @n: data to new node
*
* Return: new node on success or NULL on failure
*/

stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (head == NULL || new_node == NULL)
		return (NULL);

	temp = *head;

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}

/**
* add_node_at_index -adds a new node in list at position index
* @head: double pointer to nodes in the list
* @index: index to insert node at
* @n: data to  new node
*
* Return: new node at postion on success, NULL on failure
*/

stack_t *add_node_at_index(stack_t **head, unsigned int index, int n)
{
	unsigned int i;
	stack_t *temp = NULL;
	stack_t *new_node = NULL;

	temp = *head;

	if (index == 0)
		return (add_node_beg(head, n));

	for (i = 0; temp->next && i <= index; i++)
	{
		if (i == index - 1)
		{
			if (temp->next == NULL)
				return (add_node_end(head, n));
			new_node = malloc(sizeof(stack_t));
			if (new_node == NULL)
				return (NULL);
			new_node->n = n;
			new_node->next = NULL;
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->prev->next = new_node;
			temp->next = new_node;
			return (new_node);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
* get_node_at_index -func returns nth node of the list
* @head: pointer to the nodes of the list
* @index: position of node in list
*
* Return: head at position of index
*/

stack_t *get_node_at_index(stack_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (i = 0; i < index; i++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
