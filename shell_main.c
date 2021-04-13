#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *input = NULL, **cmnds;
	pid_t child_pid;
	size_t bufsize = 0;
	int i_mode = isatty(STDIN_FILENO), status;

	while(i_mode)
	{
		if (i_mode == 1)
			write(STDOUT_FILENO, "shellie$ ", 9);
		if(getline(&input, &bufsize, stdin) == EOF)
			break;

		/* this is where we call our tokenizer function */
		cmnds = tokenizer(input, " \n");

		/* "bin/ls -l" */
/*		if (cmnds[0][0] != '/')
		cmnds[0] = pathhandle(cmnds[0]); */

		/* cmnds will be used to search for the search
		for the shell command to execute in execve */
		/* how are we going to search for that? */

		/* research stat() */
		/* we might be able to put stat() in a seperat function */
		child_pid = fork();
                if (child_pid == -1)
                {
                        perror("Error:");
                        return (1);
                }
                if (child_pid == 0)
                {
                        /* cmnds  has to be _strcmp to a command in /bin */
                        /* do the execve thing on what was matched */
                        execve(cmnds[0], cmnds, NULL);
                        /* printf("%s\n", cmnds[0]); */
                        printf("got to child\n");
                }
                else
                {
                        printf("waiting\n");
                        wait(&status);
		}
	}
	return (0);
}
