#include "main.h"

/**
 * print_flags - function that calculates the active flags
 * @j: a parameter taken
 * @format: the formatted string in which to print the arguments
 * Return: the flags found
 */

int print_flags(const char *format, int *j)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, cur_i;
	int flgs = 0;
	const char FLAGS_CH[] = {'+', '0', '-', ' ', '#', '\0'};
	const int FLAGS_ARR[] = {F_PLUS, F_ZERO, F_MINUS, F_SPACE, F_HASH, 0};

	for (cur_i = *j + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[cur_i] == FLAGS_CH[a])
			{
				flgs |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*j = cur_i - 1;

	return (flgs);
}
