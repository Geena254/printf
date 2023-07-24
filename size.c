#include "main.h"

/**
 * print_size - function that calculates the size to cast to the argument
 * @j: the list of arguments to be printed
 * @format: the formatted string in which to print the arguments
 * Return: The size.
 */
int print_size(const char *format, int *j)
{
	int cur_i = *j + 1;
	int size = 0;

	if (format[cur_i] == 'l')
		size = S_LONG;
	else if (format[cur_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = cur_i - 1;
	else
		*j = cur_i;

	return (size);
}
