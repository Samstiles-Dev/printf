#include "main.h"
/**
 * size_func - a function that calculate the
 * size to cast the argument
 * @format: formatted string
 * @i: argument list to be printed
 * Return: precision
 */
int size_func(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == '1')
		size = S_LONG;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
