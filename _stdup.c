#include "monty.h"
/**
 * _stdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the newly allocated duplicated string,
 *         or NULL if memory allocation fails.
 */
char *_stdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *copy = malloc(len * sizeof(char));

	if (copy != NULL)
	{
		memcpy(copy, str, len);
	}

	return copy;
}
