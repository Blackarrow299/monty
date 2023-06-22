#include "monty.h"
/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int _isnumber(char *str)
{
    if (str == NULL || *str == '\0') {
        return (0);
    }

    if (*str == '+' || *str == '-') {
        str++;
    }

    while (*str != '\0') {
        if (!isdigit(*str)) {
            return (0);
        }   
        str++;
    }

    return (1);
}
