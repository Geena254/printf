#include "main.h"

/**
 * print_precision - function that calculates the precision for printing
 * @format: the formatted string in which to print the arguments
 * @j: The list of arguments to be printed.
 * @lst: a list of arguments.
 * Return: The precision.
 */
int print_precision(const char *format, int *j, va_list lst)
{
	int cur_i = *j + 1;
	int precision = -1;

	if (format[cur_i] != '.')
		return (precision);

	precision = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_dig(format[cur_i]))
		{
			precision *= 10;
			precision += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*j = cur_i - 1;

	return (precision);
}
