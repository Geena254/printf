#include "main.h"

/**
 * print_buffer - function that prints the contents of the buffer if it exist
 * @indbuf: the index for buffer
 * @buffer: an array of chars
 */
void print_buffer(char buffer[], int *indbuf)
{
	if (*indbuf > 0)
		write(1, &buffer[0], *indbuf);

	*indbuf = 0;
}

/**
 * _printf - the Printf function
 * @format: a character string composed of zero or more directives
 * Return: the printed characters
 */
int _printf(const char *format, ...)
{
	int flags, width, precision, size, indbuf = 0;
	int j, printed = 0, printed_chars = 0;
	char buffer[BUFF_SIZE];
	va_list lst;

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[indbuf++] = format[j];
			if (indbuf == BUFF_SIZE)
				print_buffer(buffer, &indbuf);
			/* write(1, &format[j], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &indbuf);
			flags = get_flags(format, &j);
			width = get_width(format, &j, lst);
			precision = get_precision(format, &j, lst);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, lst, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &indbuf);
	va_end(list);

	return (printed_chars);
}
