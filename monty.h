#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

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
	char *line_ptr;
	int flag;

} global_t;
extern global_t global;


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
stack_t *add_node_at_index(stack_t **head, unsigned int index, int n);
void delete_node_at_index(stack_t **head, unsigned int index);

/* op_functions */
void m_add(stack_t **head, unsigned int line_number);
void m_pint(stack_t **head, unsigned int line_number);
void m_nop(stack_t **head, unsigned int line_number);
void m_pop(stack_t **head, unsigned int line_number);
void m_push(stack_t **head, unsigned int line_number);
void m_pall(stack_t **head, unsigned int line_number);
void m_swap(stack_t **head, unsigned int line_number);
void m_div(stack_t **head, unsigned int line_number);
void m_mul(stack_t **head, unsigned int line_number);
void m_sub(stack_t **head, unsigned int line_number);
void m_mod(stack_t **head, unsigned int line_number);
/*op_pstr.c*/
void m_pstr(stack_t **head, unsigned int line_number);
/*op_pchar.c*/
void m_pchar(stack_t **head, unsigned int line_number);
/*op_rotl.c*/
void m_rotl(stack_t **head, unsigned int line_number);
/*op_rotr.c*/
void m_rotr(stack_t **head, unsigned int line_number);
/*op_stack.c*/
void m_stack(stack_t **head, unsigned int line_number);
/*op_queue.c*/
void m_queue(stack_t **head, unsigned int line_number);
/* free.c*/
void free_stack(stack_t *head);

/*check_mode*/
int parse(char *line_ptr, stack_t **head, unsigned int line_number,
		FILE *fptr);
/*is_digit.c */
int is_digit(char c);
/*read_line.c*/
int main(int argc, char *argv[]);
#endif
