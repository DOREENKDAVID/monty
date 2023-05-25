/**
* free_ all - free all elements in the list
* @head: pointer to nodes in the list
* @line: pointer to string
* @fptr: file pointer
*/

void free_all(stack_t **head)
{
	if (**head == NULL)
	{
		free_all(&(*head)->next);
		free(*head);
		*head = NULL;
	}
	fclose(fptr);
}
