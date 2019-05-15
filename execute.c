#include "monty.h"

/**
 * exe - tokenize input string and select operation to perform
 * @input: input string
 * @stack: pointer to a pointer to the stack
 * Return: 1 for success, 0 for failure
 */
int exe(char *input, stack_t **stack)
{
	unsigned int toklen = 0, i, j = 0, lnum = 1, flag = 0, lnumx = 0, toklenx = 0;
	instruction_t instarr[] = {
		{"push", push}, {"pall", pall},	{"pint", pint}, {"pop", pop},
	        {"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	char *tok;

	for (toklenx = 0; input[toklenx] == '\n'; toklenx++)
		lnumx++;
	tok = strtok(input, "\n");
	while (tok)
	{
		for (i = 0; tok[i] == ' '; i++)
			;
		for (toklen = i; tok[toklen] && tok[toklen] != ' '; toklen++)
			;
		gen->token = tokop_init(tok + i, toklen - i);
		if (!gen->token)
			return (0);
		for (j = 0; instarr[j].opcode; j++)
		{
			if (!strcmp(gen->token, "push"))
			{
				for (; tok[toklen] && tok[toklen] == ' '; toklen++)
					;
				if (!tok[toklen])
					free_exit(*stack, lnum + lnumx, "L%u: usage: push integer\n");
				gen->input_int = ((gen->input_int * 10) + atoi(tok + toklen)); }
			if (!strcmp(gen->token, instarr[j].opcode))
				instarr[j].f(stack, lnum + lnumx), flag = 1; }
		if (instarr[j].opcode == NULL && !flag && *(gen->token))
			free_exit_2(*stack, lnum + lnumx, "L%u: unknown instruction %s\n");
		lnumx += nl_count(tok),	tok = strtok(NULL, "\n"), gen->input_int = 0;
		lnum++, flag = 0, free(gen->token); }
	return (lnum + lnumx);
}

/**
 * free_exit - exits with message
 * @stack: a pointer to the stack
 * @lnum: line number
 * @mssg: message to be printed to stderr
 * Return: none
 */
void free_exit(stack_t *stack, unsigned int lnum, char *mssg)
{
	fprintf(stderr, mssg, lnum);
	free(gen->input);
	free(gen->token);
	free(gen);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_exit_2 - exits with message and opcode
 * @stack: a pointer to the stack
 * @lnum: line number
 * @mssg: message to be printed to stderr
 * Return: none
 */
void free_exit_2(stack_t *stack, unsigned int lnum, char *mssg)
{
	fprintf(stderr, mssg, lnum, gen->token);
	free(gen->input);
	free(gen->token);
	free(gen);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * tokop_init - initializes tokop pointer with copied memory
 * @tok: pointer to the start of opcode
 * @tok_abs: the length of the token minus the number of spaces
 * Return: pointer to new buffer
 */
char *tokop_init(char *tok, int tok_abs)
{
	char *result;

	result = malloc(sizeof(char) * (tok_abs + 1));
	if (result == NULL)
		return (NULL);
	result = memset(result, 0, (tok_abs + 1));
	result = strncpy(result, tok, tok_abs);
	return (result);
}

/**
 * nl_count - counts new lines
 * @tok: pointer to the newlines
 * Return: number of new lines
 */
int nl_count(char *tok)
{
	int toklenx, i, lnumx = 0;

	for (toklenx = 0; tok[toklenx]; toklenx++)
		;
	for (i = 1; tok[toklenx + i] == '\n'; i++)
		lnumx++;
	return (lnumx);
}

