#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: number of characters printed chars.
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p_chars = 0;
	int fs, w, accuracy, s, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL){
		return (-1);
	}
	else{


	va_start(list, format);
	}
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
	
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			fs = get_flags(format, &i);
			w = get_w(format, &i, list);
			accuracy = get_accuracy(format, &i, list);
			s = get_s(format, &i);
			++i;
			p = make_print(format, &i, list, buffer,
				fs, w, accuracy, Size);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}

	get_buffer(buffer, &buffer_index);

	va_end(list);

	return (p_chars);
}

/*
 * print the content of the bufer using the get_buffer
 * */

void get_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
