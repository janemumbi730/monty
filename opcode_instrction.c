#include "monty.h"
/**
 *plus_nodeintend - adds note at end of link list
 *@h: first position of linked list
 *@n: parameter
 *Return: linked list
 */
stack_t *plus_nodeintend(stack_t **h, const int n)
{
	stack_t *t, *q;

if (h == NULL)
    return NULL;

t = malloc(sizeof(stack_t));
if (!t)
{
    fprintf(stderr, "Error: malloc failed\n");
    free_vrall();
    exit(EXIT_FAILURE);
}
t->n = n;

if (*h == NULL)
{
    t->next = *h;
    t->prev = NULL;
    *h = t;
    return *h;
}

q = *h;
while (q->next)
    q = q->next;

t->next = q->next;
t->prev = q;
q->next = t;
return q->next;
}

/**
 * op_concat - concatenate two strings
 * @x: number of elements
 * @y: type of elements
 * Return: void
 */
void *op_concat(unsigned int x, unsigned int y)
{
	void *b = NULL;
	unsigned int a;

	if (x == 0 || y == 0)
	{
		return (NULL);
	}
	b = malloc(x * y);
	if (b == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < (x * y); a++)
	{
		*((char *)(b) + a) = 0;
	}
	return (b);
}

/**
 * op_changer - change size and copy content
 * @pointer: pointer to reallocate
 * @past: old number of bytes
 * @present: new number of Bytes
 * Return: void
 */
void *op_changer(void *pointer, unsigned int past, unsigned int present)
{
	char *b = NULL;
	unsigned int a;

	if (present == past)
		return (pointer);
	if (pointer == NULL)
	{
		b = malloc(present);
		if (!b)
			return (NULL);
		return (b);
	}
	if (present == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	if (present > past)
	{
		b = malloc(present);
		if (!b)
			return (NULL);
		for (a = 0; a < past; a++)
			b[a] = *((char *)pointer + a);
		free(pointer);
	}
	else
	{
		b = malloc(present);
		if (!b)
			return (NULL);
		for (a = 0; a < present; a++)
			b[a] = *((char *)pointer + a);
		free(pointer);
	}
	return (b);
}

/**
 *plus_nodeint - add note at begining of link list
 *@h: first position
 *@n: parameter
 *Return: linked list
 */
stack_t *plus_nodeint(stack_t **h, const int n)
{
	stack_t *t;

	if (h == NULL)
		return (NULL);
	t = malloc(sizeof(stack_t));
	if (!t)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vrall();
		exit(EXIT_FAILURE);
	}
	t->n = n;

	if (*h == NULL)
	{
		t->next = *h;
		t->prev = NULL;
		*h = t;
		return (*h);
	}
	(*h)->prev = t;
	t->next = (*h);
	t->prev = NULL;
	*h = t;
	return (*h);
}

/**
 * op_freelist - frees the linked list
 * @h: head of list
 * Return: void
 */
void op_freelist(stack_t *h)
{
	stack_t *t;

	while ((t = h) != NULL)
	{
		h = h->next;
		free(t);
	}
}
