#include "monty.h"
/**
 * op_rotate - rotates the first elements
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_rotate(stack_t **stack, unsigned int line_number)
{
	stack_t *q1 = NULL;
	stack_t *q2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	q1 = (*stack)->next;
	q2 = *stack;

	for (; q2->next != NULL; q2 = q2->next)
		;

	q1->prev = NULL;
	q2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = q2;
	*stack = q1;
}

/**
 * op_mode - computes the rest of the div
 * by the top element of the stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_mode(stack_t **stack, unsigned int line_number)
{
    int w = 0;
    stack_t *q = NULL;

    q = *stack;

    for (; q != NULL; q = q->next, w++)
        ;

    if (w < 2)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_vrall();
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free_vrall();
        exit(EXIT_FAILURE);
    }

    q = (*stack)->next;
    q->n %= (*stack)->n;
    op_pop(stack, line_number);
}
/**
 * op_printchar - prints the char of first element
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_printchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * op_printstr - prints string
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_printstr(stack_t **stack, unsigned int line_number)
{
	stack_t *q;
	(void)line_number;

	q = *stack;

	while (q && q->n > 0 && q->n < 128)
	{
		printf("%c", q->n);
		q = q->next;
	}

	printf("\n");
}

/**
 * op_reverse - reverses the stack
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void op_reverse(stack_t **stack, unsigned int line_number)
{
	stack_t *q = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	q = *stack;

	for (; q->next != NULL; q = q->next)
		;

	q->prev->next = NULL;
	q->next = *stack;
	q->prev = NULL;
	(*stack)->prev = q;
	*stack = q;
}
