#include "monty.h"
/**
 * push - push element to stack
 * @stack: stack
 * @line_num: line num
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (atoi(store_var) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(store_var); /* store in a global varible */
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
 * @line_num: line num
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	if ((*stack) == NULL)
		return;
	while (tmp)
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
		fprintf(stderr, "L:%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	printf("%d\n", tmp->n);
}
/**
 * pop - pop top node in stack
 * @stack: stack
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}
