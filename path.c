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

	if (stat(path[i]) == 0)

/*        while (path != NULL)
        {
                ptok[i] = _strdup(path);
                path = strtok(NULL, delim);
                count++;
        }
*/

	if (input == ar_p)
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

	return (path);
}
