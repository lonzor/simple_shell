#include "header.h"
/**
 * main - main function, takes input, find command and calls execve()
 * Return: returns 0, or exits via input
 * 
 * Description: EVN and EXIT implementation. Pass data through tokenizer
 * and runs function to execute commands
 */
int main(void)
{
	char *input = NULL, **cmnds, *path = NULL;
	size_t bufsize = 0;
	int i_mode = 1;

	signal(SIGINT, handler);
	while (i_mode)
	{
		if (isatty(0))
			write(STDOUT_FILENO, "shellie$ ", 9);
		if (getline(&input, &bufsize, stdin) == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (input == NULL)
			exit(0);
		if (_strcmp(input, "env\n\0") == 0)
		{
			free(input), input = NULL, printenv();
			continue;
		}
		if (_strcmp(input, "exit\n\0") == 0)
			break;
		cmnds = tokenizer(input, " ", 0); /*cmnds via tokenizer()*/
		path = pathhandle(cmnds); /*get path via tokenized cmnds*/
		if (cmnds == NULL) /*if NULL isn't found do all the free*/
		{
			free(input), free(cmnds);
			cmnds = NULL, input = NULL;
			continue;
		}
		executecmd(cmnds, path, input); /*exe cmnds found*/
		freetokens(cmnds);
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}
/*
 *
 *
 **/
void handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "shellie$ ", 9);	
}
