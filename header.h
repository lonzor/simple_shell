#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/* global variables */
extern char **environ;

/* prototypes */
char *_strdup(char *str);
char **tokenizer(char *str);
char *_getenv(char *name);
char *_strstr(char *haystack, char *needle);
