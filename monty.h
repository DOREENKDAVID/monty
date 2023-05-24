#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_struct_s - hold common variables
 * @linenum: linenumber as integer
 * @line: pointer to string
 * @arglist: double pointer to list of line parsed
 */
typedef struct global_struct_s
{
	char *line;
	unsigned int linenum;
	char **arg_list;
} global_struct_t;

/* add_node.c and delete_node.c*/
size_t list_len(const stack_t *h);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_beg(stack_t **head, const int n);
stack_t *get_node_at_index(stack_t *head, unsigned int index);
stack_t *insert_node_at_index(stack_t **h, unsigned int idx, int n);
void delete_node_at_index(stack_t **head, unsigned int index);

/* op_functions */
void op_add(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **head, unsigned int line_number);
void free_stack_t(stack_t *head, char *line, FILE *fptr);

/*main function*/
void (*select_op_func(char *choice))(stack_t **head, unsigned int line_number)
#endif
