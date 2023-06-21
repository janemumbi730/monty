#include "monty.h"

/**
 * op_pall - prints stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *q;
	(void)line_number;

	q = *stack;

	while (q)
	{
		printf("%d\n", q->n);
		q = q->next;
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
	int a, n;

	if (!vrall.args)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_vrall();
		exit(EXIT_FAILURE);
	}

	for (a = 0; vrall.args[a] != '\0'; a++)
	{
	if (!isdigit(vrall.args[a]) && vrall.args[a] != '-')
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_vrall();
		exit(EXIT_FAILURE);
	}
	}

		n = atoi(vrall.args);

	if (vrall.lifo == 1)
		plus_nodeint(stack, n);
	else
		plus_nodeintend(stack, n);
}
/**
 * op_swap - swaps two elements of stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int w = 0;
	stack_t *q = NULL;

	q = *stack;

	for (; q != NULL; q = q->next, w++)
	;

	if (w < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}

	q = *stack;
	*stack = (*stack)->next;
	q->next = (*stack)->next;
	q->prev = *stack;
	(*stack)->next = q;
	(*stack)->prev = NULL;
}

/**
 * op_queue - format of data to a queue
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	vrall.lifo = 0;
}

/**
 * op_stack - format of data to a stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	vrall.lifo = 1;
}
