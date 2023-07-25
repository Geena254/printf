#include "main.h"

/**
 * is_printable - function that evaluates if a character is printable
 * @b: the character to be checked
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char b)
{
	if (b >= 32 && b < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - function that appends ASCII in hexadecimal code to buffer
 * @asc_cod: ASCII CODE.
 * @buffer: an array of characters
 * @j: Index at which to start appending.
 * Return: Always 3
 */
int append_hexa_code(char asc_cod, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asc_cod < 0)
		asc_cod *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[asc_cod / 16];
	buffer[j] = map_to[asc_cod % 16];

	return (3);
}

/**
 * is_dig - function that verifies if a character is a digit
 * @a: the character to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_dig(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

/**
 * conv_siz_num - function that casts a number to the specified size
 * @num: Number to be casted.
 * @siz: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int conv_siz_num(long int num, int siz)
{
	if (siz == S_LNG)
		return (num);
	else if (siz == S_SHRT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_siz_unsignd - Casts a number to the specified size
 * @num: the number to be casted
 * @siz: the number indicating the type to be casted
 * Return: Casted value of num
 */
long int conv_siz_unsignd(unsigned long int num, int siz)
{
	if (siz == S_LNG)
		return (num);
	else if (siz == S_SHRT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
