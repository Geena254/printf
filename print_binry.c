#include "main.h"

/**
 * print_binary -Function that prints an unsigned number
 * @types:A list of arguments
 * @buffer: The Buffer array to handle print
 * @flags: Calculates the active flags
 * @wid: Gets the width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
		int flags, int wid, int precision, int size)
{
	int cnt;
	unsigned int n[32];
	unsigned int a, b, l, add;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	n[0] = a / b;
	for (l = 1; l < 32; l++)
	{
		b /= 2;
		n[l] = (a / b) % 2;
	}
	for (l = 0, add = 0, cnt = 0; l < 32; l++)
	{
		add += n[l];
		if (add || l == 31)
		{
			char z = '0' + n[l];

			write(1, &z, 1);
			cnt++;
		}
	}
	return (cnt);
}
