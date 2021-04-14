#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
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
int _strcmp(char *s1, char *s2);
int printenv(void);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strcat3(char *dest, char *middle, char *src);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *checkpath(char *str);
int fullpath(char **path, char **input);
void freetokens(char **toks);
char *pathhandle(char **input);
size_t countword(char *str, char delim);
int _strncmp(const char *s1, const char *s2, int n);
void executecmd(char **cmnds, char *path, char *input);
void handler(int num);

#endif
