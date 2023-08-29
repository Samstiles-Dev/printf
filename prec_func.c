#include "main.h"
/**
 * prec_func - a function that calculate the
 * the precision for printing
 * @format: formatted string in which to
 * print the arguments
 * @i: pointer integer parameter
 * @list: pointer argument variable
 * Return: precision
 */
int prec_func(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int prec = -1;

	if (format[curr_i] != '.')
		return (prec);

	prec = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			prec *= 10;
			prec += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (prec);
}
