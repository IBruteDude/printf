#include "main.h"


/**
 * strip - strips a string from leading zeros
 * @str: input string
 */
void strip(char *str)
{
	if (str)
		while (str[0] == '0' && _strlen(str) > 1)
			strcpy(str, str + 1);
}

/**
 * _strlen - find the length of a string
 * @str: input string
 * Return: length of the string
 */
size_t _strlen(const char *str)
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

	if (start >= 0 && str != NULL && start <= sizeof(str) - 1)
		for (i = start; str[i] != '\0'; i++)
		{
			if (str[i] == c)
				return (idx);
			idx++;
		}
	return (-1);
}

