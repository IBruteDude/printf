#include "main.h"

/**
 * print_formatted_int - Prints a formatted integer to standard output
 * @fmt_buffer: Pointer to a buffer containing the format string
 * @va: A va_list of arguments for the format string
 * Return: The number of characters written to standard output.
 */

int print_formatted_int(strQ *fmt_buffer, va_list va)
{
	int i;
	UV char negative = 0, *str = (fmt_buffer->front);

	if (*str == 'd' || *str == 'i')
	{
		i = va_arg(va, int);
		str = int_to_str((i > INT32_MIN) ? abs(i) : INT32_MIN, 10, fmt_buffer);
		if (i < 0)
			str[0] = '-';
		else
			strcpy(str, str + 1);
		return (write(1, str, _strlen(str)));
	}
	return (0);
}

/**
 * print_formatted_double - Print formatted double-prec number to stdoutput
 * @fmt_buffer: Pointer to a buffer containing format string
 * @va: A va_list of arguments for format string
 *
 * Return: The number of characters written to standard output.
 */

int print_formatted_double(UV strQ *fmt_buffer, UV va_list va)
{
	/* TO DO */
	return (0);
}

/**
 * print_formatted_string - Prints a formatted string to stdout
 * @fmt_buffer: Pointer to buffer containing format string
 * @va: A va_list of arguments for format string
 * Return: The number of characters written to standard output.
 */

int print_formatted_string(strQ *fmt_buffer, va_list va)
{
	char *str;

	if (*(fmt_buffer->front) == 's')
	{
		str = (char *) va_arg(va, char *);
		if (str)
			return (write(1, str, _strlen(str)));
		else
			return (write(1, "(null)", 6));
	}
	return (0);
}

/**
 * print_formatted_char - Prints a formatted character to standard output
 * @fmt_buffer: Pointer to a buffer containing the format string
 * @va: A va_list of arguments for the format string
 * Return: The number of characters written to standard output (always 1).
 */

int print_formatted_char(strQ *fmt_buffer, va_list va)
{
	char str[1];

	if (*(fmt_buffer->front) == 'c')
	{
		str[0] = (char) va_arg(va, int);
		return (write(1, str, 1));
	}
	return (0);
}
