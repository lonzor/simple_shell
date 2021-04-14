#include "header.h"
/**
 * executecmd - function that forks and executes from main
 * @cmnds: commands from main
 * @path: path from main
 * @input: input from main
 */
void executecmd(char **cmnds, char *path, char *input)
{
	pid_t child_pid;
	char *tmp;
	int status;

	tmp = _strdup(path);
	free(cmnds[0]);
	cmnds[0] = tmp;
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("child_pid error");
	}
	if (child_pid == 0)
	{
		if (execve(cmnds[0], cmnds, environ) == -1)
		{
			perror("WRONG");
			free(input);
			freetokens(cmnds);
			exit(127);
		}
	}
	else
		wait(&status);
}
