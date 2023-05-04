#include "main.h"

/* strlen("18446744073709551615") = 20 */
#define MAX_INT_LEN 20

char *interpret_spec(char *fmt_spec, strQ *out_string)
{
	/* TO DO */
}
char *double_to_str(double num, strQ *custom)
{
	/* TO DO */
}
char *int_to_str(int num, size_t radix, strQ *custom)
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
	str = malloc(MAX_INT_LEN + 1 + 1);
	VALID_ALLOC(str);

	str[MAX_INT_LEN + 1] = '\0';
	for (i = MAX_INT_LEN; i > 0; i--)
	{
		n = (num / base) % radix;
		str[i] = (n < 10) ? ('0' + n) : ('A' + n - 10);
		base *= radix;
	}
	strip(str + 1);
	return (str);
}