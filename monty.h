#ifndef _MONTY_H_
#define _MONTY_H_

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
 * struct overrall - the global structure
 * @h: linked list
 * @lifo: stack or queue
 * @fd: descriptor
 * @buf: input text
 * @cline: current line
 * @args: parameter
 */
typedef struct overrall
{
	stack_t *h;
	int lifo;
	FILE *fd;
	char *buf;
	unsigned int cline;
	char  *args;
} overrall_t;

extern overrall_t vrall;

/* functions.c */
void op_pop(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);

/* functions2 */
void op_push(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number)
void op_queue(stack_t **stack, unsigned int line_number)


#endif
