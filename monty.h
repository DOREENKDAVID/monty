#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#define DELIMS "\n\t\r"

/**
 * struct global_s - variables -args, file, line content
 * @arg: pointer to tekenized line
 * @fptr: pointer to monty file
 * @line_ptr: line content
 * @flag: change stack <-> queue
 */
typedef struct global_s
{
	char *arg;
	FILE *fptr;
	char *lne_ptr;
	int flag;
	stack_t *head;
	unsigned int num;

}  global_t;
extern global_t global_s;


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
void op_swap(stack_t **head, unsigned int line_number);
void free_all(stack_t *head);

/*main function*/
void tokenizer(stack_t **head,char * choice,  unsigned int line_number);
/*is_digit.c */
int is_digit(char c);
/*read_line.c*/
void read_line(char *n, stack_t **head);
#endif
