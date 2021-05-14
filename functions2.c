#include "monty.h"
/**
 * nop - does nothing
 * @stack: voided
 * @line_num: voided
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
 * add - adds the top two elements of stack
 * @stack: stack head
 * @line_num: line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int add_elements;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	add_elements = tmp->n + tmp->next->n;
	tmp->next->n = add_elements;
	pop(stack, line_num);
}
/**
 * sub - substracts top element from de second top element
 * @stack: head of stack
 * @line_num: line number
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int sub_elements = 0;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub_elements = tmp->next->n - tmp->n;
	tmp->next->n = sub_elements;
	pop(stack, line_num);
}
/**
 * div - divides the second top element by the top element of stack
 * @stack: head of stack
 * @line_num: line number
 */
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int div_elements = 0;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	div_elements = tmp->next->n / tmp->n;
	tmp->next->n = div_elements;
	pop(stack, line_num);
}
/**
 * mul - multiplies the second top element by the top element
 * @stack: head of stack
 * @line_num: line number
 */
void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int mul_elements = 0;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	mul_elements = tmp->next->n * tmp->n;
	tmp->next->n = mul_elements;
	pop(stack, line_num);
}
