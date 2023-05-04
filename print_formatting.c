#include "main.h"

/**
 * memcpy - set first n bytes of n to b
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to be copied
 * Return: output string
 */
char *memcpy(char *dest, char *src, unsigned int n)
{
	while (n--)
		dest[n] = src[n];
	return (dest);
}

/**
 * print_formatted_int - Prints a formatted integer to standard output
 * @fmt_buffer: Pointer to a buffer containing the format string
 * @va: Address va_list of arguments for the format string
 * Return: The number of characters written to standard output.
 */
int print_formatted_int(strQ *fmt_buffer, va_list *va)
{
	int i, written = 0;
	char *str;

	i = va_arg(*va, int);
	switch (*(fmt_buffer->back - 1))
	{
	case 'd': case 'i': case 'u':
	{
		str = int_to_str(i, 10, fmt_buffer);
		if (i >= 0)
			strcpy(str, str + 1);
		written = write(1, str, strlen(str));
		break;
	}
	case 'b':
		str = int_to_str(i, 2, fmt_buffer);
		written = write(1, str + 1, strlen(str + 1));
		break;
	case 'o':
		str = int_to_str(i, 8, fmt_buffer);
		written = write(1, str + 1, strlen(str + 1));
		break;
	case 'X': case 'x':
	{
		str = int_to_str(i, 16, fmt_buffer);
		if (*str == 'x')
			str = str_tolower(str);
		written = write(1, str + 1, strlen(str + 1));
		break;
	}
	}
	if (written)
		free(str);
	return (written);
}

/**
 * print_formatted_double - Print formatted double-prec number to stdoutput
 * @fmt_buffer: Pointer to a buffer containing format string
 * @va: Address va_list of arguments for format string
 *
 * Return: The number of characters written to standard output.
 */
int print_formatted_double(UV strQ *fmt_buffer, UV va_list *va)
{
	/* TO DO */
	return (0);
}

/**
 * print_formatted_string - Prints a formatted string to stdout
 * @fmt_buffer: Pointer to buffer containing format string
 * @va: Address va_list of arguments for format string
 * Return: The number of characters written to standard output.
 */
int print_formatted_string(strQ *fmt_buffer, va_list *va)
{
	char c, *str;

	if (fmt_buffer == NULL || fmt_buffer->front == NULL)
		return (-1);

	str = (char *) va_arg(*va, char *);
	c = *(fmt_buffer->front);
	if (c == 's')
	{
		if (str)
			return (write(1, str, strlen(str)));
		else
			return (write(1, "(null)", 6));
	}
	else
	{
		str = interpret_spec(str, fmt_buffer);
		return (write(1, str, strlen(str)));
	}
	return (0);
}

/**
 * print_formatted_char - Prints a formatted character to standard output
 * @fmt_buffer: Pointer to a buffer containing the format string
 * @va: Address va_list of arguments for the format string
 * Return: The number of characters written to standard output (always 1).
 */
int print_formatted_char(strQ *fmt_buffer, va_list *va)
{
	char str[23], *num, chr[1];
	uint64_t written = 0, ptr, *ptr_p;

	ptr_p = &ptr;
	if (*(fmt_buffer->back - 1) == 'c')
	{
		chr[0] = (char) va_arg(*va, int);
		written = write(1, chr, 1);
	}
	else if (*(fmt_buffer->back - 1) == 'p')
	{
		void *p = va_arg(*va, void *);

		memcpy((char *)ptr_p, (char *) &p, 8);
		num = str_tolower(int_to_str(ptr, 16, strQ_init("")));
		if (ptr != 0)
		{
			str[0] = '0', str[1] = 'x';
			memcpy(str + 2, num + 2, strlen(num + 2) + 1);
			written = write(1, str, strlen(str));
		}
		else
		{
			written = write(1, "(null)", 6);
		}
	}
	free(num);
	return (written);
}
