#include "monty.h"
/**
 * mod - computes rest of the division of
 * the second top element by the top element
 * @stack: head of stack
 * @line_num: line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int mod_elements = 0;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	mod_elements = tmp->next->n % tmp->n;
	tmp->next->n = mod_elements;
	pop(stack, line_num);
}
