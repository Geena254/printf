#include "main.h"

/**
 * print_unsigned - Function that prints an unsigned number
 * @types: the list a of arguments
 * @buffer: The buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed.
 */

int print_unsigned(va_list types, char buffer[]
	int flags, int wid, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = conv_siz_unsignd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, wid, precision, size));
}
