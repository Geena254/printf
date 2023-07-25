#include "main.h"

/**
 * print_integer - Function that prints an integer
 * @types: Lista of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates the active flags
 * @wid: Gets the width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_integer(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int numb;

	m = conv_siz_num(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)m;

	if (m < 0)
	{
		numb = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flags, wid, precision, size));
}
