#include "header.h"
/**
 * _strlen - function name
 * @s: determines length
 * Return: final return value
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: the difference of the two strings
 **/
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strncmp - function name, currently unused, compares stings up to n bytes
 * @s1: first string to compare
 * @s2: string to compare s1 to
 * @n: number of bytes to compare up to
 * Return: returns difference of the strings
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
