#include "header.h"

char **pathhandle(char *input)
{
	char *path = NULL;
	char **ptok;
	int i = 0;

	/* want to stat here, will return "/bin/ls ..." to main func to tokenize */
	/* start with tokenizing PATH by delim ':' */

	path = _getenv("PATH");
	ptok = tokenizer(path, ":");
	/* store tokens in ptok*/

	while (ptok[i])
	{
		i++;
	}

/* stat should check each of PATH's token for ls? */
	/* might could use linked lists, and each token can check struct, point to function */
		return(ptok);
}

char *_getenv(char *name)
{
	int i = 0;
	size_t l = _strlen(name);
	char *path;



	while (environ[i] && (_strncmp(name, environ[i], l) || environ[i][l] != '='))
	{
		i++;
	}
	path = _strdup(environ[i]);

	return (path + length + 1);
}
/**
 * _strncmp - compares two strins to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to check
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
}
