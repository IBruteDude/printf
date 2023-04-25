#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int printed = 0;
	int flags, width, precision, size;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			/* Handle %% */
			if (*format == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				/* write(1, "%", 1); */
				printed_chars++;
			}

			/* Handle %c */

			else if (*format == 'c')
			{
				char c = (char)va_arg(list, int);

				buffer[buff_ind++] = c;

				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				/* write(1, &c, 1); */
				printed_chars++;
			}

			/* Handle %s*/

			else if (*format == 's')
			{
				char *str = va_arg(list, char*);

				while (*str)
				{
					buffer[buff_ind++] = *str++;
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);

					/* write(1, str, 1);*/

					printed_chars++;
				}
			}
		}
		else
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			/* write(1, format, 1); */
			printed_chars++;
		}

		format++;
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, buffer, *buff_ind);

	*buff_ind = 0;
}
