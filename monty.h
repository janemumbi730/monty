#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
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

/* functions2.c */
void op_push(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);

/* function3.c */
void op_rotate(stack_t **stack, unsigned int line_number);
void op_mode(stack_t **stack, unsigned int line_number);
void op_printchar(stack_t **stack, unsigned int line_number);
void op_printstr(stack_t **stack, unsigned int line_number);
void op_reverse(stack_t **stack, unsigned int line_number);

/* function4.c */
int my_compstr(char *str1, char *str2);
void op_divide(stack_t **stack, unsigned int line_number);
void op_multiply(stack_t **stack, unsigned int line_number);
int my_search(char *str, char c);
char *my_strtok(char *str, char *dell);

/* retriver.c */
void (*retrive_ops(char *ops))(stack_t **stack, unsigned int line_number);

/* opcode_instrction.c */
stack_t *plus_nodeintend(stack_t **h, const int n);
void *op_concat(unsigned int x, unsigned int y);
void *op_changer(void *pointer, unsigned int past, unsigned int present);
stack_t *plus_nodeint(stack_t **h, const int n);
void op_freelist(stack_t *h);

/*main.c*/
void free_vrall(void);

#endif
