#include "main.h"

/**
 * get_precision - get the accuracy
 * @format: Formatted strings
 * @i: list the parametre.
 * @list: show parameters.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c = *i + 1;
	int precision = -1;

	if (format[c] != '.')
		return (precision);

	precision = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			precision *= 10;
			precision += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (precision);
}

