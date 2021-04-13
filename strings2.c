#include "header.h"
/**
 */
char *_strcat3(char *dest, char *middle, char *src)
{
	if (dest && middle && src)
	{
		_strcat(dest, middle);
		_strcat(dest, src);
	}
	else
		return (NULL);
	return(dest);
}

char *_realloc(char* ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp = NULL;
	size_t i = 0;

	if (new_size == old_size)
		return(ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
	}
	tmp = malloc(new_size);
	if (tmp == NULL)
		return (NULL);

	while (ptr[i])
	{
		tmp[i] = ptr[i];
		i++;
	}
	tmp[i] = '\0';
	free(ptr);
	return(tmp);
}
/**
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return(0);
}
