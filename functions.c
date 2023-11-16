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
	if (top == NULL)
	{
		new->n = value;
		new->next = NULL;
		top = new;
	} else
	{
		new->n = value;
		new->next = top;
		top = new;
	}
}

/**
 * pop - Function to delete the top node
 */
void pop()
{
	int __attribute__((unused)) val;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	}
	val = top->n;
	top = top->next;
}

/**
 * pall - Print all stack nodes
 */
void pall()
{
	stack_t *temp;

	temp = top;
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
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
