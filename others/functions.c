#include "monty.h"

/**
 * push - Function to push a new node to a stack
 */
void push()
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		new->n = value;
		new->next = NULL;
		stack = new;
	} else
	{
		new->n = value;
		new->next = stack;
		stack = new;
	}
}

/**
 * pop - Function to delete the top node
 */
void pop()
{
	int __attribute__((unused)) val;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	}
	val = stack->n;
	stack = stack->next;
}

/**
 * pall - Print all stack nodes
 */
void pall()
{
	stack_t *temp;

	temp = stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
	}
}

/**
 * pint - Print the top node of the stack
 */
void pint()
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}
