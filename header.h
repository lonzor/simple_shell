#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/* prototypes */
char *_strdup(char *str);
char **tokenizer(char *str);
