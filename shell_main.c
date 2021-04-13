#include "header.h"
/**
 * main - main function, takes input, find command and executes it
 * @ac: unused in main, count of arguments made
 * @av: unused in main, arguments made
 * Return: returns 0, or exits via input
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *input = NULL, **cmnds;
	pid_t child_pid;
	size_t bufsize = 0;
	int i_mode = isatty(STDIN_FILENO), status;

	while (i_mode)
	{
		if (i_mode == 1)
			write(STDOUT_FILENO, "shellie$ ", 9);
		if (getline(&input, &bufsize, stdin) == EOF)
			break;
		if (_strcmp(input, "env\n") == 0)
		{
			/*free here */
			printenv();
			continue;
		}
		if (_strcmp(input, "exit\n") == 0)
		{
			/* free here */
			break;
		}
		/* this is where we call our tokenizer function */
		cmnds = tokenizer(input, " \n");
/* cmnds will be used to search for the shell command to execute in execve */
/* how are we going to search for that? */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
			execve(cmnds[0], cmnds, NULL);
		else
			wait(&status);
	}
	return (0);
}
