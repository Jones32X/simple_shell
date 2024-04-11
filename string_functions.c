#include "simple.h"

/**
 * _strlen - find the length of a string
 * @s: entry string
 * Return: number of bytes
 **/

int _strlen(char *s)
{
	int L;

	L = 0;

	for (; s[L]; L++)
	{
	}
	return (L);
}

/**
 * _strcat - concatenate directories with first position of the array
 * @directory: directories
 * @slash: /
 * @arg: array of commands.
 * Return: string
 **/

char *_strcat(char *directory, char *slash, char *arg)
{
	char *str = NULL;
	int l1;
	int l2;
	int i;
	int k;

	l1 = _strlen(directory);
	l2 = _strlen(arg);
	str = malloc(sizeof(char) * (l1 + l2 + 2));
	if (!str)
		return (NULL);
	for (i = 0; directory[i]; i++)
		str[i] = directory[i];
	str[i] = *slash;
	k = i + 1;
	for (i = 0; arg[i]; i++)
		str[k + i] = arg[i];
	str[k + i] = '\0';
	return (str);
}

/**
 * _strtok - breaks a str into sequence
 * @str: string
 * @delim: specific char to break the string
 * Return: NULL if fails otherwise
 * point to divided string.
 */

char *_strtok(char *str, char *delim)
{
	int i;
	int j;
	int a;
	static char *tracker;

	j = 0;
	a = 0;
	i = 0;

	if (!delim || (!str && !tracker))
		return (NULL);
	str == NULL ? str = tracker : str;
	for (; str[j] == ' ' ; j++)
	{
		if (str[j + 1] == '\0')
			return (NULL);
	}
	for (i = j ; str[i] != '\0' ; i++)
	{
		if (str[i] == *delim)
		{
			a = 1;
			break;
		}
	}
	for (; str[i] != '\0' ; i++)
		if (str[i] != delim[0])
			break;
		else if (str[i + 1] == '\0')
		{
			a = 0, str[i] = '\0';
			break;
		}
		else
			str[i] = '\0';
	if (a == 0)
	{
		tracker = NULL;
		return (str + j);
	}
	if (str + i)
		tracker = str + i;
	else
		tracker = NULL;
	return (str + j);
}
/**
 * *_strcpy - copies the string pointed to another pointer
 * @src: original pointer
 * @dest: pointer destination
 * Return: return a pointer char

*/
char *_strcpy(char *dest, char *src)
{
	int v = 0;
	int W;

	W = 0;

	for (v = 0; src[v] != '\0' ; v++)
	{
	}
	for (W = 0; b < v ; W++)
	{
		dest[W] = src[W];
	}
	for (; W <= v ; W++)
	{
		dest[W] = '\0';
	}
	return (dest);
}
