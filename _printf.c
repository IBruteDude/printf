#include "main.h"

#define BUFFER_SIZE 1024

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
	{
		if (spec[++i] == '*')
			i++;
		else
			while (isdigit(spec[i]))
				i++;
	}
	if (spec[i] == 'h' || spec[i] == 'l')
	{
		i++;
		if (spec[i - 1] == spec[i])
			i++;
	}
	else
	{
		if (chrpos("Lzjt", spec[i], 0) != -1)
			i++;
	}

	if (chrpos("diuxXopfFeEgGaAscbSrR", spec[i], 0) != -1)
		i++, *fail_flag = 0;
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
	char fail_flag, *spec;

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
 * process_conversion_spec - process printf's format conversion specification
 * @format: the main input formatting string
 * @buffer: the address of the main buffer used to store bytes to be read
 * @w_bytes: the address for storing the number of written bytes
 * @i: the index of the @format string to continue reading from
 * @va: the va_list struct from which passed arguments are retrieved
 * Return: number of bytes read from the buffer
 */
int process_conversion_spec(const char *format, va_list *va, strQ *buffer,
		size_t *w_bytes, size_t i)
{
	int read;
	strQ fmt_buffer;

	buffer->front = buffer->store = *((char **)(&format)) + i;
	buffer->back = strchr(format + i, '%');
	if (buffer->back == NULL)
		buffer->back = *((char **)(&format)) + i + strlen(format + i);

	read = get_fmt_spec(buffer, &fmt_buffer);
	if (read > 0)
		switch (*(fmt_buffer.back - 1))
		{
		case 'd': case 'i': case 'u': case 'x':
		case 'X': case 'o': case 'b':
			*w_bytes += print_formatted_int(&fmt_buffer, va);
			break;
		case 'f': case 'F': case 'e': case 'E':
		case 'g': case 'G': case 'a': case 'A':
			*w_bytes += print_formatted_double(&fmt_buffer, va);
			break;
		case 's': case 'S': case 'r': case 'R':
			*w_bytes += print_formatted_string(&fmt_buffer, va);
			break;
		case 'c': case 'p':
			*w_bytes += print_formatted_char(&fmt_buffer, va);
			break;
		}
	return (read);
}

/**
 * print_buffer - writes a char stream utilizing a buffer storage
 * @format: the main input formatting string
 * @tb: the  main token buffer
 * @r_bytes: the address where the number of read bytes is stored
 * @w_bytes: the address where the number of written bytes is stored
 */
void print_buffer(const char *format, strQ *tb,
					size_t *r_bytes, size_t *w_bytes)
{
	int i, j;
	char buffer[BUFFER_SIZE];
	strQ token_buffer;

	if (!(format && tb && w_bytes && r_bytes))
		exit(EXIT_FAILURE);
	/**
	 * TODO: needs rework to remove unnecessary token buffer usage
	 */
	token_buffer = *tb;
	i = *r_bytes;
	token_buffer.store = token_buffer.front = *((char **)(&format)) + *r_bytes;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	token_buffer.back = *((char **)(&format)) + i;

	do {
		j = 0;
		do
			buffer[j++] = strQ_pop(&token_buffer);
		while (j < BUFFER_SIZE && (buffer[j - 1] != '\0'));
		j = (j == BUFFER_SIZE) ?
			(BUFFER_SIZE - (!format[*r_bytes + j - 1] && !buffer[j - 1])) :
			j - 1;
		*r_bytes += j;
		*w_bytes += write(1, buffer, j);
	} while (buffer[j] != '\0');
	*tb = token_buffer;
}

/**
 * _printf - prints arguments as formatted output
 * @format: the format specification for arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	size_t read_bytes, written_bytes;
	int *n;
	char fail_flag;
	strQ token_buffer;
	va_list va;

	if (format != NULL)
	{
		va_start(va, format);
		read_bytes = written_bytes = 0;
		while (format[read_bytes] != '\0')
		{
			print_buffer(format, &token_buffer, &read_bytes, &written_bytes);
			if (format[read_bytes] == '%')
			{
				fail_flag = 0;
				read_bytes++;
				if (format[read_bytes] == 'n')
					n = va_arg(va, int *), *n = written_bytes, read_bytes++;
				else if (format[read_bytes] == '%')
					write(1, "%", 1), written_bytes++, read_bytes++;
				else
					read_bytes += process_conversion_spec(
						format, &va, &token_buffer,
						&written_bytes, read_bytes
					);
				if (token_buffer.front == NULL)
					fail_flag = 1;
			}
		}
		va_end(va);
		if (!fail_flag)
			return (written_bytes);
	}
	return (-1);
}
