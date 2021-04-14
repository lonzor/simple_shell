#include "header.h"
/**
 * main - main function, takes input, find command and executes it
 * @ac: unused in main, count of arguments made
 * @av: unused in main, arguments made
 * Return: returns 0, or exits via input
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *input = NULL, **cmnds, *path = NULL;
	size_t bufsize = 0;

	while (1)
	{
		write(STDOUT_FILENO, "shellie$ ", 9);
		if (getline(&input, &bufsize, stdin) == EOF)
			break;
		if (input == NULL)
			exit(0);
		if (_strcmp(input, "env\n\0") == 0)
		{
			free(input);
			printenv();
			continue;
		}
		if (_strcmp(input, "exit\n\0") == 0)
		{
			break;
		}
		/* this is where we call our tokenizer function */
		cmnds = tokenizer(input, " ", 0);
/* cmnds will be used to search for the shell command to execute in execve */
/* how are we going to search for that? */
		path = pathhandle(cmnds);
		if (cmnds == NULL)
		{
			free(input);
			free(cmnds);
			cmnds = NULL;
			continue;
		}
		executecmd(cmnds, path, input);
		freetokens(cmnds);
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}
