#include "monty.h"
/**
 * op_pop - gets rid of top element of stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *x;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_vrall();
        exit(EXIT_FAILURE);
    }

    x = *stack;
    *stack = (*stack)->next;
    free(x);
}
/**
 * op_nop - empty
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_sub - Prints the value at the top of the stack.
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
    int i = 0;
    stack_t *q = NULL;

    q = *stack;

    for (; q != NULL; q = q->next, i++)
        ;

    if (i < 2)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        free_vrall();
        exit(EXIT_FAILURE);
    }

    q = (*stack)->next;
    q->n -= (*stack)->n;
    op_pop(stack, line_number);
}
/**
 * op_add - adds two elements
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
    int u = 0;
    stack_t *q = NULL;

    q = *stack;

    for (; q != NULL; q = q->next, u++)
        ;

    if (u < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_vrall();
        exit(EXIT_FAILURE);
    }

    q = (*stack)->next;
    q->n += (*stack)->n;
    op_pop(stack, line_number);
}

/**
 * op_pint - prints value of stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_vrall();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
