#include "header.h"
/**
 * tokenizer - tokenizes a string given by the delimiters given
 * @str: string given to tokenize
 * @delim: delimiters given to tokenize string with
 * Return: returns input as tokens for use
 */
char **tokenizer(char *str, char *delim)
{
	char *token = NULL;
	int i = 0, len = 0;
	char **toks = NULL;
	size_t count = 0;

	len = _strlen(str);
	/*changes \n from getline() to nullbyte cuz str need that*/
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	count = countword(str, delim[0]);/*determines rows needed in array*/
	toks = malloc(sizeof(char *) * (count + 1));
	if (toks == NULL)
		return (NULL);
	token = strtok(str, delim);

	while (token != NULL)
	{
		toks[i] = _strdup(token);/*populating 2D array of new toks*/
		if (toks[i] == NULL)
		{
			freetokens(toks);
			return (NULL);
		}
		token = strtok(NULL, delim);/*goes one word at a time*/
		i++;
	}
	toks[i] = token;
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
