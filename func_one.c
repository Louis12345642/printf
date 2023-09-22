#include "main.h"

/*******here we print unisgn numbers******/
/**
 * print_unsigned - print the an unsigned num
 * @types: Lshow the list of parameters
 * @buffer: character arrays
 * @flags:  finds the flags
 * @width: calculate width
 * @precision: get accuracy
 * @size: calculate the size
 * Return: characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[j--] = (n % 10) + '0';
		n /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/********this function print octal numbers******/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: show the list of parameters
 * @buffer: character arrays
 * @flags:  finds the flags
 * @width: calculate width
 * @precision: get accuracy
 * @size: calculate the size
 * Return: characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int number = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[k--] = (n % 8) + '0';
		n /= 8;
	}

	if (flags & F_HASH && number != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/*******print hexadecimal numbers*********/
/**
 * print_hexadecimal - find a hexadecimal numbers and prints
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  finds the flags
 * @width: calculate width
 * @precision: get accuracy
 * @size: calculate the size
 * Return: characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/******* print unsign numbers of hexadecima in uppercase***********/
/**
 * print_hexa_upper - print the unsigns hexadecimal
 * @types: show the list of parameters
 * @buffer: character arrays
 * @flags:  finds the flags
 * @width: calculate width
 * @precision: get accuracy
 * @size: calculate the size
 * Return: characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*******print hex in lower or uppcases****/
/**
 * print_hexa - print both lower and upper hexadecimals
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: character arrays
 * @flags:  finds the flags
 * @flag_ch: Calculates active flags
 * @width: calculate width
 * @precision: get accuracy
 * @size: calculate the size
 * @size: Size  calculation
 * Return: characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int i_num = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[m--] = map_to[n % 16];
		n /= 16;
	}

	if (flags & F_HASH && i_num != 0)
	{
		buffer[m--] = flag_ch;
		buffer[m--] = '0';
	}

	m++;

	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}

