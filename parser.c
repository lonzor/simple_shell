#include "header.h"
/**
 * tokenizer - tokenizes a string given by the delimiters given
 * @str: string given to tokenize
 * @delim: delimiters given to tokenize string with
 * Return: returns input as tokens for use
 */
char **tokenizer(char *str, char *delim)
{
	char *token;
	int count = 0;
	char **toks;

	token = strtok(str, delim);
	toks = malloc(sizeof(char *) * 1024);
	if (toks == NULL)
		return (NULL);

	while (token != NULL)
	{
		toks[count] = _strdup(token);
		token = strtok(NULL, delim);
		count++;
	}
	toks[count] = token;
	return (toks);
}

/**
 * _strdup - copies a string and returns a pointer
 * @str: string that will be copied
 * Return: NULL or a pointer
 **/
char *_strdup(char *str)
{
	int i = 1;
	int k = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	dup = malloc((sizeof(char) * i) + 1);
	if (dup == NULL)
		return (NULL);
	while (k < i)
	{
		dup[k] = str[k];
		k++;
	}

	dup[k] = '\0';
	return (dup);
}
