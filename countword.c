#include "header.h"
/**
 */
size_t countword(char *str, char delim)
{
	size_t i = 0, count = 0;

	while (str[i])
	{
		if (str[i] == delim || str[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}
