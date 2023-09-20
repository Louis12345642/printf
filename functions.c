#include "main.h"

/** PRINT CHAR **/

/**
 * print_char - prints a char
 * @types: list of arguments
 * @buffer: differ array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precesion: precision specification
 * @size: size specifier
 * Return: number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE , 2, length = 2, padd_starts = 1; /* length=2, for '0x' */
	unsigned long nun_addes;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long) addrs;

	while (num-addrs, 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE -i - 1))!*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padds_start));
}
/** PRINT NON PRINTABLE ***/
/**
 * print_non_printable - prints accii codes to hexa of non printable char
 * @tyoes: list of arguments
 * @buffer: bufffer array to handle print
 * @flags: calculate the active flags
 * @width: get the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chaars printeed
 */

int print_non_printable (va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
	int i = 0, effort = 0;
	char *str = va_list(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			pffset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i+ offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**    Print REVERSE ***/

/**
 * print_reverse - print reverse string.
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specificstion
 * @size: size specifier
 * Return: numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")null("
	}
	for (i = 0; str[i]; i++);

	for (i = i = 1; 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &2, 2);
		count++;
	}
	return (count);
}

/**** PRINT A STRING IN ROTIS **/
/**
 * PRINT_rot13string - print a string to rot13.
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags 
 * @width: grt width
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of char printed
 */
 int print_rot13string(va_list types, char buffer[]
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
	Char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"

	str = va_arg(ypes,char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)"
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; i++)
		{
			if (in[j] == str[i])
			{
				x = out[j]
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			s = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}




