#include "main.h"

/**** This function prints characters ********/

/**
 * print_char - prrint chars here
 * @types: show the parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: finds width
 * @precision: get the Precision specification
 * @size: find Size 
 * Return: Number of characters prints
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char k = va_arg(types, int);

	return (handle_write_char(k, buffer, flags, width, precision, size));
}
/**********This functon print the strings****************/
/**
 * print_string - this print the string
 * @types: group of parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: get the width.
 * @precision: get accuracy
 * @size: Size finder
 * Return: nmber of printed chararters
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, h;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (h = width - len; h > 0; h--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (h = width - len; h > 0; h--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}

	return (write(1, s, len));
}
/**********prints the percentage here*******/
/**
 * print_percent - Prints a percent sign
 * @types: show parameters
 * @buffer: array of charaters
 * @flags:  get the flags
 * @width: find the width.
 * @precision: find the precisionr
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/********prints any integer****************/
/**
 * print_int - Print int
 * @types: show parameters
 * @buffer: array of charaters
 * @flags:  get the flags
 * @width: find the width.
 * @precision: find the precisionr
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int negative = 0;
	long int a = va_arg(types, long int);
	unsigned long int num;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_number(negative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: show parameters
 * @buffer: array of charaters
 * @flags:  get the flags
 * @width: find the width.
 * @precision: find the precisionr
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int g, t, l, add;
	unsigned int a[32];
	int total;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	g = va_arg(types, unsigned int);
	t = 2147483648; /* (2 ^ 31) */
	a[0] = g / t;
	for (l = 1; l < 32; l++)
	{
		t /= 2;
		a[l] = (g / t) % 2;
	}
	for (l = 0, add = 0, total = 0; l < 32; l++)
	{
		add += a[l];
		if (add || l == 31)
		{
			char z = '0' + a[l];

			write(1, &z, 1);
			total++;
		}
	}
	return (total);
}

