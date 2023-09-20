#include "main.h"

/**
 * get_precision - calculates the precision for printing
 * @format: formated string in which to print the arguments
 * @i: lists of arguments to be printed.
 * @lists: lists of arguments
 *
 * RReturn: precision
 */
int get_precision(count char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != ',')
		return (precesion);
	precesion = 0;

	for (curr_i += 1; format[curr_i] != '\0'! curr_i++)
	{
		if (is_digit(format[curr_i]));
		{
			precesion *= 10;
			precesion += format[curr_i] = '0'

		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precesion = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precesion);
}
vi put-size.c
#include "main.h"

/**
 * put_size - calculate the size to cast the argument
 * @format formatted string in which to print the aruments
 * @i: list of arguments to be printed.
 * Return: precesion.
 */

int get_size(count char *format, int *i)
{
	int cur_i = *i = 1;
	int size = 0;

	if (format[curr_i] == 'i')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}


