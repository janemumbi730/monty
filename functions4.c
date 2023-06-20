#include "monty.h"
/**
 * my_compstr - compares two strings
 * @str1: string 1 to be compared
 * @str2: string 2 to be compared with
 * Return: 0 
 */
int my_compstr(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a] == str2[a] && str1[a]; a++)
		;
	if (str1[a] > str2[a])
		return (1);
	if (str1[a] < str2[a])
		return (-1);
	return (0);
}

/**
 * op_divide - divides the second element by the top element of the stack
 * @stack: head of linked list
 * @line_number: line number
 * Return: void
 */
void op_divide(stack_t **stack, unsigned int line_number)
{
	int w = 0;
	stack_t *q = NULL;

	aux = *stack;

	for (; q != NULL; q = q->next, w++)
		;

	if (w < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}

	q = (*stack)->next;
	q->n /= (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_multiply - multiplies element
 * @stack: head of linked list
 * @line_number: line number
 * Return: void
 */
void op_multiply(stack_t **stack, unsigned int line_number)
{
	int w = 0;
	stack_t *q = NULL;

	q = *stack;

	for (; q != NULL; q = q->next, w++)
		;

	if (w < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_vrall();
		exit(EXIT_FAILURE);
	}

	q = (*stack)->next;
	q->n *= (*stack)->n;
	op_pop(stack, line_number);
}
/**
 * my_search - reviews if char is inside string
 * @str: string to be reviewed
 * @c: character to be found
 * Return: 1 or 0
 */
int my_search(char *str, char c)
{
	int cline = 0;

	while (str[cline] != '\0')
	{
		if (str[cline] == c)
		{
			break;
		}
		cline++;
	}
	if (str[cline] == c)
		return (1);
	else
		return (0);
}

/**
 * my_strtok - cuts string into token
 * @str: string
 * @dell: delimeter
 * Return: first partition
 */
char *my_strtok(char *str, char *dell)
{
	static char *x;
	int a = 0, b = 0;

	if (!str)
		str = x;
	while (str[a] != '\0')
	{
		if (my_search(dell, str[a]) == 0 && str[a + 1] == '\0')
		{
			x = str + a + 1;
			*x = '\0';
			str = str + b;
			return (str);
		}
		else if (my_search(dell, str[a]) == 0 && my_search(dell, str[a + 1]) == 0)
			a++;
		else if (my_search(dell, str[a]) == 0 && my_search(dell, str[a + 1]) == 1)
		{
			x = str + a + 1;
			*x = '\0';
			x++;
			str = str + b;
			return (str);
		}
		else if (my_search(dell, str[a]) == 1)
		{
			b++;
			a++;
		}
	}
	return (NULL);
}
