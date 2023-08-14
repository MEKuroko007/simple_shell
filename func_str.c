#include "main.h"

/**
 * _strlen - function return the  lenght of a string
 * @s : char to be counted
 * Description: this will return the length of a string
 * Return: 0 is success
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}

	return (count);
}

/**
 * _strcpy - function that copy the string pointed to by src to dest
 * @dest: char
 * @src: char
 * Return: 0 success
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - Concat Two String
 * @dest:char
 * @src:char
 * Return:char pointer
 */
char *_strcat(char *dest, char *src)
{
	char *string = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (string);
}

/**
 * handle_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n",1);
	exit(EXIT_FAILURE);
}
