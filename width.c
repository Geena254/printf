#include "main.h"

/**
 * print_width - function that calculates the width for printing
 * @format: the formatted string in which to print the arguments
 * @lst: A list of arguments
 * @j: The list of arguments to be printed
 * Return: The width.
 */
int print_width(const char *format, int *j, va_list lst)
{
	int cur_i;
	int width = 0;

	for (cur_i = *j + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_dig(format[cur_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*j = cur_i - 1;

	return (width);
}
