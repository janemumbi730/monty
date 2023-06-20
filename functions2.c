#include "monty.h"

/**
 * op_pall - prints stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *x = *stack;

	(void)line_number;

	while (x != NULL)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}

/**
 * op_push - pushes stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *x;
  
	x = malloc(sizeof(stack_t));
	if (x == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	x->n = line_number;
	x->prev = NULL;
	x->next = NULL;

	if (*stack != NULL)
		(*stack)->prev = x;
	x->next = *stack;
	*stack = x;
}

/**
 * op_swap - swaps two elements of stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *up;
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	up = *stack;
	next = (*stack)->next;

	up->prev = next;
	up->next = next->next;

	up->prev = NULL;
	up->next = up;

	if (up->next != NULL)
		up->next->prev = up;

	*stack = next;
}
