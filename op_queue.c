#include "monty.h"

/**
* m_queue - sets the format of the data to a queue (FIFO)
* @head: double pointer to first element of the queue
* @line_number: tracks instruction line read
*
* Return: void
* Description
* Set the flag variable in the global_vars to one,
* to indicate that the linked list should act as a queue.
*/
void m_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global.flag = 1;
}
