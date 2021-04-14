#include "header.h"
/**
 * freetokens - frees a double pointer array
 * @toks: double pointer to free
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
