#include "header.h"
/**
 * countword - counts the number of words in a string, per delimiter
 * @str: string to count words
 * @delim: what to delimit words by, usually a space
 * Return: returns total number of words
 */
size_t countword(char *str, char delim)
{
	size_t i = 0, count = 0;

	while (str[i])
	{/*if no nullbyte, then won't count last word*/
		if (str[i] == delim || str[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}
