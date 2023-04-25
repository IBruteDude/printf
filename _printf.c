#include "main.h"

/**
 * check_optional_fields - checks for valid optional fields and flags
 * @buffer: main format specification buffer
 * @fail_flag: the address of a char to store the exit status of the function
 * Return: number of bytes read from the buffer
 */
int check_optional_fields(strQ *buffer, char *fail_flag)
{
	const char *spec;
	int i = 0, j;

	VALID_ALLOC(buffer && buffer->front);
	spec = buffer->front;
	while (chrpos("-+ 0#'", spec[i], 0) != -1)
		i++;
	if (spec[i] == '*')
		i++;
	else
		while (isdigit(spec[i]))
			i++;
	if (spec[i] == '.')
		if (spec[++i] == '*')
			i++;
		else
			while (isdigit(spec[i]))
				i++;
	if (spec[i] == 'h' || spec[i] == 'l')
	{
		if (spec[i++] == spec[i])
			i++;
	}
	else
	{
		if (chrpos("Lzjt", spec[i], 0) != -1)
			i++;
	}

	if (chrpos("diuxXopfFeEgGaAscbSrR", spec[i], 0) != -1)
		i++;
	else
		*fail_flag = 1;

	for (j = 0; j < i; j++)
		strQ_pop(buffer);
	return (i);
}
/**
 * get_fmt_spec - gets the format specifiers and stores them in the buffer
 * @buffer: main formatting specification buffer
 * @fmt_buffer: address of the buffer used to store the format parameters
 * Return: number of bytes read from the buffer
 */
int get_fmt_spec(strQ *buffer, strQ *fmt_buffer)
{
	int len;
	char *spec, fail_flag = 0;

	if (!buffer || !buffer->front || !fmt_buffer)
		return (-1);
	spec = buffer->front;
	len = check_optional_fields(buffer, &fail_flag);
	if (fail_flag)
		fmt_buffer->store = fmt_buffer->front = fmt_buffer->back = NULL;
	else
		fmt_buffer->store = fmt_buffer->front = spec,
		fmt_buffer->back = spec + len;
	return (len);
}
/**
 * print_formatted_token - prints the passed argument to printf formatted
 * @format: the main input formatting string
 * @buffer: the address of the main buffer used to store bytes to be read
 * @w_bytes: the address for storing the number of written bytes
 * @i: the index of the @format string to continue reading from
 * @va: the va_list struct from which passed arguments are retrieved
 * Return: number of bytes read from the buffer
 */
int print_formatted_token(const char *format, strQ *buffer,
		size_t *w_bytes, size_t i, va_list va)
{
	int read;
	strQ fmt_buffer;

	buffer->front = buffer->store = *((char **)(&format)) + i;
	buffer->back = strchr(format + i, '%');
	if (buffer->back == NULL)
		buffer->back = *((char **)(&format)) + i + _strlen(format + i);

	read = get_fmt_spec(buffer, &fmt_buffer);
	if (fmt_buffer.front)
		switch (*(fmt_buffer.back - 1))
		{
		case 'd': case 'i': case 'u': case 'x':
		case 'X': case 'o': case 'p': case 'b':
			*w_bytes += print_formatted_int(&fmt_buffer, va);
			break;
		case 'f': case 'F': case 'e': case 'E':
		case 'g': case 'G': case 'a': case 'A':
			*w_bytes += print_formatted_double(&fmt_buffer, va);
			break;
		case 's': case 'S': case 'r': case 'R':
			*w_bytes += print_formatted_string(&fmt_buffer, va);
			break;
		case 'c':
			*w_bytes += print_formatted_char(&fmt_buffer, va);
			break;
		}
	return (read);
}
/**
 * print_buffer - writes a char stream while using a buffer storage
 * @format: the main input formatting string
 * @tb: the  main token buffer
 * @r_bytes: the address where the number of read bytes is stored
 * @w_bytes: the address where the number of written bytes is stored
 */
void print_buffer(const char *format, strQ *tb, int *r_bytes, int *w_bytes)
{
	int j;
	char buffer[1024];
	strQ token_buffer = *tb;

	do {
		j = 0;
		do
			buffer[j++] = strQ_pop(&token_buffer);
		while (j < 1024 && (buffer[j - 1] != '\0'));
		j = (j == 1024) ?
			(1024 - (!format[*r_bytes + j - 1] && !buffer[j - 1])) :
			j - 1;
		*r_bytes += j;
		*w_bytes += write(1, buffer, j);
	} while (buffer[j - 1] != '\0');
}

/**
 * _printf - prints arguments as formatted output
 * @format: the format specification for arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	size_t i, j, tbw, read_bytes, written_bytes, interpretted_bytes = 0, *n;
	char fail_flag = 0, *str, write_buffer[1024];
	strQ token_buffer;
	va_list va;

	if (format != NULL)
	{
		va_start(va, format);
		i = 0, read_bytes = written_bytes = 0;
		while (format[i] != '\0')
		{
			interpretted_bytes = 0;
			token_buffer.store = token_buffer.front = *((char **)(&format)) + i;
			while (format[i] != '\0' && format[i] != '%')
				i++;
			token_buffer.back = *((char **)(&format)) + i;

			print_buffer(format, &token_buffer, &read_bytes, &written_bytes);
			if (format[i] == '%')
			{
				if (format[++i] == 'n')
					n = va_arg(va, size_t *), *n = written_bytes,
					read_bytes += 2, i++;
				else if (format[i] == '%')
					write(1, "%", 1), written_bytes++, read_bytes++, i++;
				else
					interpretted_bytes = print_formatted_token(
						format, &token_buffer, &written_bytes, i, va
					);
			}
			if (interpretted_bytes)
				i += interpretted_bytes, read_bytes += interpretted_bytes;
			else
				fail_flag = 1;
		}
		va_end(va);
		return (written_bytes);
	}
	return (-1);
}
