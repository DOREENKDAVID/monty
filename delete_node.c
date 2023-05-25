#include "monty.h"
/**
 * delete_node_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 *
 * Return: 1 on success, -1 on failure
 */

void delete_node_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *curr = NULL;
	stack_t *temp = NULL;

	if (!*head || !head)
		return;

	temp = *head;

	if (index == 0)
	{
		(*head)->prev = NULL;
		*head = (*head)->next;
		free(temp);
		return;
	}
	for (i = 0; i < index - 1; i++)
		temp = temp->next;

	curr = temp->next;
	temp->next = curr->next;
	curr->next->prev = temp;
	free(curr);

}

/**
* list_len - func returns length of the linked list
* @h: pointer to the nodes of the list
*
* Return: number of nodes
*/

size_t list_len(const stack_t *h)
{
	stack_t *temp = (stack_t *) h;
	int i;

	for (i = 0; temp != NULL; i++)
		temp = temp->next;
	
	return (i);

}
