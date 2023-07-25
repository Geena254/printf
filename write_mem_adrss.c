#include "main.h"

/**
 * write_pter - Function that writes a memory address
 * @buffer: An arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @leng: the length of number
 * @wid: The width specifier
 * @flags: The flags specifier
 * @padd: Character representing the padding
 * @extra_ch: Character representing extra char
 * @padd_begin: The index at which padding should start
 * Return: The number of written chars.
 */

int write_pter(char buffer[], int ind, int leng,
	int wid, int flags, char padd, char extra_ch, int padd_begin)
{
	int a;

	if (wid > leng)
	{
		for (a = 3; a < wid - leng + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[ind], leng) + write(1,
						&buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_ch)
				buffer[--ind] = extra_ch;
			return (write(1, &buffer[3], a - 3) + write(1,
						&buffer[ind], leng));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_ch)
				buffer[--padd_begin] = extra_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_begin], a - padd_begin) +
					write(1, &buffer[ind], leng - (1 - padd_begin) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
