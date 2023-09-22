#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - this is the entry point print
 * @format: it is used for formatting.
 * Return: numbers of Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, p = 0, p_chars = 0;
	int flg, width, accuracy, s, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flg = get_flags(format, &a);
			width = get_width(format, &a, list);
			accuracy = get_precision(format, &a, list);
			s = get_size(format, &a);
			++a;
			p = handle_print(format, &a, list, buffer,
				flg, width, accuracy, s);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (p_chars);
}

/**
 * print_buffer - it findes the buffers and prints it
 * @buffer: buffer is character array
 * @buff_ind: this is the starting index of adding a character.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

