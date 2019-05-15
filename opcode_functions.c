#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free(gen->input);
		exit(EXIT_FAILURE);
	}
	newNode->n = gen->input_int;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * pall - pushes an element onto the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}

