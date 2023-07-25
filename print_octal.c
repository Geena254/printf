#include "main.h"

/**
 * print_octal - Function that prints an unsigned number in octal notation
 * @types: The list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: Number of chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{

	int h = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[h--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[h--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[h--] = '0';

	h++;

	return (write_unsgnd(0, h, buffer, flags, wid, precision, size));
}
