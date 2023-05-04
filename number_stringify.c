#include "main.h"
#include <stdio.h>

/**
 * strip - strips a string from leading zeros
 * @str: input string
 */
void strip(char *str)
{
	if (str)
		while (str[0] == '0' && strlen(str) > 1)
			strcpy(str, str + 1);
}

/**
 * interpret_spec - Interpret format specifier string, creates formatted string
 * @fmt_spec: the format specification string
 * @out_string: the output strQ holding the output formatted string
 * Return: A pointer to the formatted string.
 */
char *interpret_spec(UV char *fmt_spec, strQ *out_string)
{
	/* TO DO */
	UV char *c = out_string->front;

	if (c != NULL)
		return (c);
	return (0);
}

/**
 * double_to_str - Converts double-precision floating-point number to a string
 * @num: The double-precision floating-point number to convert
 * @custom: Pointer to a buffer to hold the resulting string
 * Return: A pointer to the resulting string.
 */
char *double_to_str(double UV num, UV strQ *custom)
{
	/* TO DO */
	strQ c = *custom;

	if (c.back != NULL)
		return (custom->back);
	return (0);
}

/**
 * int_to_str - Converts integer to string representation in specified radix
 * @num: The integer to convert
 * @radix: The radix to use for the conversion
 * @custom: Pointer to a buffer to hold the resulting string
 * Return: A pointer to the resulting string.
 */
char *int_to_str(uint64_t num, size_t radix, UV strQ *custom)
{
	int i, INT_LEN;
	uint64_t n, base = 1;
	char *str;

	if (num == (uint64_t) INT32_MIN)
		return (strdup("-2147483648"));
	if (radix > 32 || radix < 2)
		return (strdup("NaN"));

	INT_LEN = ceil((64 / log2(radix)));
	/* printf("%d\n", INT_LEN); */
	str = malloc(INT_LEN + 1 + 1);
	VALID_ALLOC(str);

	str[INT_LEN + 1] = '\0';
	for (i = INT_LEN; i > 0; i--)
	{
		n = (num / base) % radix;
		str[i] = (n < 10) ? ('0' + n) : ('A' + (n - 10));
		base *= radix;
	}
	strip(str + 1);
	str[0] = '-';
	return (str);
}

/**
 * str_tolower - changes all characters in a string to lower case
 * @str: input string
 * Return: resulting modified string 
 */
char *str_tolower(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	return (str);
}
