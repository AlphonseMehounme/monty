#include "monty.h"

/**
 * push - add element to the stack
 * @stack: the stack to work on
 * @value: number to add
 * @line: number of line
 */

void push(stack_t **stack, unsigned int line)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - print all nodes
 * @stack: stack to print
 * @line: line number
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack;

	(void)line;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
