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
			flags = print_flags(format, &j);
			width = print_width(format, &j, lst);
			precision = print_precision(format, &j, lst);
			size = print_size(format, &j);
			++j;
			printed = handl_print(format, &j, lst, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &indbuf);
	va_end(lst);

	return (printed_chars);
}

#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
