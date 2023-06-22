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

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 * _pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * _swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int tmp;

	current = *stack;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}

