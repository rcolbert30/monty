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
	        {"swap", swap}, {"add", add}, {"sub", sub}, {NULL, NULL}
	};
	char *tok;

	for (toklenx = 0; input[toklenx] == '\n'; toklenx++)
		lnumx++;
	tok = strtok(ipt, "\n");
	while (tok)
	{
		for (i = 0; tok[i] == ' '; i++)
			;
		if (comment_check(&lnum, i, &tok))
			continue;
		for (toklen = i; tok[toklen] && tok[toklen] != ' '; toklen++)
			;
		gen->token = tokop_init(tok + i, toklen - i);
		if (!gen->token)
			return (0);
		for (j = 0; instarr[j].opcode; j++)
		{
			if (!strcmp(gen->token, "push"))
			{e
				for (; tok[toklen] && tok[toklen] == ' '; toklen++)
					;
				if (!tok[toklen])
					free_exit(*stack, lnum + lnumx, "L%u: usage: push integer\n");
				push_check(toklen, tok, *stack, lnum + lnumx);
				gen->input_int = ((gen->input_int * 10) + atoi(tok + toklen)); }
			if (!strcmp(gen->tokop, instarr[j].opcode))
				instarr[j].f(stack, lnum + lnumx), flag = 1; }
		if (instarr[j].opcode == NULL && !flag && *(gen->token))
			free_exit_ui(*stack, lnum + lnumx, "L%u: unknown instruction %s\n");
		lnumx += nl_count(tok),	tok = strtok(NULL, "\n"), gen->input_int = 0;
		lnum++, flag = 0, free(gen->token); }
	return (lnum + lnumx);
}

