#ifndef _MONTY_H
#define _MONTY_H
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct general - input, tokenize
 * @input: takes in file info
 * @input_int: push integer when called
 * @token: tokenize the opcode
 */
typedef struct general
{
	char *input;
	int input_int;
	char *token;
} general_t;

/*global variable*/
extern general_t *gen;

/** helper functions */
size_t print_stack(const stack_t *h);
char *tokop_init(char *tok, int tok_abs);
char *read_it(int fd);
int nl_count(char *tok);

/**execute functions */
int exe(char *input, stack_t **stack);

/**free functions*/
void free_exit(stack_t *stack, unsigned int lnum, char *mssg);
void free_exit_2(stack_t *stack, unsigned int lnum, char *mssg);
void free_stack(stack_t *head);

/**opcode functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
#endif
