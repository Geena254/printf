#include "main.h"

/**
 * print_int - Function that prints an integer
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates the active flags
 * @wid: Gets the width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_int(va_list types, char buffer[],
		int flags, int wid, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int m = va_arg(types, long int);
	unsigned long int numb;

	m = convert_size_number(n, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)m;

	if (m < 0)
	{
		numb = (unsigned long int)((-1) * m);
		is_neg = 1;
	}

	while (numb > 0)
	{
		buffer[i--] = (num % 10) + '0';
		numb /= 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, wid, precision, size));
}
