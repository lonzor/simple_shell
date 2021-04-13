#ifndef HEADER_H
#define HEADER_H

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
char **tokenizer(char *str, char *delim);
char *_getenv(char *name);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, int n);
int _strcmp(char *s1, char *s2);
int printenv(void);

#endif
