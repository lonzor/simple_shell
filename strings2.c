#include "header.h"
/**
 * _strcat3 - concats three three strings together
 * @dest: destination to concat strings to
 * @middle: string to concat between dest and src
 * @src: source to concat with after dest is concat with middle
 * Return: returns new concatenated string
 */
char *_strcat3(char *dest, char *middle, char *src)
{
	if (dest && middle && src)
	{
		_strcat(dest, middle);/*cats middle to end of dest*/
		_strcat(dest, src);/*cats src to end of prev cat str*/
	}
	else
		return (NULL);
	return (dest);
}
/**
 * _realloc - reallocates memory from old size to new size
 * @ptr: pointer array to what needs memory reallocated
 * @old_size: the current size in bytes
 * @new_size: the space/size needed
 * Return: returns tmp as newly realocated  string to use
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp = NULL;

	if (new_size == old_size)/*no new sizing is needed*/
		return (ptr);

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

	_strcpy(tmp, ptr);
	free(ptr);
	return (tmp);
}
/**
 * _strncmp - compares strings up to n bytes
 * @s1: first string to check
 * @s2: second string to check
 * @n: number of bytes to check up to
 * Return: returns 0 if not found
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
