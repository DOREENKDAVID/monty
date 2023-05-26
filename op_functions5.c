/**
* m_rotl - rotate the stack to the top
* @head: double pointer to first element of the stack
* @line_number: tracks instruction line read
*
* Return: void
* Description:
* Check if the stack is empty
* Get the first node
* Store the value of the first node.
* Delete the first node
* Add a new node at the end of the stack with data value
*
*/
void m_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int data = 0;

	(void)line_number;
	if (!*head == NULL)
		return;
	temp = get_node_at_index(*head, 0);
	data = temp->n;
	delete_node_at_index(head, 0);
	add_node_end(head, data);
}

/**
* m_rotr - rotate the stack to the bottom
* @head: pointer to first element of the stack
* @line_number: tracks instruction line read
*
* Return: void
* Description:
* size - Variable to store the length of the stack
* check if the stack is empty
* Get the last node
* Store the value of the last node
* Delete the last node
* Add a new node at the end of the stack
*/
void m_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int data = 0;

	max = list_len(*head);

	(void)line_number;
	if (*head == NULL)
		return;
	temp = get_node_at_index(*head, max - 1);
	data = temp->n;
	delete_node_at_index(head, max - 1);
	add_node_end(head, data);
}
