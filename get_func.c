#include "monty.h"

/**
 * get_func - checks for opcode functions and returns
 * them if they exist
 * @token: opcode
 * @line: line
 * Return: function or NULL
 */

void (*get_func(char *token))
{
	int i;

	instruction_t opcodes[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			/*{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},*/
			{"NULL, NULL"}
	};
	
	i = 0;
	while (opcodes[i].f != NULL)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
