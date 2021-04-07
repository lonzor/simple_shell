#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *input = NULL;
	char *cmnds = NULL;
	size_t bufsize = 1024;
	int i_mode = isatty(STDIN_FILENO);
	int l;
	

	while(i_mode)
	{
		if (i_mode == 1)
			write(STDOUT_FILENO, "shellie$ ", 13);

		l = getline(&input, &bufsize, stdin);
		if (l == EOF)
			break;

		/* this is where we call our tokenizer function */
		/* cmnds  = tokenizer(input); */
		/* cmnds will be used to search for the search 
		for the shell command to execute in execve */
		/* how are we going to search for that? */

		/* research stat() */

		/* this is where we fork */
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			/* cmnds  has to be _strcmp to a command in /bin */
			/* do the execve thing on what was matched */
		}
		else
		{
			/* do the wait thing */
		}
		
	}
	return (0);
}
