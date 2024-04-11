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
	int K = 0, B = 0, TV = 0;
	static char *tracker;

	if (!delim || (!str && !tracker))
		return (NULL);
	str == NULL ? str = tracker : str;
	for (; str[B] == ' ' ; B++)
	{
		if (str[B + 1] == '\0')
			return (NULL);
	}
	for (K = B ; str[K] != '\0' ; K++)
	{
		if (str[K] == *delim)
		{
			TV = 1;
			break;
		}
	}
	for (; str[K] != '\0' ; K++)
		if (str[K] != delim[0])
			break;
		else if (str[K + 1] == '\0')
		{
			TV = 0, str[K] = '\0';
			break;
		}
		else
			str[K] = '\0';
	if (TV == 0)
	{
		tracker = NULL;
		return (str + B);
	}
	if (str + K)
		tracker = str + K;
	else
		tracker = NULL;
	return (str + B);
}

/**
 * *_strcpy - copies the string pointed to another pointer
 * @src: original pointer
 * @dest: pointer destination
 * Return: return a pointer char
*/

char *_strcpy(char *dest, char *src)
{
	int Aa = 0;
	int Boa = 0;

	for (Aa = 0; src[Aa] != '\0' ; Aa++)
	{
	}
	for (Boa = 0; Boa < Aa ; Boa++)
	{
		dest[Boa] = src[Boa];
	}
	for (; Boa <= Aa ; Boa++)
	{
		dest[Boa] = '\0';
	}
	return (dest);
}
