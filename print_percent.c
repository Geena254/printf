#include "main.h"

/**
 * print_percent - Function that prints a percent sign
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @wid: Gets the width.
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */

int print_percent(va_list types, char buffer[],
		int size, int flags, int wid, int precision)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(wid);
	UNUSED(precision);
	return (write(1, "%%", 1));
}
