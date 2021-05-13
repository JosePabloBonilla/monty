#include "monty.h"
/**
 * push - push element to stack
 * @stack: stack
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;
	(void)line_num;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints all the values in the stack
 * @stack: stack
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - print the value at the top of the stack
 * @stack: stack
 * @line_num: line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		printf("%d: this stack is empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	printf("%d\n", tmp->n);
}
