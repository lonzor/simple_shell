#include "header.h"
/**
 *
 *
 *
 *
 */
int printenv(void)
{
	unsigned int i;
	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i],_strlen(environ[i]));
		i++;
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
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

	return (path + l + 1);
}
