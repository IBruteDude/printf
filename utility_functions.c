#include "main.h"

/**
 * strlen - find the length of a string
 * @str: input string
 * Return: length of the string
 */
size_t strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * strcpy - copys a string
 * @dest: destination address
 * @src: soure address
 * Return: copied destination address
 */
char *strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
		dest[i] = src[i], i++;
	dest[i] = '\0';
	return (dest);
}

/**
 * strdup - makes a duplicate of a string
 * @s: input string
 * Return: created duplicate string address
 */
char *strdup(const char *s)
{
	return (strcpy(malloc(strlen(s) + 1), s));
}

/**
 * strchr - find the address of a char inside a string
 * @str: input string
 * @c: specified char
 * Return: address of the found char, or NULL if not found
 */
char *strchr(const char *str, int c)
{
	size_t i = 0;

	while (str[i] != '\0')
		if (str[i++] == c)
			return ((char *)(str + i - 1));
	return (NULL);
}

/**
 * chrpos - find the relative position of a char inside a string
 * @str: input string
 * @c: specified char
 * @start: starting position for searching
 * Return: relative position of char if found, -1 if not found
 */
int chrpos(const char *str, char c, int start)
{
	int i, idx = 0;

	if (start >= 0 && str != NULL && start <= (int) sizeof(str) - 1)
		for (i = start; str[i] != '\0'; i++)
		{
			if (str[i] == c)
				return (idx);
			idx++;
		}
	return (-1);
}
