#include "../main.h"
#include <stdio.h>

/**
 * main - applies several tests to _printf function
 * Return: exit status
 */
int main(void)
{

	uint64_t ui64;

	int i = INT32_MIN;

	ui64 = i;

	printf("My printf:\t%d\noriginal printf:\t%d\n",
		_printf("%lx\n", &ui64),
		printf("%lx\n", &ui64));
	
	printf("My printf:\t%d\noriginal printf:\t%d\n",
		_printf("12s45%d78%s0\n", '4', "EVER!"),
		printf("12s45%d78%s0\n", '4', "EVER!"));
	_printf("%s\n",
	int_to_str(INT32_MIN, 8, strQ_init("")));
	printf("%o\n", ui64);
	_printf("%X\n", 2222);
	
	printf("%f\n", nanf(""));
	getchar();
	/**
	printf("%lo\n%s\n", UINT32_MAX, strdup(1 + int_to_str(UINT32_MAX, 8, strQ_init(""))));
	printf("%ld\n%s\n", INT32_MIN, strdup(1 + int_to_str(INT32_MIN, 10, strQ_init(""))));
	printf("%lX\n%s\n", INT32_MIN, strdup(1 + int_to_str(INT32_MIN, 16, strQ_init(""))));
	printf("%lX\n%s\n", INT32_MIN, strdup(1 + int_to_str(INT32_MIN, 16, strQ_init(""))));
	printf("%lu\n%s\n", UINT32_MAX, strdup(1 + int_to_str(UINT32_MAX, 10, strQ_init(""))));
	printf("%lX\n%s\n", UINT32_MAX, strdup(1 + int_to_str(UINT32_MAX, 16, strQ_init(""))));

	printf("%llo\n%s\n", INT64_MIN, strdup(1 + int_to_str(INT64_MIN, 8, strQ_init(""))));
	printf("%lld\n%s\n", INT64_MIN, strdup(1 + int_to_str(INT64_MIN, 10, strQ_init(""))));
	printf("%llX\n%s\n", INT64_MIN, strdup(1 + int_to_str(INT64_MIN, 16, strQ_init(""))));
	printf("%llX\n%s\n", INT64_MIN, strdup(1 + int_to_str(INT64_MIN, 16, strQ_init(""))));
	printf("%llu\n%s\n", UINT64_MAX, strdup(1 + int_to_str(UINT64_MAX, 10, strQ_init(""))));
	printf("%llX\n%s\n\n\n\n", UINT64_MAX, strdup(1 + int_to_str(UINT64_MAX, 16, strQ_init(""))));
	*/
	/**
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %X\nSalam\n", 22),
		printf("Alsalam Alaicom, %X\nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %o\nSalam\n", 22),
		printf("Alsalam Alaicom, %o\nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Hi, %c\nBye\n", 'A'),
		printf("Hi, %c\nBye\n", 'A'));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Hi, %s\nBye\n", sx1),
		printf("Hi, %s\nBye\n", sx1));

	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", 22),
		printf("Alsalam Alaicom, %i\nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", -22),
		printf("Alsalam Alaicom, %i\nSalam\n", -22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %i\nSalam\n", INT32_MIN),
		printf("Alsalam Alaicom, %i\nSalam\n", INT32_MIN));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %b\nSalam\n", 22),
		printf("Alsalam Alaicom, \nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %X\nSalam\n", 22),
		printf("Alsalam Alaicom, %X\nSalam\n", 22));
	printf("my printf:\t%d\noriginal printf:\t%d\n",
		_printf("Alsalam Alaicom, %o\nSalam\n", 22),
		printf("Alsalam Alaicom, %o\nSalam\n", 22));
	*/
	return (0);
}
