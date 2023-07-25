#include "main.h"

/* WRITE HANDLE */
/**
 * handl_writ_char - Function that prints a string
 * @a: character types.
 * @buffer: The buffer array to handle print
 * @size: Gets the size specifier
 * @flags:  Calculates active flags.
 * @width: calculates the width.
 * @precision: calculates the precision specifier
 * Return: The number of characters printed.
 */

int handl_writ_char(char a, char buffer[],
	int flags, int width, int precision, int size)
{
	char padd = ' ';
	int j = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[j++] = a;
	buffer[j] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/* WRITE NUMBER */
/**
 * write_number - function that prints a string
 * @is_neg: the list of arguments
 * @ind: character types.
 * @buffer: The buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: Calculates the width.
 * @precision: Gets the precision specifier
 * @size: Gets the size specifier
 * Return: The number of characters printed.
 */
int write_number(int is_neg, int ind, char buffer[],
	int flags, int wid, int precision, int size)
{
	int leng = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, wid, precision,
		leng, padd, extra_ch));
}

/**
 * write_num - function that writes a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: the buffer
 * @flags: the Flags
 * @wid: the width
 * @precision: the Precision specifier
 * @leng: the number length
 * @padd: the Pading character
 * @extra_ch: The extra character
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int wid, int precision,
	int leng, char padd, char extra_ch)
{
	int a, padd_begin = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && wid == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > leng)
		buffer[--ind] = '0', leng++;
	if (extra_ch != 0)
		leng++;
	if (wid > leng)
	{
		for (a = 1; a < wid - leng + 1; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Assigns extra char to left of buffer */
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[ind], leng) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[ind], leng));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_begin] = extra_ch;
			return (write(1, &buffer[padd_begin], i - padd_begin) +
				write(1, &buffer[ind], leng - (1 - padd_begin)));
		}
	}
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], leng));
}

/**
 * write_unsgnd - Function that writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @wid: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int ind,
	char buffer[],
	int flags, int wid, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position a */
	int len = BUFF_SIZE - ind - 1, a = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no charcter is printed */

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (wid > len)
	{
		for (a = 0; a < wid - len; a++)
			buffer[i] = padd;

		buffer[a] = '\0';

		if (flags & F_MINUS) /* Assign extra character to left of [buffer>padd]*/
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], a));
		}
		else /* Assign extra character to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[ind], len));
		}
	}
	return (write(1, &buffer[ind], len));
}
