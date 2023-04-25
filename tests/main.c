#include "../main.h"
#include <stdio.h>

/**
 * main - applies several tests to _printf function
 * Return: exit status
 */
int main(void)
{
	char sx1[] = "Testing";

	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Hi, %c\nBye\n", 'A'),
		printf("Hi, %c\nBye\n", 'A'));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Hi, %s\nBye\n", sx1),
		printf("Hi, %s\nBye\n", sx1));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Hi, %s\nBye\n", NULL),
		printf("Hi, %s\nBye\n", NULL));

	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", 22),
		printf("Alsalam Alaicom, %i\nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", -22),
		printf("Alsalam Alaicom, %i\nSalam\n", -22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", INT32_MIN),
		printf("Alsalam Alaicom, %i\nSalam\n", INT32_MIN));
}
