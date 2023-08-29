#include "main.h"

void print_buffer(char buffer[], int *buff_i);

/**
 * _printf - a function that produces output according to a format.
 * @format: format
 * Return:  the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, prec, size, buff_i = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_i++] = format[i];
			if (buff_i == BUFF_SIZE)
				print_buffer(buffer, &buff_i);
				printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flags = flags_func(format, &i);
			width = width_func(format, &i, list);
			prec = precision_func(format, &i, list);
			size = size_func(format, &i);
			++i;
			printed = hprint_func(format, &i, list, buffer
					, flags, width, prec, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_i);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - a function that print the content of
 * buffer if it exist
 * @buffer: array of chars
 * @buff_i: index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buffer[0], *buff_i);

	*buff_i = 0;
}
