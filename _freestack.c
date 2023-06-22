#include "monty.h"

/**
 * _freestack - Frees the memory allocated for the stack.
 * @stack: Double pointer to the stack.
 */
void _freestack(stack_t **stack)
{
    stack_t *currentNode = *stack;
    stack_t *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    *stack = NULL;
}

