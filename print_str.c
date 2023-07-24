#include "main.h"

/**
 * print_str - Function that prints a string
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates the active flags
 * @wid: Gets the width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_string(va_list types, char buffer[],
		int flags, int wid, int precision, int size)
{
	int len = 0, i;
	char *stri = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);
	if (stri == NULL)
	{
		stri = "(null)";
		if (precision >= 6)
			stri = "      ";
	}

	while (stri[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (wid > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &stri[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &stri[0], len);
			return (wid);
		}
	}

	return (write(1, stri, len));
}
