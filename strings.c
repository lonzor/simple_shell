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
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _strncpy - string copy function
 * @dest: destination to copy to
 * @src: source to copy from
 * @n: number to copy up to
 * Return: returns destination for use
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - string concatenate function
 * @dest: destination to concat to
 * @src: source to concat from
 * Return: returns new concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *str_ret = dest;

	if ((dest != '\0') && (src != '\0'))
	{
		while (*dest != '\0')
		{
			dest++;
		}
		while (*src != '\0')
		{
			*dest++ = *src++;
		}
		*dest = '\0';
	}
	return (str_ret);
}
/**
 * _strcpy - string copy function
 * @dest: destination to copy to
 * @src: source to copy from
 * Return: returns destination for use
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int k = _strlen(src);

	for (i = 0; i <= k; i++)
		dest[i] = src[i];
	return (dest);
}
