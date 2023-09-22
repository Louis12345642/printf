#include "main.h"

/**********print the pointer***************/
/**
 * print_char - prrint chars here
 * @types: show the parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: finds width
 * @precision: get the Precision specification
 * @size: find Size 
 * Return: Number of characters pointers
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char add_c = 0, p = ' ';
	int i = BUFF_SIZE - 2, len = 2, start = 1; /* length=2, for '0x' */
	unsigned long n_adress;
	char map[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	n_adress = (unsigned long)address;

	while (n_adress > 0)
	{
		buffer[i--] = map[n_adress % 16];
		n_adress /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (flags & F_PLUS)
		add_c = '+', len++;
	else if (flags & F_SPACE)
		add_c = ' ', len++;

	i++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, i, len,
		width, flags, p, add_c, start));
}

/*******************print non printable**************/
/**
 * print_char - prrint chars assic
 * @types: show the parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: finds width
 * @precision: get the Precision specification
 * @size: find Size 
 * Return: Number of characters prints
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, off = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[j] != '\0')
	{
		if (is_printable(s[j]))
			buffer[j + off] = s[j];
		else
			off += append_hexa_code(s[j], buffer, j + off);

		j++;
	}

	buffer[j + off] = '\0';

	return (write(1, buffer, j + off));
}

/********print in reverse************/
/**
 * print_char - print reverse chars
 * @types: show the parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: finds width
 * @precision: get the Precision specification
 * @size: find Size 
 * Return: Number of characters prints
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int i, total = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = s[i];

		write(1, &z, 1);
		total++;
	}
	return (total);
}
/**************print the string in rot13**************/
/**
 * print_char - print in rot13
 * @types: show the parameters
 * @buffer: they take care of print
 * @flags:  finds flags
 * @width: finds width
 * @precision: get the Precision specification
 * @size: find Size 
 * Return: Number of characters prints
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char g;
	char *s;
	unsigned int i, j;
	int total = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == s[i])
			{
				g = out[j];
				write(1, &g, 1);
				total++;
				break;
			}
		}
		if (!in[j])
		{
			g = s[i];
			write(1, &g, 1);
			total++;
		}
	}
	return (total);
}

