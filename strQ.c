#include "main.h"

/**
 * strQ_init - initialises a strQ struct
 * @str: the string to be stored
 * Return: address of the created strQ struct
 */
strQ *strQ_init(const char *str)
{
	char *str_in;
	strQ *s = malloc(sizeof(strQ));

	VALID_ALLOC(s);
	if (str == NULL)
	{
		s->store = s->front = s->back = NULL;
		return (s);
	}
	str_in = malloc(_strlen(str) + 1);
	VALID_ALLOC(str_in);
	strcpy(str_in, str);
	s->front = s->store = str_in;
	s->back = str_in + _strlen(str);
	return (s);
}

/**
 * strQ_pop - pop the next element from a strQ
 * @s: the address of the strQ struct
 * Return: extracted char if any are left, or '\0' if it is empty
 */
char strQ_pop(strQ *s)
{
	char c;

	VALID_ALLOC(s && s->store);
	if (s->front < s->back)
		c = *(s->front++);
	else
		c = '\0';
	return (c);
}

/**
 * strQ_free - frees the memory stored by a strQ struct
 * @s: the address of the strQ struct
 */
void strQ_free(strQ *s)
{
	if (s && s->store)
		free(s->store), free(s);
}

