#include "monty.h"

/**
 * _strlen - returns the length of a string.
 * @c: the string to be operated on.
 *
 * Return: int
 */
int _strlen(char *c)
{
	int i = 0;

	while (c[i] != '\0')
		i++;
	return (i);
}



/**
 * _strcpy - copies a string pointed to by src,
 * including the \0 character, to the buffer
 * pointed to by dest.
 * @dest: the copied string
 * @src: the pointer to the string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0, i;

	for (; src[len] != '\0'; len++)
		;

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}


/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if equal, -ve integer if s1 < s2, otherwise +ve integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
