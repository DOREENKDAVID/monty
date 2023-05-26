#include "monty.h"


/**
* m_stack - sets the format of the data to a stack (LIFO)
* @head: double pointer to first element of the stack
* @line_number: tracts instruction line read
*
* Return: void
* Description
* Set the "flag" variable in the global_vars to 0,
* to  indicate that the linked list should act as a stack.
*/
void m_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global.flag = 0;
}

/**
* m_queue - sets the format of the data to a queue (FIFO)
* @head: double pointer to first element of the queue
* @line_number: tracks instruction line read
*
* Return: void
* Description
* Set the "flag" variable in the global_vars to 1,
* to indicate that the linked list should act as a queue.
*/
void m_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global.flag = 1;
}
