#include "main.h"

/**
 * print_char -Function that prints a character
 * @types: A list a of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of characters printed
 */

int print_char(va_list types, char buffer[],
		int flags, int wid, int precision, int size)
{
	char c = va_arg(types, int);

	return (handl_writ_char(c, buffer, flags, wid, precision, size));
}
