## Lonzo and Garrison's Journey to sHell
## Description

**$shellie** is a simple shell we created for our final project of the first trimester at Holberton School. Input is taken from user input via the keyboard. Our created shell takes the same commands and functions as the "real" shell.

## Requirements

* Must follow Betty style guidelines
* Allowed code editors are: vi, vim, and emacs
* Must  have `README.md`file, a man page, and AUTHORS file.
* All header files must be guarded
* There must be no memory leaks

## Files and Functions
 
* strings.c - helper functions that pertain to strings
  * _strlen - gets the length of a string
  * _strcmp - compares two strings
  * _strcat - concatenates two strings
  * _strcpy - copies a string
* strings2.c - more helper functions that pertain to strings and _realloc
  * _strcat3 - concatenates three strings
  * _realloc - reallocs memory
  * _strncmp - compares strings up to n bytes
* countword.c - counts number of words in a string, per delim
* execution.c - forks to create child and parent process, and execve() using the function executecmd().
* envhelpers.c - helper functions pertaining to environment
  * printenv - prints environment
  * _getenv - gets environment
* freetokens.c - frees a double pointer array
*  parser.c - handles tokenization
	* tokenizer - tokenizes input from user, and also tokenizes the path
	* _strdup - duplicates strings and mallocs space
* header.h - contains all prototypes, libraries, and global variables
* path.c - helper functions pertaining to finding and manipulating PATH
  * pathhandler - Gets PATH and tokenizes it with a colon. Runs input checking functions to verify if user entered full path and searches all directories using stat().
  * checkpath - A helper for fullpath(). Checks if there are slashes in path given by user to determine if a path was given, and copies it to a tmp string
  * fullpath - checks what was returned from checkpath() and compares it to what we got for our path variable.
 * shell_main.c - Main function where while loop is implemented. The tokenizer is called here for both the commands and the PATH.  This is also where where the executecmd() function is called to perform a command. 

## Compilation

```c
gcc -Wall -Wextra -Werror -pedantic *.c`-o ./hsh
```
## Sample Output
### Interactive Mode

```c
~/user$ ./hsh
shellie$ echo hello
hello
shellie$ pwd
/home/vagrant/simple_shell

```

### Non-Interactive Mode

```c
~/user$ echo "pwd" | ./a.out
/home/vagrant/simple_shell
```

## Bugs

At this time of completing this README, we are not able to take multiple spaces as input from a user.


## Authors

Lonzo Rust | [GitHub](https://github.com/lonzor)
Garrison Shoemake | [GitHub](https://github.com/Garrison-Shoemake)
