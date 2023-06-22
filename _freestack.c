#include "monty.h"

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
