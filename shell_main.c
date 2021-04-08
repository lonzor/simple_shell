#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *input = NULL;
	/* char **cmnds; */
	pid_t child_pid;
	size_t bufsize = 0;
	int i_mode = isatty(STDIN_FILENO);
	int l;
	int status;
	

	while(i_mode)
	{
		if (i_mode == 1)
			write(STDOUT_FILENO, "shellie$ ", 9);
		l = getline(&input, &bufsize, stdin);
		printf("%s\n", input);
		if (l == EOF)
			break;

		/* this is where we call our tokenizer function */
		/* cmnds = tokenizer(input); */
		/* printf("%s\n", cmnds[0]); */
		/* cmnds will be used to search for the search 
		for the shell command to execute in execve */
		/* how are we going to search for that? */

		/* research stat() */
		
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
			/* execve(cmnds[0], cmnds, NULL); */
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
