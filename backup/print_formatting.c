#include "main.h"

int print_formatted_int(strQ *fmt_buffer, va_list va)
{
	int i;
	char negative = 0, *str = (fmt_buffer->front);

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
}
int print_formatted_double(strQ *fmt_buffer, va_list va)
{
	/* TO DO */
}
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
}
int print_formatted_char(strQ *fmt_buffer, va_list va)
{
	char str[1];

	if (*(fmt_buffer->front) == 'c')
	{
		str[0] = (char) va_arg(va, int);
		return write(1, str, 1);
	}
}
