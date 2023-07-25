#include "main.h"

/* PRINT A POINTER */
/**
 * print_pointer - Function that prints the value of a pointer variable
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	char extra_ch = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, leng = 2, padd_begin = 1; /* length=2, for '0x' */
	unsigned long num_addrss;
	char mapto[] = "0123456789abcdef";
	void *addrss = va_arg(types, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addrss == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrss = (unsigned long)addrss;

	while (num_addrss > 0)
	{
		buffer[ind--] = mapto[num_addrss % 16];
		num_addrss /= 16;
		leng++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_ch = '+', leng++;
	else if (flags & F_SPACE)
		extra_ch = ' ', leng++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - a - 1));*/
	return (write_pointer(buffer, ind, leng,
		wid, flags, padd, extra_ch, padd_start));
}

/* PRINT NON PRINTABLE ASCII CODES */
/**
 * print_non_printble - Function that prints ascii codes
 * in hexa of non printable chars
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_non_printble(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	int a = 0, offset = 0;
	char *stri = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	if (stri == NULL)
		return (write(1, "(null)", 6));

	while (stri[a] != '\0')
	{
		if (is_printble(stri[a]))
			buffer[a + offset] = stri[a];
		else
			offset += append_hexa_code(stri[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}

/* PRINTS A STRING IN REVERSE */
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/* PRINT A STRING IN ROT13 */
/**
 * print_rot13str - Function that print a string in rot13.
 * @types: A list of arguments
 * @buffer: The buffer array to handle print
 * @flags: Calculates active flags
 * @wid: Gets the width
 * @precision: The precision specification
 * @size: The size specifier
 * Return: The numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int wid, int precision, int size)
{
	char y;
	char *stri;
	unsigned int a, b;
	int cnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	stri = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wid);
	UNUSED(precision);
	UNUSED(size);

	if (stri == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				y = out[b];
				write(1, &y, 1);
				cnt++;
				break;
			}
		}
		if (!in[b])
		{
			x = stri[a];
			write(1, &y, 1);
			cnt++;
		}
	}
	return (cnt);
}
