#include "main.h"
/**
 * interpret_spec - Interpret format specifier string, creates formatted string
 * Return: A pointer to the formatted string.
 */

/* strlen("18446744073709551615") = 20 */
#define MAX_INT_LEN 20

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

char *int_to_str(int num, size_t radix, UV strQ *custom)
{
	int i;
	uint64_t n, base = 1;
	char *str;

	if (num == INT32_MIN)
	{
		str = malloc(11);
		return (strcpy(str, "-2147483648"));
	}
	if (radix == 0)
	{
		str = malloc(4);
		return (strcpy(str, "NaN"));
	}
	str = malloc(64 + 1 + 1);
	VALID_ALLOC(str);

	str[64 + 1] = '\0';
	for (i = 64; i > 0; i--)
	{
		n = (num / base) % radix;
		str[i] = (n < 10) ? ('0' + n) : ('A' + n - 10);
		base *= radix;
	}
	strip(str + 1);
	return (str);
}
