#include "main.h"

/**
 * get_flags - get all the flags of the print
 * @format: use for formate string
 * @i: take augment.
 * Return: flag:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, c_index;
	int flags = 0;
	const char F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_index = *i + 1; format[c_index] != '\0'; c_index++)
	{
		for (k = 0; F_CH[k] != '\0'; k++)
			if (format[c_index] == F_CH[k])
			{
				flags |= F_ARR[k];
				break;
			}

		if (F_CH[k] == 0)
			break;
	}

	*i = c_index - 1;

	return (flags);
}

