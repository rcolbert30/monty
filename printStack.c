#include "monty.h"

/**
 * print_stack - prints all elements of a stack
 * @h: head pointer
 * Return: number of nodes
*/
size_t print_stack(const stack_t *h)
{
	int i;

	if (h == NULL)
		return (0);
	for (i = 0; h; i++, h = h->next)
		printf("%d\n", h->n);
	return (i);
}
