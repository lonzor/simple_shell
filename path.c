#include "header.h"
/**
 * pathhandle - function for handling PATH, currently unused
 * @input: user's input, modified to pass back to execeve in main
 * Return: will return full path of user's input, if found
 */
char *pathhandle(char **input)
{
	char *tmp = NULL;
	char **path = NULL;
	size_t i = 0, len = 0, len2 = _strlen(input[0]), indicator = 0;
	struct stat statad;

	/* want to stat here, will return "/bin/ls ..." to main func to execve*/

	tmp = _getenv("PATH");
	/* store tokens in path*/
	path = tokenizer(tmp, ":", 1);
	if (path == NULL)
		return (input[0]);

	free(tmp);
	tmp = NULL;
	/*check if user specified full path */
	/* if match found, return input[0]*/
	if (fullpath(path, input) == 1)
	{
		return (input[0]);
	}
	/* if not, append input[0] to each path */
	for (i = 0; path[i]; i++)
	{

		len = _strlen(path[i]);
		path[i] = _realloc(path[i], len + 1, len + len2 + 2);
		_strcat3(path[i], "/", input[0]);
	}
	/* loop through path , use stat to check if command exists */
	for (i = 0; path[i]; i++)
	{
		if (stat(path[i], &statad) == 0)
		{
			indicator = 1;
			break;
		}
	}
	/* if valid command found, return path to command */
	if (indicator == 1)
	{
		len = _strlen(path[i]);
		input[0] = _realloc(input[0], len2 + 1, len + 1);
		_strcpy(input[0], path[i]);
		freetokens(path);
		return (input[0]);
	}
	/* return user input otherwise */
	freetokens(path);
	return (input[0]);
}

int fullpath(char **path, char**input)
{
	int i = 0;
	char *tmp = checkpath(input[0]);

	while (path[i])
	{
		if (_strcmp(path[i], tmp) == 0)
		{
			free(tmp);
			freetokens(path);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

char *checkpath(char *str)
{
	int i = 0, count1 = 0, count2 = 0, count3 = 0;
	char *tmp = NULL;

	while (str[i])
	{
		if (str[i] == '/')
			count1++;
		i++;
	}
	if (count1 == 0)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			count2++;
		if (count1 == count2)
			break;

		count3++;
	}
	tmp = malloc(sizeof(char) * count3 + 1);
	_strncpy(tmp, str, count3);
	return (tmp);
}
