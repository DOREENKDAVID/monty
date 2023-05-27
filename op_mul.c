#include "monty.h"

/**
 * m_mul - find product of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read instructions
 *
 * Return: new node with product
 * Description:
 * Check if the doubly linked list has at least two nodes
 * Get the first two nodes of the doubly linked list
 * Calculat the product of the values of the first two nodes
 * Delet the first two nodes from the doubly linked list
 * Add a new node with the product as its value at the beginning
 * Handle the case of memory allocation failure
*/
void m_mul(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *node_0 = NULL, *node_1 = NULL;
	int mul = 0;

	if (list_len(*head) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		fclose(global.fptr);
		free(global.line_ptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node_0 = get_node_at_index(*head, 0);
	node_1 = get_node_at_index(*head, 1);

	mul = node_0->n * node_1->n;
	delete_node_at_index(head, 0);
	delete_node_at_index(head, 0);

	new_node =  add_node_beg(head, mul);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed%u",
				line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
}

