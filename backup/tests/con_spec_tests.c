#include "../main.h"
#include <stdio.h>

int main()
{
	char c = 'a';
	printf("Testing chrpos:\n");
	printf("1-\t4\t%d\n", chrpos("12345", '5', 0));
	printf("2-\t\t%d\n", chrpos("12345", '5', 7));
	printf("3-\t\t%d\n", chrpos("12345", '6', 0));
	printf("4-\t\t%d\n", chrpos("", '6', 0));
	printf("5-\t\t%d\n", chrpos(NULL, '6', 0));

	printf("\nTesting get_valid_specifier:\n");

	strQ sQ;
	get_fmt_spec(strQ_init("+0-3.3llu"), &sQ);
	printf("%s\t,\t", sQ.front);
	putchar(c);
	printf("%-03.3llu, %Ld", 5, 400);
	_printf("12356");
}