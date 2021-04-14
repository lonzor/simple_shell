#include "header.h"
/**
 * pathhandle - function for handling PATH
 * @input: user's input, modified to pass back to execeve in main
 * Return: will return full path of user's input, if found
 *
 * Description: This function gets PATH and tokenizes it
 * with a colon. Runs input checking functions to verify
 * if user entered full paht and searches all directories
 * using stat().
 */
char *pathhandle(char **input)
{
	char *tmp = NULL;
	char **path = NULL;
	size_t i = 0, len = 0, len2 = _strlen(input[0]), indicator = 0;
	struct stat statad;

	tmp = _getenv("PATH");
	path = tokenizer(tmp, ":");/*pass path var to tokenizer*/
	if (path == NULL)
		return (input[0]);
	free(tmp);
	if (fullpath(path, input) == 1)/*if 1 then full path from user*/
		return (input[0]);
	for (i = 0; path[i]; i++)
	{
		len = _strlen(path[i]);/*realloc needed for cat3 space*/
		path[i] = _realloc(path[i], len + 1, len + len2 + 2);
		if (path[i] == NULL)
		{freetokens(path);
			return (NULL); }
		_strcat3(path[i], "/", input[0]);/*cats path w/input*/
	}
	for (i = 0; path[i]; i++)
	{
		if (stat(path[i], &statad) == 0)/*looks for path w/input*/
		{indicator = 1;/*this is if finds match*/
			break; }
	}
	if (indicator == 1)/*found match*/
	{
		if (access(path[i], X_OK) == 0)/*executable access yes*/
		{
			len = _strlen(path[i]);
			input[0] = _realloc(input[0], len2 + 1, len + 1);
			_strcpy(input[0], path[i]), freetokens(path);
			return (input[0]);
		}
	}
	freetokens(path);
	return (input[0]);/*find no match, probably not a cmnd*/
}
/**
 * fullpath - checks for full path, if not given by user input
 * @path: tokenized path from pathhandle
 * @input: input from main to check for path
 * Return: returns 1 if the comparison is true, 0 if not
 *
 * Description: Checks what was returned from checkpath() and compares
 * it to what we got for our path variable.
 */
int fullpath(char **path, char **input)
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
/**
 * checkpath - helper func for tmp variable in fullpath
 * @str: string to check and malloc space for
 * Return: returns the string back to fullpath for use
 *
 * Description: A helper function for fullpath(). Counts slashes in
 * string in order to know how many bytes are needed for malloc.
 */
char *checkpath(char *str)
{
	int i = 0, count1 = 0, count2 = 0, chars_sum = 0;
	char *tmp = NULL;

	while (str[i])/*counts total slashes in str*/
	{
		if (str[i] == '/')
			count1++;
		i++;
	}
	if (count1 == 0)
		return (NULL); /*no slash means no path*/
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')/*count slashes again*/
			count2++;
		if (count1 == count2)
			break;
		chars_sum++; /*countall chars include /'s for bytes to mal*/
	}
	tmp = malloc(sizeof(char) * chars_sum + 1);
	if (tmp == NULL)
		return (NULL);
	_strncpy(tmp, str, chars_sum);/*gets copy of tmp w/correct size*/
	return (tmp);
}
