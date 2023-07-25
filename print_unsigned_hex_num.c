#include "main.h"

/**
 * print_hexadeci - Function that prints an unsigned number in hexadecimal
 * @types: The list of arguments
 * @buffer: The buffer array to handle print
 * @flags:  Calculates the active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_hexadeci(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', wid, precision, size));
}

/* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - Function that prints an unsigned number in upper
 * hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', wid, precision, size));
}

/* PRINT HEXX NUM IN LOWER OR UPPER */
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @mapto: An array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @wid: Gets the width
 * @precision: Precision specification
 * @size: The size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char mapto[], char buffer[],
	int flags, char flag_ch, int wid, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = conv_siz_unsignd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = mapto[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (writ_unsgnd(0, j, buffer, flags, wid, precision, size));
}
