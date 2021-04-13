#include "header.h"
/**
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
			exit(0);
		}
	}
	else
		wait(&status);
}
