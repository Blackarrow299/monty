#include "monty.h"
#include <stdlib.h>
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
  

  if(_isnumber(tokens[1]) == 0) {
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }

	head->n = atoi(tokens[1]);
	head->next = *stack;
	head->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = head;
	*stack = head;
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
  (void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
