#include "header.h"
/**
 */
void freetokens(char **toks)
{
	int i = 0;

	if (toks == NULL)
	{
		return;
	}
	while (toks[i])
	{
		free(toks[i]);
		i++;
	}
	free(toks);
}
