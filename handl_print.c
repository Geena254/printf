#include "main.h"
/**
 * handl_print - Function that prints an argument based on its type
 * @frmt: The formatted string in which to print the arguments.
 * @lst: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @wid: Gets the width.
 * @precision: the precision specification
 * @size: The size specifier
 * Return: 1 or 2;
 */
int handl_print(const char *frmt, int *ind, va_list lst, char buffer[],
	int flags, int wid, int precision, int size)
{
	int a, unknow_leng = 0, printd_chars = -1;
	frmt_t frmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_integer}, {'d', print_integer}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadeci},
		{'X', print_hexa_upper}, {'p', print_pter}, {'S', print_non_printble},
		{'r', print_reverse}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (a = 0; frmt_types[a].frmt != '\0'; a++)
		if (frmt[*ind] == frmt_types[a].frmt)
			return (frmt_types[a].func(lst, buffer, flags, wid, precision, size));

	if (frmt_types[a].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknow_leng += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknow_leng += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_leng += write(1, &frmt[*ind], 1);
		return (unknow_leng);
	}
	return (printd_chars);
}
