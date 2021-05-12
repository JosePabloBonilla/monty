#include "monty.h"
/**
 * main - opens monty interface
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success, 1 for failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
