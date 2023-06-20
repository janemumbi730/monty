#include "monty.h"
/**
 * op_pop - gets rid of top element of stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	t = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(t);
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
	int x;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->next->n - (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n = x;
}

/**
 * op_add - adds two elements
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *up;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	up = *stack;
	next = (*stack)->next;

	next->n += up->n;

	*stack = next;
	(*stack)->prev = NULL;
	free(up);
}

/**
 * handle_pint - Prints the value at the top of the stack.
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
