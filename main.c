#include "monty.h"

general_t *gen = NULL;

/**
 * main - entry point
 * @argc: count of arguments passed
 * @argv: argument vector
 * Return: 0
*/

int main(int argc, char *argv[])
{
	int file1, trl;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	gen = malloc(sizeof(general_t));
	if (gen == NULL)
	{
		close(file1);
				fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	gen->input = NULL;
	gen->token = NULL;
	gen->input_int = 0;
	gen->input = read_it(file1);
	trl = exe(gen->input, &stack);
	if (trl == 0)
	{
		free(gen->input);
		free_stack(stack);
		free(gen);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	close(file1);
	free_stack(stack);
	free(gen->input);
	free(gen);
	return(0);
}
