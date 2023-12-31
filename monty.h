#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *value;

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of th stackor queue
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int);
} instruction_t;

void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
instruction_t *get_instructions();
void free_instructions(instruction_t *instructions);
void free_stack(stack_t **stack);
int is_int(char *str);
instruction_t *find(char *opcode, instruction_t *instructions);
char *my_strdup(const char *src);
void free_stack(stack_t **stack);
int is_int(char *str);
/**
 * instruction_t *find(char *opcode);
 */
int parse_instructions(stack_t **stack, char *lineread, unsigned int line, char *file);

#endif
