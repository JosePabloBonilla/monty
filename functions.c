#include "monty.h"
/**
 * push - push element to stack
 * @stack: stack
 */
void push(stack_t **stack)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: unable to find memory\n");
		exit(EXIT_FAILURE);
	}
	new->n = store_var; /* store in a global varible */
	new->prev = NULL;

	if (*stack == NULL) /* stack = head of stack */
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new-next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints all the values in the stack
 * @stack: stack
 */
void pall(stack_t **stack)
{
	stack_t *tmp = *stack;

	if ((*stack) == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
